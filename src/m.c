#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mk.h"

static void on_fetch_document(mk_document *document)
{
	mk_unpack_value(document);
	fprintf(stderr, "Hello\n");
}

static void on_insert_complete(mk_session *session)
{
	//mk_execute_command_str(session, MK_STRL("insert into x values (4, 5, 6)"), on_insert_complete);
	mk_dump_documents_from_coll(session, mk_get_collection(session->db, "x", strlen("x")), on_fetch_document);
}

void on_create_complete(mk_session *session)
{
	fprintf(stderr, "Completed\n");
	mk_execute_command_str(session, MK_STRL("insert into x values (1, 2, 3)"), on_insert_complete);
}

static void on_drop_complete(mk_session *session)
{
	mk_execute_command_str(session, MK_STRL("create collection x (a, b, c)"), on_create_complete);
}

static void on_use_test(mk_session *session)
{
	mk_execute_command_str(session, MK_STRL("drop collection if exists x"), on_drop_complete);
}

static void on_initialized(mk_session *session)
{
	mk_execute_command_str(session, MK_STRL("use test"), on_use_test);
}

int main(int argc, char **argv)
{
	mk_initialize_engine(on_initialized);

	uv_run(uv_default_loop(), UV_RUN_DEFAULT);

	//free(session);
	return 0;
}
