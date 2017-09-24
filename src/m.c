#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mk.h"

int main(int argc, char **argv)
{
    mk_session *session = malloc(sizeof(mk_session));
    session->db = NULL;

    mk_execute_command_str(session, MK_STRL("use test"));

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
    return 0;
}
