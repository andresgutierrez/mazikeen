#include <string.h>
#include <stdlib.h>
#include "language.h"
#include "mk.h"
#include "scanner.h"

static mk_ast_node *mk_ret_literal(int type, mk_parser_token *T)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = type;
    fprintf(stderr, "%s\n", T->token);
    return node;
}

static mk_ast_node *mk_ret_insert(mk_parser_token *I, mk_ast_node *values)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    //node->type = ;
    return node;
}

static mk_ast_node *mk_ret_list(mk_ast_node *values, mk_ast_node *k)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    //node->type = type;
    return node;
}
