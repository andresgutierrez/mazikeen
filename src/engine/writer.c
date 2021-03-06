
#include "../mk.h"

typedef struct _mk_writer_context {
	uint8_t *buffer;
	uv_fs_t *write_req;
} mk_writer_context;

static mk_page *mk_get_writable_page(mk_collection *collection)
{
	if (collection->writable_page == NULL) {
#if MK_DEBUG		
		fprintf(stderr, "Debug: Allocating new page for collection %s\n", collection->name);
#endif
		collection->writable_page = mk_allocate_page();
	}
	return collection->writable_page;
}

static void mk_append_document_to_coll_cb(uv_fs_t *req)
{
	mk_writer_context *context = (mk_writer_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Error: Error writing to file: %s\n", uv_strerror((int)req->result));
		return;
	}

	uv_fs_req_cleanup(context->write_req);
	free(context->write_req);
	free(context->buffer);
	free(context);
}

void mk_append_document_to_coll(mk_collection *collection, mk_document *document)
{
	mk_page *writable_page = mk_get_writable_page(collection);

#if MK_DEBUG
	fprintf(stderr, "Debug: Set write pointer in %s to: %d\n", collection->name, writable_page->pointer);
#endif

	memcpy(writable_page->data + writable_page->pointer, document, sizeof(mk_document));
	writable_page->pointer += sizeof(mk_document);

	mk_writer_context *context = (mk_writer_context *) malloc(sizeof(mk_writer_context));

	context->write_req = malloc(sizeof(uv_fs_t));
	context->write_req->data = context;

	context->buffer = malloc(sizeof(mk_page));
	memcpy(context->buffer, writable_page, sizeof(mk_page));

	uv_buf_t iov = uv_buf_init((char *)context->buffer, sizeof(mk_page));
	uv_fs_write(uv_default_loop(), context->write_req, collection->open_req->result, &iov, 1, 0, mk_append_document_to_coll_cb);
}
