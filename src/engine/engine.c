
#include <assert.h>
#include "../mk.h"

static void mk_initialize_on_write_cb(uv_fs_t *req);

static void mk_initialize_extend(mk_initialize_context *context)
{
    uv_buf_t iov = uv_buf_init(context->buffer, MK_INITIALIZATION_BUFFER_SIZE);
	uv_fs_write(uv_default_loop(), context->write_req, context->open_req->result, &iov, 1, -1, mk_initialize_on_write_cb);
}

static void mk_initialize_on_write_cb(uv_fs_t *req)
{
	mk_initialize_context *context = (mk_initialize_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Error: writing to file: %s\n", uv_strerror((int)req->result));
		return;
	}

    uv_fs_req_cleanup(context->write_req);

    context->number++;
    if (context->number < 10) {
        mk_initialize_extend(context);
        return;
    }

    uv_fs_req_cleanup(context->open_req);
    free(context->open_req);
	free(context->write_req);
    free(context->buffer);

    if (context->cb != NULL) {
        mk_session *session = malloc(sizeof(mk_session));
        session->db = NULL;
        (context->cb)(session);
    }

    free(context);
}

static void mk_initialize_on_open(uv_fs_t *req)
{
    mk_initialize_context *context = (mk_initialize_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Error: could not open tablespace: %s\n", uv_strerror((int)req->result));
		return;
	}

    context->write_req  = malloc(sizeof(uv_fs_t));
	context->write_req->data = context;

    mk_initialize_extend((mk_initialize_context*) req->data);
}

static void mk_initialize_on_stat(uv_fs_t *req)
{
    mk_initialize_context *context = (mk_initialize_context*) req->data;

    uv_fs_req_cleanup(context->stat_req);
	free(context->stat_req);

	if (req->result >= 0) {

        if (context->cb != NULL) {
            mk_session *session = malloc(sizeof(mk_session));
            session->db = NULL;
            (context->cb)(session);
        }

		return;
	}

    fprintf(stderr, "Initializing '%s' tablespace\n", context->path);

    context->number = 0;
    context->buffer = malloc(sizeof(uint8_t) * MK_INITIALIZATION_BUFFER_SIZE);

	context->open_req = malloc(sizeof(uv_fs_t));
	context->open_req->data = context;

	uv_fs_open(uv_default_loop(), context->open_req, context->path, O_RDWR | O_CREAT, 0644, mk_initialize_on_open);
}

void mk_initialize_engine(on_execute_succeed *cb)
{
    assert(sizeof(mk_page) == MK_PAGE_SIZE);

    mk_initialize_context *context = malloc(sizeof(mk_initialize_context));

    context->cb = cb;

	context->stat_req = malloc(sizeof(uv_fs_t));
	context->stat_req->data = context;

    context->path = malloc(sizeof(char) * 256);
    snprintf(context->path, 256, "%s/db.0", MK_DATA_DIR);

	uv_fs_stat(uv_default_loop(), context->stat_req, context->path, mk_initialize_on_stat);
}
