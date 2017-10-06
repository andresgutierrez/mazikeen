
#include "../mk.h"

typedef struct _mk_reader_context {
    mk_session *session;
    mk_collection *collection;
    uv_fs_t *read_req;
    uv_buf_t iov;
    char *buffer;
    int buffer_len;
    on_document_fetch *cb;
} mk_reader_context;

static void mk_dump_fetch_documents(mk_reader_context *context)
{
    mk_document *document = malloc(sizeof(mk_document));
    memcpy(document, context->iov.base, sizeof(mk_document));
    if (context->cb != NULL) {
        (context->cb)(document);
    }
    free(document);
}

static void mk_dump_cleanup(mk_reader_context *context)
{
    uv_fs_req_cleanup(context->read_req);

    free(context->buffer);
    free(context->read_req);
    free(context);
}

static void mk_dump_documents_on_read(uv_fs_t *req)
{
	mk_reader_context *context = (mk_reader_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
		return;
	}

	if (req->result == 0) {
		mk_dump_cleanup(context);
		return;
	}

    context->iov.len = req->result;
    if (context->iov.len == MK_PAGE_SIZE)
        mk_dump_fetch_documents(context);

    uv_fs_read(uv_default_loop(), context->read_req, context->collection->open_req->result, &context->iov, 1, -1, mk_dump_documents_on_read);
	return;
}

void mk_dump_documents_from_coll(mk_session *session, mk_collection *collection, on_document_fetch *cb)
{
    mk_reader_context *context = malloc(sizeof(mk_reader_context));
    context->session = session;
    context->collection = collection;
    context->cb = cb;

    context->read_req = malloc(sizeof(uv_fs_t));
	context->read_req->data = context;

    context->buffer = malloc(sizeof(mk_page));
	context->buffer_len = sizeof(mk_page);

    context->iov = uv_buf_init(context->buffer, context->buffer_len);
	uv_fs_read(uv_default_loop(), context->read_req, collection->open_req->result, &context->iov, 1, 0, mk_dump_documents_on_read);
}
