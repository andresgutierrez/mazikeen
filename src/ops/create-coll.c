
#include <uv.h>
#include "../mk.h"

static void mk_create_coll_cleanup(mk_create_coll_context *context)
{
    uv_fs_req_cleanup(context->open_req);
    uv_fs_req_cleanup(context->write_req);
    uv_fs_req_cleanup(context->close_req);

    free(context->open_req);
    free(context->write_req);
    free(context->close_req);
    free(context->path);

    free(context);
}

static void mk_create_coll_close_cb(uv_fs_t *req)
{
    mk_create_coll_context *context = (mk_create_coll_context*) req->data;

    if (req->result < 0) {
        fprintf(stderr, "error closing file: %s\n", uv_strerror((int)req->result));
        return;
    }

    mk_create_coll_cleanup(context);
}

static void mk_create_coll_write_cb(uv_fs_t *req)
{
    mk_create_coll_context *context = (mk_create_coll_context*) req->data;

    if (req->result < 0) {
        fprintf(stderr, "error writing to file: %s\n", uv_strerror((int)req->result));
        return;
    }

    uv_fs_close(uv_default_loop(), context->close_req, context->open_req->result, mk_create_coll_close_cb);
}

static void mk_create_coll_on_open(uv_fs_t *req)
{
    mk_create_coll_context *context = (mk_create_coll_context*) req->data;

    if (req->result < 0) {
        fprintf(stderr, "error opening file: %s\n", uv_strerror((int)req->result));
        return;
    }

    uv_buf_t iov = uv_buf_init("?", strlen("?") + 1);
    uv_fs_write(uv_default_loop(), context->write_req, context->open_req->result, &iov, 1, -1, mk_create_coll_write_cb);
}

void mk_create_coll_on_stat(uv_fs_t *req)
{
    uv_stat_t *stat = (uv_stat_t *) req->ptr;
    mk_create_coll_context *context = (mk_create_coll_context*) req->data;

    if (stat != NULL) {
        fprintf(stderr, "Collection '%s' already exists\n", context->path);
        return;
    }

    context->open_req = malloc(sizeof(uv_fs_t));
    context->write_req = malloc(sizeof(uv_fs_t));
    context->close_req = malloc(sizeof(uv_fs_t));

    context->open_req->data = context;
    context->write_req->data = context;
    context->close_req->data = context;

    uv_fs_open(uv_default_loop(), context->open_req, context->path, O_RDWR | O_CREAT, 0644, mk_create_coll_on_open);
}

int mk_create_coll(mk_ast_node *node)
{
    mk_create_coll_context *context = malloc(sizeof(mk_create_coll_context));

    context->stat_req = malloc(sizeof(uv_fs_t));
    context->stat_req->data = context;

    context->path = malloc(sizeof(char) * 256);
    snprintf(context->path, 256, "%s/%s/%s", MK_DATA_DIR, MK_DEFAULT_DB, node->value);
    fprintf(stderr, "%d %s %s\n", node->type, context->path, node->value);

    uv_fs_stat(uv_default_loop(), context->stat_req, context->path, mk_create_coll_on_stat);
    return SUCCESS;
}
