
#ifndef MK_H
#define MK_H

#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

#include "engine/memory.h"

typedef struct _mk_document {
    int pointer;
    int buffer_len;
    uint8_t *buffer;
} mk_document;

typedef struct _mk_collection {
    char *name;
    int name_len;
    char *path;
    uv_fs_t *open_req;
    int writable_page_offset;
    mk_page* writable_page;
} mk_collection;

typedef struct _mk_db {
    char *name;
    int name_len;
    int number;
    mk_collection **collections;
} mk_db;

typedef struct _mk_session {
    mk_db *db;
} mk_session;

#include "parser/parser.h"
#include "executor/executor.h"
#include "engine/engine.h"

#define MK_DATA_DIR "data"
#define MK_DEFAULT_DB "test"

#endif
