
#include "../mk.h"

int mk_execute_command(mk_session *session, mk_ast_node *node, on_execute_succeed *cb)
{
    switch (node->type) {

        case MK_AST_T_INSERT:
            return mk_insert_into_coll(session, node, cb);

        case MK_AST_T_OPEN_DB:
            return mk_open_db(session, node, cb);

        case MK_AST_T_CREATE_COLL:
            return mk_create_coll(session, node, cb);

        case MK_AST_T_DROP_COLL:
            return mk_drop_coll(session, node, cb);

        default:
            fprintf(stderr, "Error: Unknown Command=%d\n", node->type);
    }

    return FAILURE;
}

int mk_execute_command_str(mk_session *session, const char *command, int command_len, on_execute_succeed *cb)
{
    char *error_msg = NULL;

    mk_ast_node *root = mk_parse_command(command, command_len, "", &error_msg);
    if (root == NULL)
    {
        fprintf(stderr, "Error: %s\n", error_msg);
        return FAILURE;
    }

    return mk_execute_command(session, root, cb);
}

mk_collection *mk_get_collection(mk_db *db, const char *name, int name_len)
{
    for (int i = 0; i < db->number; i++) {
        mk_collection *collection = db->collections[i];
        if (collection == NULL) {
            continue;
        }
        if (name_len != collection->name_len) {
            continue;
        }
        if (!strcmp(name, collection->name)) {
            return collection;
        }
    }
    return NULL;
}
