
#include "../mk.h"

void mk_execute_command(mk_ast_node *node)
{
    switch (node->type) {

        case MK_AST_T_INSERT:
            break;

        case MK_AST_T_CREATE_COLL:
            mk_create_coll(node);
            break;
    }
}
