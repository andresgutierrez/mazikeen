
#include "../mk.h"

static inline void mk_pack_type(mk_document *document, uint8_t type)
{
	uint8_t byteType = 0;

	if (type < 0x10) {
		byteType = (byteType & 0xf) | (type << 4);
	} else {
		byteType = (byteType & 0xf)  | (MK_TYPE_EXTENDED << 4);
		byteType = (byteType & 0xf0) | (type - 0xf);
	}

	memcpy(document->buffer + document->pointer, &byteType, sizeof(uint8_t));
	document->pointer++;
}

void mk_pack_long(mk_document *document, long number)
{
	mk_pack_type(document, MK_TYPE_LONG);
	memcpy(document->buffer + document->pointer, &number, sizeof(long));
	document->pointer += sizeof(long);
}

static uint8_t mk_parse_type(mk_document *document)
{
	uint8_t type_byte = document->buffer[document->pointer];
	uint8_t type = (type_byte & 0xf0) >> 4;

	if (type == MK_TYPE_EXTENDED) {
		return (type_byte & 0xf) + 0xf;
	}

	return type;
}

void mk_unpack_value(mk_document *document)
{
	document->pointer = 0;
	fprintf(stderr, "%d\n", mk_parse_type(document));

	/*mk_pack_type(document, MK_TYPE_LONG);
	memcpy(document->buffer + document->pointer, &number, sizeof(long));
	document->pointer += sizeof(long);*/
}
