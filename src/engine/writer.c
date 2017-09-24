
#include "../mk.h"

static mk_page *mk_get_writable_page(mk_collection *collection)
{
    if (collection->writable_page == NULL) {
        collection->writable_page = mk_allocate_page();
    }
    return collection->writable_page;
}

void mk_append_document_to_coll(mk_collection *collection, mk_document *document)
{
    mk_page *writable_page = mk_get_writable_page(collection);

    //fprintf(stderr, "%zu\n", writable_page->size);

    //memcpy();
}
