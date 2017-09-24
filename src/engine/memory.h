
#ifndef MK_MEMORY_H
#define MK_MEMORY_H

typedef struct _mk_page {
    size_t free;
    void *data;
} mk_page;

mk_page *mk_allocate_page();

#endif
