
#include "../mk.h"

void mk_write_value_to_record(mk_document *document, mk_ast_node *value)
{
    switch (value->type) {
        case MK_AST_T_INTEGER:
            mk_pack_long(document, strtol(value->value, NULL, 10));
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

    int number = 0, limit;
    mk_ast_node *value = node->n0;

    do {
        number++;
        value = value->n1;
    } while (value != NULL);

    value = node->n0;
    limit = number - 1;
    mk_ast_node **values = malloc(sizeof(mk_ast_node *) * number);

    do {
        values[limit--] = value->n0;
        value = value->n1;
    } while (value != NULL);

    mk_document *document = malloc(sizeof(mk_document));
    document->pointer = 0;
    document->buffer = malloc(1024);
    document->buffer_len = 1024;

    for (int i = 0; i < number; i++) {
        mk_write_value_to_record(document, values[i]);
    }

    //fprintf(stderr, "%d\n", document->pointer);

    free(values);

    mk_append_document_to_coll(collection, document);

    /*mk_create_coll_context *context = malloc(sizeof(mk_create_coll_context));

    context->stat_req = malloc(sizeof(uv_fs_t));
    context->stat_req->data = context;

    context->path = malloc(sizeof(char) * 256);
    snprintf(context->path, 256, "%s/%s/%s", MK_DATA_DIR, MK_DEFAULT_DB, node->value);
    fprintf(stderr, "%d %s %s\n", node->type, context->path, node->value);

    uv_fs_stat(uv_default_loop(), context->stat_req, context->path, mk_create_coll_on_stat);*/
    return SUCCESS;
}
