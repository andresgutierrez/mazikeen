
#ifndef MK_EXECUTOR_H
#define MK_EXECUTOR_H

#include <uv.h>

typedef void (on_open_db_cb)(mk_session *session, mk_db *db);

typedef struct _mk_open_db_context {
    mk_session *session;
    char *name;
    int name_len;
    char *path;
    on_open_db_cb *cb;
    uv_fs_t *stat_req;
    uv_fs_t *scan_req;
} mk_open_db_context;

typedef struct _mk_create_coll_context {
    mk_session *session;
    char *path;
    uv_fs_t *stat_req;
    uv_fs_t *open_req;
    uv_fs_t *write_req;
    uv_fs_t *close_req;
} mk_create_coll_context;

int mk_execute_command(mk_session *session, mk_ast_node *node);
int mk_execute_command_str(mk_session *session, const char *command, int command_len);

int mk_create_coll(mk_session *session, mk_ast_node *node);
int mk_open_db(mk_session *session, mk_ast_node *node, on_open_db_cb *cb);

#endif
