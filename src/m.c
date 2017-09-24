#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mk.h"

void on_use_test(mk_session *session)
{
    mk_execute_command_str(session, MK_STRL("insert into x values (1, 2, 3)"), NULL);
}

int main(int argc, char **argv)
{
    mk_session *session = malloc(sizeof(mk_session));
    session->db = NULL;

    mk_execute_command_str(session, MK_STRL("use test"), on_use_test);

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    free(session);
    return 0;
}
