
#include <string.h>
#include "mk.h"
#include "scanner.h"

#define YYCTYPE unsigned char
#define YYCURSOR (s->start)
#define YYLIMIT (s->end)
#define YYMARKER q

int mk_get_token(mk_scanner_state *s, mk_scanner_token *token) {

	char *q = YYCURSOR, *start = YYCURSOR;
	int status = MK_SCANNER_RETCODE_IMPOSSIBLE;
	int is_constant = 0, j;

	while (MK_SCANNER_RETCODE_IMPOSSIBLE == status) {

		/*!re2c
		re2c:indent:top = 2;
		re2c:yyfill:enable = 0;

		INTEGER = ([\-]?[0-9]+)|([\-]?[0][x][0-9A-Fa-f]+);
		INTEGER {
			token->opcode = MK_T_INTEGER;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}

		DOUBLE = ([\-]?[0-9]+[\.][0-9]+);
		DOUBLE {
			token->opcode = MK_T_DOUBLE;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}

		'null' {
			s->active_char += sizeof("null")-1;
			token->opcode = MK_T_NULL;
			return 0;
		}

		'false' {
			s->active_char += sizeof("false")-1;
			token->opcode = MK_T_FALSE;
			return 0;
		}

		'true' {
			s->active_char += sizeof("true")-1;
			token->opcode = MK_T_TRUE;
			return 0;
		}

		SCHAR = (['] ([\\][']|[\\].|[\001-\377]\[\\'])* [']);
		SCHAR {
			token->opcode = MK_T_CHAR;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}

		ISTRING = ([~]["] ([\\]["]|[\\].|[\001-\377]\[\\"])* ["]);
		ISTRING {
			token->opcode = MK_T_ISTRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}

		STRING = (["] ([\\]["]|[\\].|[\001-\377]\[\\"])* ["]);
		STRING {
			token->opcode = MK_T_STRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}

		/* We have to remove this and define constants in compiler */
		IDENTIFIER = [\\_\$]?[_a-zA-Z\\][a-zA-Z0-9_\\]*;
		IDENTIFIER {
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			token->opcode = MK_T_IDENTIFIER;
			return 0;
		}

		"(" {
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_OPEN;
			return 0;
		}

		")" {
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_CLOSE;
			return 0;
		}

		"{" {
			s->active_char++;
			token->opcode = MK_T_BRACKET_OPEN;
			return 0;
		}

		"}" {
			s->active_char++;
			token->opcode = MK_T_BRACKET_CLOSE;
			return 0;
		}

		"[" {
			s->active_char++;
			token->opcode = MK_T_SBRACKET_OPEN;
			return 0;
		}

		"]" {
			s->active_char++;
			token->opcode = MK_T_SBRACKET_CLOSE;
			return 0;
		}

		"@" {
			s->active_char++;
			token->opcode = MK_T_AT;
			return 0;
		}

		"!" {
			s->active_char++;
			token->opcode = MK_T_NOT;
			return 0;
		}

		"~" {
			s->active_char++;
			token->opcode = MK_T_BITWISE_NOT;
			return 0;
		}

		"&&" {
			s->active_char += 2;
			token->opcode = MK_T_AND;
			return 0;
		}

		"||" {
			s->active_char += 2;
			token->opcode = MK_T_OR;
			return 0;
		}

		"&" {
			s->active_char++;
			token->opcode = MK_T_BITWISE_AND;
			return 0;
		}

		"|" {
			s->active_char++;
			token->opcode = MK_T_BITWISE_OR;
			return 0;
		}

		"^" {
			s->active_char++;
			token->opcode = MK_T_BITWISE_XOR;
			return 0;
		}

		"<<" {
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTLEFT;
			return 0;
		}

		">>" {
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTRIGHT;
			return 0;
		}

		"=" {
			s->active_char++;
			token->opcode = MK_T_ASSIGN;
			return 0;
		}

		"+=" {
			s->active_char++;
			token->opcode = MK_T_ADDASSIGN;
			return 0;
		}

		"-=" {
			s->active_char++;
			token->opcode = MK_T_SUBASSIGN;
			return 0;
		}

		"*=" {
			s->active_char++;
			token->opcode = MK_T_MULASSIGN;
			return 0;
		}

		"/=" {
			s->active_char++;
			token->opcode = MK_T_DIVASSIGN;
			return 0;
		}

		"%=" {
			s->active_char++;
			token->opcode = MK_T_MODASSIGN;
			return 0;
		}

		".=" {
			s->active_char++;
			token->opcode = MK_T_CONCATASSIGN;
			return 0;
		}

		"==" {
			s->active_char += 2;
			token->opcode = MK_T_EQUALS;
			return 0;
		}

		"!=" {
			s->active_char += 2;
			token->opcode = MK_T_NOTEQUALS;
			return 0;
		}

		"===" {
			s->active_char += 3;
			token->opcode = MK_T_IDENTICAL;
			return 0;
		}

		"!==" {
			s->active_char += 3;
			token->opcode = MK_T_NOTIDENTICAL;
			return 0;
		}

		"<=" {
			s->active_char++;
			token->opcode = MK_T_LESSEQUAL;
			return 0;
		}

		">=" {
			s->active_char++;
			token->opcode = MK_T_GREATEREQUAL;
			return 0;
		}

		"<" {
			s->active_char++;
			token->opcode = MK_T_LESS;
			return 0;
		}

		">" {
			s->active_char++;
			token->opcode = MK_T_GREATER;
			return 0;
		}

		"->" {
			s->active_char += 2;
			token->opcode = MK_T_ARROW;
			return 0;
		}

		"=>" {
			s->active_char += 2;
			token->opcode = MK_T_DOUBLEARROW;
			return 0;
		}

		"::" {
			s->active_char += 2;
			token->opcode = MK_T_DOUBLECOLON;
			return 0;
		}

		"." {
			s->active_char++;
			token->opcode = MK_T_DOT;
			return 0;
		}

		"+" {
			s->active_char++;
			token->opcode = MK_T_ADD;
			return 0;
		}

		"-" {
			s->active_char++;
			token->opcode = MK_T_SUB;
			return 0;
		}

		"*" {
			s->active_char++;
			token->opcode = MK_T_MUL;
			return 0;
		}

		"/" {
			s->active_char++;
			token->opcode = MK_T_DIV;
			return 0;
		}

		"%" {
			s->active_char++;
			token->opcode = MK_T_MOD;
			return 0;
		}

		"++" {
			s->active_char += 2;
			token->opcode = MK_T_INCR;
			return 0;
		}

		"--" {
			s->active_char += 2;
			token->opcode = MK_T_DECR;
			return 0;
		}

		".." {
			s->active_char += 2;
			token->opcode = MK_T_INCLUSIVE_RANGE;
			return 0;
		}

		"..." {
			s->active_char += 3;
			token->opcode = MK_T_EXCLUSIVE_RANGE;
			return 0;
		}

		":" {
			s->active_char++;
			token->opcode = MK_T_COLON;
			return 0;
		}

		";" {
			s->active_char++;
			token->opcode = MK_T_DOTCOMMA;
			return 0;
		}

		"," {
			s->active_char++;
			token->opcode = MK_T_COMMA;
			return 0;
		}

		"?" {
			s->active_char++;
			token->opcode = MK_T_QUESTION;
			return 0;
		}

		[ \t\r]+ {
			s->active_char += (YYCURSOR - start);
			token->opcode = MK_T_IGNORE;
			return 0;
		}

		[\n] {
			s->active_line++;
			s->active_char = 0;
			token->opcode = MK_T_IGNORE;
			return 0;
		}

		"\000" {
			status = MK_SCANNER_RETCODE_EOF;
			break;
		}

		[^] {
			status = MK_SCANNER_RETCODE_ERR;
			break;
		}

		*/
	}

	return status;
}
