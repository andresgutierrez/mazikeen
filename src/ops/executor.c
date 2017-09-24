
#include "../mk.h"

void on_open_db(mk_db *db)
{
    fprintf(stderr, "%s\n", db->name);
}

void mk_execute_command(mk_ast_node *node)
{
    switch (node->type) {

        case MK_AST_T_INSERT:
            break;

        case MK_AST_T_CREATE_COLL:
            mk_create_coll(node);
            break;

        case MK_AST_T_OPEN_DB:
            mk_open_db(node, on_open_db);
            break;

        default:
            fprintf(stderr, "Unknown Command=%d\n", node->type);
    }
}
