
#include "../mk.h"

mk_page *mk_allocate_page()
{
    mk_page *page = malloc(sizeof(mk_page));
    page->pointer = 0;
    page->size = MK_PAGE_SIZE - sizeof(int) * 2;
    page->data = malloc(page->size);
    return page;
}
