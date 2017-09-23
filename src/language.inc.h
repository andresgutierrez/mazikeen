#include <string.h>
#include <stdlib.h>

#include "mk.h"
#include "parser.h"
#include "language.h"
#include "scanner.h"

static mk_ast_node *mk_ret_literal(int type, mk_parser_token *T)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = type;
    node->value = T->token;
    node->len = T->token_len;
    return node;
}

static mk_ast_node *mk_ret_insert(mk_parser_token *I, mk_ast_node *values)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = MK_AST_T_INSERT;
    return node;
}

static mk_ast_node *mk_ret_list(mk_ast_node *left, mk_ast_node *right)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = MK_AST_T_LIST;
    node->n0 = left;
    node->n1 = right;
    return node;
}
