
#ifndef MK_EXECUTOR_H
#define MK_EXECUTOR_H

#include <uv.h>

typedef struct _mk_open_coll_request {
    void *data;
} mk_open_coll_request;

typedef void (on_execute_succeed)(mk_session *session);
typedef void (on_open_coll_cb)(mk_open_coll_request *req);

typedef struct _mk_open_db_context {
    mk_session *session;
    char *name;
    int name_len;
    char *path;
    on_execute_succeed *cb;
    uv_fs_t *stat_req;
    uv_fs_t *scan_req;
} mk_open_db_context;

typedef struct _mk_open_coll_context {
    mk_collection *collection;
    char *buffer;
    int buffer_len;
    mk_open_coll_request *req;
    on_open_coll_cb *cb;
    uv_buf_t iov;
    uv_fs_t *stat_req;
    uv_fs_t *read_req;
    uv_fs_t *open_req;
} mk_open_coll_context;

typedef struct _mk_create_coll_context {
    mk_session *session;
    char *path;
    on_execute_succeed *cb;
    uv_fs_t *stat_req;
    uv_fs_t *open_req;
    uv_fs_t *write_req;
    uv_fs_t *close_req;
} mk_create_coll_context;

typedef struct mk_insert_open_coll_context {
    mk_session *session;
    mk_ast_node *node;
    mk_collection *collection;
    on_execute_succeed *cb;
} mk_insert_open_coll_context;

int mk_execute_command(mk_session *session, mk_ast_node *node, on_execute_succeed *cb);
int mk_execute_command_str(mk_session *session, const char *command, int command_len, on_execute_succeed *cb);

int mk_create_coll(mk_session *session, mk_ast_node *node, on_execute_succeed *cb);
int mk_open_db(mk_session *session, mk_ast_node *node, on_execute_succeed *cb);
int mk_open_coll(mk_collection *collection, mk_open_coll_request *req, on_open_coll_cb *cb);
int mk_insert_into_coll(mk_session *session, mk_ast_node *node, on_execute_succeed *cb);
int mk_drop_coll(mk_session *session, mk_ast_node *node, on_execute_succeed *cb);

mk_collection *mk_get_collection(mk_db *db, const char *name, int name_len);

#endif
