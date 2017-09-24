
#include "../mk.h"

mk_page *mk_allocate_page()
{
    mk_page *page = malloc(sizeof(mk_page));
    return page;
}
