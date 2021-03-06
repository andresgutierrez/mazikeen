
#include "../mk.h"

static void mk_drop_coll_on_unlink(uv_fs_t *req)
{
	int i;
	mk_drop_coll_context *context = (mk_drop_coll_context*) req->data;

	if (req->result < 0) {
		fprintf(stderr, "Error: unlinking file: %s\n", uv_strerror((int)req->result));
		return;
	}

	uv_fs_req_cleanup(context->unlink_req);

	mk_db *db = context->session->db;
	for (i = 0; i < db->number; i++) {
		if (!strcmp(db->collections[i]->name, context->collection->name)) {
			free(db->collections[i]->name);
			free(db->collections[i]);
			db->collections[i] = NULL;
			break;
		}
	}

	if (context->cb != NULL) {
		(context->cb)(context->session);
	}

	free(context);
}

int mk_drop_coll(mk_session *session, mk_ast_node *node, on_execute_succeed *cb)
{
	mk_db *db = session->db;

	if (db == NULL) {
		fprintf(stderr, "Error: No database selected\n");
		return FAILURE;
	}

	mk_collection *collection = mk_get_collection(db, node->value, node->len);
	if (collection == NULL) {

		if (node->flags) {
			if (cb != NULL) {
				(cb)(session);
			}
			return SUCCESS;
		}

		fprintf(stderr, "Error: Collection '%s' does not exist\n", node->value);
		return FAILURE;
	}

	mk_drop_coll_context *context = malloc(sizeof(mk_drop_coll_context));

	context->session = session;
	context->cb = cb;
	context->collection = collection;

	context->unlink_req = malloc(sizeof(uv_fs_t));
	context->unlink_req->data = context;

	uv_fs_unlink(uv_default_loop(), context->unlink_req, collection->path, mk_drop_coll_on_unlink);
	return SUCCESS;
}
