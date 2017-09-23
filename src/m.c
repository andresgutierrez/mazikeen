#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <uv.h>

#include "mk.h"
#include "parser/parser.h"

void on_read(uv_fs_t *req);

uv_fs_t open_req;
uv_fs_t read_req;
uv_fs_t write_req;

static char buffer[1024];

static uv_buf_t iov;

typedef struct _cl
{
    char *buffer;
    int len;
} cl;

void on_read(uv_fs_t *req) {
    if (req->result < 0) {
        fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
    }
    else if (req->result == 0) {
        uv_fs_t close_req;
        // synchronous
        uv_fs_close(uv_default_loop(), &close_req, open_req.result, NULL);
    }
    else if (req->result > 0) {
        iov.len = req->result;
        fprintf(stderr, "%.*s %zu\n", (int)iov.len, iov.base, iov.len);
        uv_fs_read(uv_default_loop(), &read_req, open_req.result, &iov, 1, -1, on_read);
    }
}

void on_open(uv_fs_t *req) {
    cl *c = (cl*) req->data;

    fprintf(stderr, "%d\n", c->len);

    assert(req == &open_req);
    if (req->result >= 0) {
        iov = uv_buf_init(buffer, sizeof(buffer));
        uv_fs_read(uv_default_loop(), &read_req, req->result, &iov, 1, -1, on_read);
    }
    else {
        fprintf(stderr, "error opening file: %s\n", uv_strerror((int)req->result));
    }
}

int main(int argc, char **argv) {

    char *error_msg = NULL;
    char *program = "create collection x (a, b, c)";

    mk_ast_node *root = mk_parse_command(program, strlen(program), "a.x", &error_msg);
    if (root != NULL)
        fprintf(stderr, "%d\n", root->type);
    else
    {
        fprintf(stderr, "Error=%s\n", error_msg);
    }

    /*cl c;
    c.len = 1000;
    open_req.data = &c;

    uv_fs_open(uv_default_loop(), &open_req, argv[1], O_RDONLY, 0, on_open);
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    uv_fs_req_cleanup(&open_req);
    uv_fs_req_cleanup(&read_req);
    uv_fs_req_cleanup(&write_req);*/

    return 0;
}
