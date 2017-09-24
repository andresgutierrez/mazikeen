#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#include "mk.h"
#include "parser/parser.h"
#include "ops/executor.h"

int main(int argc, char **argv)
{
    char *error_msg = NULL;
    char *program = "use test";

    mk_ast_node *root = mk_parse_command(program, strlen(program), "a.x", &error_msg);
    if (root == NULL)
    {
        fprintf(stderr, "Error=%s\n", error_msg);
        return 0;
    }

    mk_execute_command(root);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    return 0;
}
