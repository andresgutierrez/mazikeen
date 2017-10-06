#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mk.h"

static void on_fetch_document(mk_document *document)
{
    mk_unpack_value(document);
    fprintf(stderr, "Hello\n");
}

void on_insert_complete(mk_session *session)
{
    //mk_execute_command_str(session, MK_STRL("insert into x values (4, 5, 6)"), on_insert_complete);
    mk_dump_documents_from_coll(session, mk_get_collection(session->db, "x", strlen("x")), on_fetch_document);
}

void on_use_test(mk_session *session)
{
    mk_execute_command_str(session, MK_STRL("insert into x values (1, 2, 3)"), on_insert_complete);
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
