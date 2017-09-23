#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "../mk.h"
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

static mk_ast_node *mk_ret_coll_field_def(mk_parser_token *T)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    //node->type = ;
    node->value = T->token;
    node->len = T->token_len;
    return node;
}

static mk_ast_node *mk_ret_insert(mk_parser_token *I, mk_ast_node *values)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = MK_AST_T_INSERT;
    node->n0 = values;
    return node;
}

static mk_ast_node *mk_ret_create_coll(mk_parser_token *C, mk_ast_node *fields)
{
    mk_ast_node *node = malloc(sizeof(mk_ast_node));
    node->type = MK_AST_T_CREATE_COLL;
    node->value = C->token;
    node->len = C->token_len;
    node->n0 = fields;
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
