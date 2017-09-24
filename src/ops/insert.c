
#include "../mk.h"

mk_page *mk_get_writable_page(mk_collection *collection)
{
    return mk_allocate_page();
}

void mk_write_value_to_page(mk_page *writable_page, mk_ast_node *value)
{
    switch (value->type) {
        case MK_AST_T_INTEGER:
            fprintf(stderr, "%ld\n", strtol(value->value, NULL, 10));
            break;
    }
}

int mk_insert_into_coll(mk_session *session, mk_ast_node *node)
{
    mk_db *db = session->db;

    if (db == NULL) {
        fprintf(stderr, "No database selected\n");
        return FAILURE;
    }

    mk_collection *collection = mk_get_collection(db, node->value, node->len);
    if (collection == NULL) {
        fprintf(stderr, "Collection '%s' does not exist\n", node->value);
        return FAILURE;
    }

    mk_page *writable_page = mk_get_writable_page(collection);

    mk_ast_node *value = node->n0;
    mk_write_value_to_page(writable_page, value->n0);
    mk_write_value_to_page(writable_page, value->n1->n0);
    mk_write_value_to_page(writable_page, value->n1->n1->n0);
    //while (node->n1 !=)

    fprintf(stderr, "%d\n", value->type);


    /*mk_create_coll_context *context = malloc(sizeof(mk_create_coll_context));

    context->stat_req = malloc(sizeof(uv_fs_t));
    context->stat_req->data = context;

    context->path = malloc(sizeof(char) * 256);
    snprintf(context->path, 256, "%s/%s/%s", MK_DATA_DIR, MK_DEFAULT_DB, node->value);
    fprintf(stderr, "%d %s %s\n", node->type, context->path, node->value);

    uv_fs_stat(uv_default_loop(), context->stat_req, context->path, mk_create_coll_on_stat);*/
    return SUCCESS;
}
