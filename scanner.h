
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
#define MK_T_TYPE_CALLABLE 331
#define MK_T_TYPE_OBJECT 332
#define MK_T_TYPE_RESOURCE 333
#define MK_T_TYPE_NULL 334
#define MK_T_TYPE_THIS 335

#define MK_T_NAMESPACE 350
#define MK_T_CLASS 351
#define MK_T_PUBLIC 352
#define MK_T_PROTECTED 353
#define MK_T_EXTENDS 354
#define MK_T_FUNCTION 355
#define MK_T_LET 356
#define MK_T_COMMENT 357
#define MK_T_ECHO 358
#define MK_T_CONST 359
#define MK_T_ABSTRACT 360
#define MK_T_IMPLEMENTS 361
#define MK_T_INTERFACE 362
#define MK_T_IF 363
#define MK_T_ELSE 364
#define MK_T_WHILE 365
#define MK_T_NEW 366
#define MK_T_RETURN 367
#define MK_T_LOOP 368
#define MK_T_BREAK 369
#define MK_T_CONTINUE 370
#define MK_T_INSTANCEOF 371
#define MK_T_TYPEOF 372
#define MK_T_ISSET 373
#define MK_T_UNSET 374
#define MK_T_THROW 375
#define MK_T_FOR 376
#define MK_T_IN 377
#define MK_T_FETCH 378
#define MK_T_SWITCH 379
#define MK_T_CASE 380
#define MK_T_DEFAULT 381
#define MK_T_REVERSE 382
#define MK_T_PRIVATE 383
#define MK_T_STATIC 384
#define MK_T_INLINE 385
#define MK_T_FINAL 386
#define MK_T_CONSTANT 387
#define MK_T_DO 388
#define MK_T_REQUIRE 389
#define MK_T_CLONE 390
#define MK_T_EMPTY 391
#define MK_T_VOID 392
#define MK_T_LIKELY 393
#define MK_T_UNLIKELY 394
#define MK_T_USE 395
#define MK_T_AS 396
#define MK_T_TRY 397
#define MK_T_CATCH 398
#define MK_T_DEPRECATED 399

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
