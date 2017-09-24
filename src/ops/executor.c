
#include "../mk.h"

void on_open_db(mk_session *session, mk_db *db)
{
    session->db = db;
    /*fprintf(stderr, "%s %d\n", db->name,  db->number);
    for (int i = 0; i < db->number; i++) {
        fprintf(stderr, "%s\n", db->collections[i]->name);
    }*/

    mk_execute_command_str(session, MK_STRL("create collection x (a, b, c)"));
}

int mk_execute_command(mk_session *session, mk_ast_node *node)
{
    switch (node->type) {

        case MK_AST_T_INSERT:
            break;

        case MK_AST_T_CREATE_COLL:
            return mk_create_coll(session, node);

        case MK_AST_T_OPEN_DB:
            return mk_open_db(session, node, on_open_db);

        default:
            fprintf(stderr, "Unknown Command=%d\n", node->type);
    }

    return FAILURE;
}

int mk_execute_command_str(mk_session *session, const char *command, int command_len)
{
    char *error_msg = NULL;

    mk_ast_node *root = mk_parse_command(command, command_len, "a.x", &error_msg);
    if (root == NULL)
    {
        fprintf(stderr, "Error=%s\n", error_msg);
        return FAILURE;
    }

    return mk_execute_command(session, root);
}
