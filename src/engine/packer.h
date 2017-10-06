
#ifndef MK_PACKER_H
#define MK_PACKER_H

void mk_pack_long(mk_document *document, long number);
void mk_unpack_value(mk_document *document);

#define MK_TYPE_NULL 0
#define MK_TYPE_LONG 1
#define MK_TYPE_EXTENDED 15

#endif
