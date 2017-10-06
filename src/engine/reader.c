
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
    fprintf(stderr, "%d\n", document->pointer);
    (context->cb)(document);
    //fprintf(stderr, "%.*s %zu\n", (int)context->iov.len, context->iov.base, context->iov.len);
}

static void mk_dump_documents_on_read(uv_fs_t *req)
{
	mk_reader_context *context = (mk_reader_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
		return;
	}

	if (req->result == 0) {
		//mk_open_coll_on_fetch_page(context);
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
