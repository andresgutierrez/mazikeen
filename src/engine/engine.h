
#ifndef MK_ENGINE_H
#define MK_ENGINE_H

#include "memory.h"
#include "packer.h"
#include "writer.h"
#include "reader.h"

#define MK_INITIALIZATION_BUFFER_SIZE 1024 * 1024

typedef struct _mk_initialize_context {
    int number;
    char *path;
    char *buffer;
    on_execute_succeed *cb;
    uv_fs_t *stat_req;
    uv_fs_t *open_req;
    uv_fs_t *write_req;
} mk_initialize_context;

void mk_initialize_engine(on_execute_succeed *cb);

#endif
