
#include "../mk.h"

static void mk_open_db_on_scandir(uv_fs_t *req)
{
    if (req->result < 0) {
        fprintf(stderr, "error scanning dir: %s\n", uv_strerror((int)req->result));
        return;
    }

    uv_dirent_t *dent = malloc(sizeof(dent));
    mk_open_db_context *context = (mk_open_db_context*) req->data;

    mk_db *db = (mk_db*) malloc(sizeof(mk_db));
    db->name = context->name;
    db->name_len = context->name_len;
    db->collections = malloc(sizeof(mk_collection *) * 16);
    db->number = 0;

    int i = 0;
    while (UV_EOF != uv_fs_scandir_next(req, dent)) {

        int length = strlen(dent->name);

        mk_collection *collection = (mk_collection*) malloc(sizeof(mk_collection));
        collection->name = strndup(dent->name, length);
        collection->name_len = length;
        collection->path = malloc(sizeof(char) * 256);
        collection->append_page_offset = 0;

        snprintf(collection->path, 256, "%s/%s/%s", MK_DATA_DIR, db->name, dent->name);

        db->collections[i++] = collection;
        db->number++;
    }

    uv_fs_req_cleanup(context->scan_req);
    free(context->scan_req);
    free(dent);

    if (context->cb != NULL) {
        (context->cb)(context->session, db);
    }

    free(context);
}

static void mk_open_db_on_stat(uv_fs_t *req)
{
    if (req->result < 0) {
        fprintf(stderr, "error stat dir: %s\n", uv_strerror((int)req->result));
        return;
    }

    uv_stat_t *stat = (uv_stat_t *) req->ptr;
    mk_open_db_context *context = (mk_open_db_context*) req->data;

    if (stat == NULL) {
        fprintf(stderr, "Database '%s' does not exist\n", context->path);
        return;
    }

    uv_fs_req_cleanup(context->stat_req);
    free(context->stat_req);

    context->scan_req = malloc(sizeof(uv_fs_t));
    context->scan_req->data = context;

    uv_fs_scandir(uv_default_loop(), context->scan_req, context->path, 0, mk_open_db_on_scandir);
}

int mk_open_db(mk_session *session, mk_ast_node *node, on_open_db_cb *cb)
{
    mk_open_db_context *context = malloc(sizeof(mk_open_db_context));

    context->path = malloc(sizeof(char) * 256);
    snprintf(context->path, 256, "%s/%s", MK_DATA_DIR, node->value);
    fprintf(stderr, "%d %s %s\n", node->type, context->path, node->value);

    context->session = session;
    context->cb = cb;

    context->stat_req = malloc(sizeof(uv_fs_t));
    context->stat_req->data = context;

    context->name = node->value;
    context->name_len = node->len;

    uv_fs_stat(uv_default_loop(), context->stat_req, context->path, mk_open_db_on_stat);
    return SUCCESS;
}
