
#ifndef MK_MEMORY_H
#define MK_MEMORY_H

#define MK_PAGE_SIZE 4096
#define MK_DOCUMENT_SIZE 1023

typedef struct _mk_page {
    int pointer;
    uint8_t data[MK_DOCUMENT_SIZE * 4];
} mk_page;

mk_page *mk_allocate_page();

#endif
