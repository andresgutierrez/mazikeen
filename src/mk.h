
#ifndef MK_H
#define MK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _mk_collection {
    char *name;
    int name_len;
} mk_collection;

typedef struct _mk_db {
    char *name;
    int name_len;
    int number;
    mk_collection **collections;
} mk_db;

#include "parser/parser.h"
#include "ops/executor.h"

#define MK_DATA_DIR "data"
#define MK_DEFAULT_DB "test"

#endif
