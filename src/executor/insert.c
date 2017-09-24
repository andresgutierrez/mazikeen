
#include "../mk.h"

static void mk_write_value_to_record(mk_document *document, mk_ast_node *value)
{
    switch (value->type) {
        case MK_AST_T_INTEGER:
            mk_pack_long(document, strtol(value->value, NULL, 10));
            break;
    }
}

static void mk_insert_on_open_coll(mk_open_coll_request *req)
{
    mk_insert_open_coll_context *context = (mk_insert_open_coll_context *) req->data;

    mk_ast_node *node = context->node;
    mk_session *session = context->session;
    mk_collection *collection = context->collection;

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
    document->buffer = malloc(MK_DOCUMENT_SIZE);
    document->buffer_len = MK_DOCUMENT_SIZE;

    for (int i = 0; i < number; i++) {
        mk_write_value_to_record(document, values[i]);
    }

    mk_append_document_to_coll(collection, document);

    free(context);
    free(values);
    free(req);
}

int mk_insert_into_coll(mk_session *session, mk_ast_node *node, on_execute_succeed *cb)
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

    mk_open_coll_request *req = (mk_open_coll_request *) malloc(sizeof(mk_open_coll_request));
    mk_insert_open_coll_context *context = (mk_insert_open_coll_context *) malloc(sizeof(mk_insert_open_coll_context));

    context->session = session;
    context->cb = cb;
    context->node = node;
    context->collection = collection;

    req->data = context;

    if (collection->is_closed) {
        fprintf(stderr, "Collection '%s' must be opened\n", node->value);
        mk_open_coll(collection, req, mk_insert_on_open_coll);
    } else {
        mk_insert_on_open_coll(req);
    }

    return SUCCESS;
}
