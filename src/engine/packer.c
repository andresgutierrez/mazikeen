
#include "../mk.h"

void mk_pack_long(mk_document *document, long number)
{
    memcpy(document->buffer + document->pointer, &number, sizeof(long));
    document->pointer += sizeof(long);
}
