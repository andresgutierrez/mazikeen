
#ifndef MK_READER_H
#define MK_READER_H

typedef void (on_document_fetch)(mk_document *document);
void mk_dump_documents_from_coll(mk_session *session, mk_collection *collection, on_document_fetch on_fetch);

#endif
