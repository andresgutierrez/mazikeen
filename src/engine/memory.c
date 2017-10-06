
#include "../mk.h"

mk_page *mk_allocate_page()
{
	mk_page *page = malloc(sizeof(mk_page));
	page->pointer = 0;
	return page;
}
