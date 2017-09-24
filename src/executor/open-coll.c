
#include "../mk.h"

static void mk_open_coll_on_fetch_page(mk_open_coll_context *context)
{
    uv_fs_req_cleanup(context->read_req);
    free(context->read_req);

    if (context->cb != NULL) {
        (context->cb)(context->req);
    }

    free(context);
}

static void mk_open_coll_on_read(uv_fs_t *req)
{
    mk_open_coll_context *context = (mk_open_coll_context*) req->data;

    if (req->result < 0) {
        fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
        return;
    }

    if (req->result == 0) {
        mk_open_coll_on_fetch_page(context);
        return;
    }

    if (req->result > 0) {

        memcpy(
            (&context->collection->writable_page->data) + context->collection->writable_page->pointer,
            context->iov.base,
            req->result
        );

        context->collection->writable_page->pointer += req->result;

        mk_open_coll_on_fetch_page(context);
        return;
    }
}

static void mk_open_coll_on_open(uv_fs_t *req)
{
    mk_open_coll_context *context = (mk_open_coll_context*) req->data;

    if (req->result < 0) {
        fprintf(stderr, "error opening file: %s\n", uv_strerror((int)req->result));
        return;
    }

    context->collection->open_req = req;
    context->collection->writable_page = mk_allocate_page();

    context->read_req = malloc(sizeof(uv_fs_t));
    context->read_req->data = context;

    context->buffer = malloc(MK_PAGE_SIZE);
    context->buffer_len = MK_PAGE_SIZE;

    context->iov = uv_buf_init(context->buffer, context->buffer_len);
    uv_fs_read(uv_default_loop(), context->read_req, req->result, &context->iov, 1, -1, mk_open_coll_on_read);
}

static void mk_open_coll_on_stat(uv_fs_t *req)
{
    if (req->result < 0) {
        fprintf(stderr, "Error stat file: %s\n", uv_strerror((int)req->result));
        return;
    }

    uv_stat_t *stat = (uv_stat_t *) req->ptr;
    mk_open_coll_context *context = (mk_open_coll_context*) req->data;

    if (stat == NULL) {
        fprintf(stderr, "Collection '%s' could not be opened\n", context->collection->path);
        return;
    }

    context->collection->writable_page_offset = stat->st_size / MK_PAGE_SIZE;

    uv_fs_req_cleanup(context->stat_req);
    free(context->stat_req);

    context->open_req = malloc(sizeof(uv_fs_t));
    context->open_req->data = context;

    uv_fs_open(uv_default_loop(), context->open_req, context->collection->path, O_RDWR | O_CREAT, 0644, mk_open_coll_on_open);
}

int mk_open_coll(mk_collection *collection, mk_open_coll_request *req, on_open_coll_cb *cb)
{
    mk_open_coll_context *context = malloc(sizeof(mk_open_coll_context));

    context->collection = collection;
    context->req = req;
    context->cb = cb;

    context->stat_req = malloc(sizeof(uv_fs_t));
    context->stat_req->data = context;

    uv_fs_stat(uv_default_loop(), context->stat_req, collection->path, mk_open_coll_on_stat);
    return SUCCESS;
}
