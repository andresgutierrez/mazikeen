
#ifndef MK_SCANNER_H
#define MK_SCANNER_H

#define MK_SCANNER_RETCODE_EOF -1
#define MK_SCANNER_RETCODE_ERR -2
#define MK_SCANNER_RETCODE_IMPOSSIBLE -3

/** Modes */
#define MK_T_IGNORE 297

/* Literals & Identifiers */
#define MK_T_INTEGER 301
#define MK_T_DOUBLE 302
#define MK_T_STRING 303
#define MK_T_NULL 304
#define MK_T_FALSE 305
#define MK_T_TRUE 306
#define MK_T_IDENTIFIER 307
#define MK_T_ARRAY 308
#define MK_T_CHAR 309
#define MK_T_ISTRING 310

#define MK_T_TYPE_INTEGER 320
#define MK_T_TYPE_DOUBLE 321
#define MK_T_TYPE_BOOL 322
#define MK_T_TYPE_STRING 323
#define MK_T_TYPE_VAR 324
#define MK_T_TYPE_LONG 325
#define MK_T_TYPE_ULONG 326
#define MK_T_TYPE_CHAR 327
#define MK_T_TYPE_UCHAR 328
#define MK_T_TYPE_UINTEGER 329
#define MK_T_TYPE_ARRAY 330

#define MK_T_INSERT 350
#define MK_T_INTO 351
#define MK_T_VALUES 352
#define MK_T_CREATE 353
#define MK_T_COLLECTION 354

/* Operators */
#define MK_T_AT '@'
#define MK_T_DOT '.'
#define MK_T_COMMA ','
#define MK_T_ASSIGN '='
#define MK_T_LESS '<'
#define MK_T_GREATER '>'
#define MK_T_COLON ':'
#define MK_T_DOTCOMMA ';'
#define MK_T_QUESTION '?'
#define MK_T_BRACKET_OPEN '{'
#define MK_T_BRACKET_CLOSE '}'
#define MK_T_SBRACKET_OPEN '['
#define MK_T_SBRACKET_CLOSE ']'
#define MK_T_PARENTHESES_OPEN '('
#define MK_T_PARENTHESES_CLOSE ')'
#define MK_T_BITWISE_OR '|'
#define MK_T_BITWISE_AND '&'
#define MK_T_BITWISE_XOR '^'
#define MK_T_ARROW 400
#define MK_T_EQUALS 401
#define MK_T_IDENTICAL 402
#define MK_T_ADD '+'
#define MK_T_SUB '-'
#define MK_T_MUL '*'
#define MK_T_DIV '/'
#define MK_T_MOD '%'
#define MK_T_INCR 403
#define MK_T_DECR 404
#define MK_T_NOTEQUALS 405
#define MK_T_NOTIDENTICAL 406
#define MK_T_NOT 407
#define MK_T_BITWISE_NOT '~'
#define MK_T_GREATEREQUAL 408
#define MK_T_LESSEQUAL 409
#define MK_T_ADDASSIGN 410
#define MK_T_SUBASSIGN 411
#define MK_T_MULASSIGN 412
#define MK_T_DIVASSIGN 413
#define MK_T_CONCATASSIGN 414
#define MK_T_AND 415
#define MK_T_OR 416
#define MK_T_DOUBLECOLON 417
#define MK_T_MODASSIGN 418
#define MK_T_BITWISE_SHIFTLEFT 419
#define MK_T_BITWISE_SHIFTRIGHT 420
#define MK_T_DOUBLEARROW 440
#define MK_T_INCLUSIVE_RANGE 441
#define MK_T_EXCLUSIVE_RANGE 442

#define MK_T_CBLOCK 451

#define MK_T_ELSEIF 452
#define MK_T_INTERNAL 453

#endif
