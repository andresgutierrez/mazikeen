
#ifndef MK_MEMORY_H
#define MK_MEMORY_H

#define MK_PAGE_SIZE 4096
#define MK_DOCUMENT_SIZE 1024

typedef struct _mk_page {
    int pointer;
    int size;
    void *data;
} mk_page;

mk_page *mk_allocate_page();

#endif
