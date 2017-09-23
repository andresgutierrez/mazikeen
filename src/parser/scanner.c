/* Generated by re2c 0.14.3 on Sat Sep 23 18:35:39 2017 */
#line 1 "src/parser/scanner.re"

#include <string.h>
#include "../mk.h"
#include "parser.h"
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

		
#line 24 "src/parser/scanner.c"
		{
			YYCTYPE yych;
			unsigned int yyaccept = 0;

			yych = *YYCURSOR;
			switch (yych) {
			case 0x00:	goto yy72;
			case '\t':
			case '\r':
			case ' ':	goto yy68;
			case '\n':	goto yy70;
			case '!':	goto yy36;
			case '"':	goto yy18;
			case '$':	goto yy19;
			case '%':	goto yy56;
			case '&':	goto yy38;
			case '\'':	goto yy14;
			case '(':	goto yy22;
			case ')':	goto yy24;
			case '*':	goto yy52;
			case '+':	goto yy50;
			case ',':	goto yy64;
			case '-':	goto yy2;
			case '.':	goto yy58;
			case '/':	goto yy54;
			case '0':	goto yy4;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy6;
			case ':':	goto yy60;
			case ';':	goto yy62;
			case '<':	goto yy44;
			case '=':	goto yy48;
			case '>':	goto yy46;
			case '?':	goto yy66;
			case '@':	goto yy34;
			case 'A':
			case 'B':
			case 'D':
			case 'E':
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'U':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case 'a':
			case 'b':
			case 'd':
			case 'e':
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 'u':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy21;
			case 'C':
			case 'c':	goto yy13;
			case 'F':
			case 'f':	goto yy9;
			case 'I':
			case 'i':	goto yy11;
			case 'N':
			case 'n':	goto yy7;
			case 'T':
			case 't':	goto yy10;
			case 'V':
			case 'v':	goto yy12;
			case '[':	goto yy30;
			case '\\':
			case '_':	goto yy20;
			case ']':	goto yy32;
			case '^':	goto yy42;
			case '{':	goto yy26;
			case '|':	goto yy40;
			case '}':	goto yy28;
			case '~':	goto yy16;
			default:	goto yy74;
			}
yy2:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '-':	goto yy188;
			case '0':	goto yy194;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy180;
			case '=':	goto yy192;
			case '>':	goto yy190;
			default:	goto yy3;
			}
yy3:
#line 349 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SUB;
			return 0;
		}
#line 155 "src/parser/scanner.c"
yy4:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case 'x':	goto yy185;
			default:	goto yy181;
			}
yy5:
#line 25 "src/parser/scanner.re"
			{
			token->opcode = MK_T_INTEGER;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 173 "src/parser/scanner.c"
yy6:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy181;
yy7:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case 'U':
			case 'u':	goto yy175;
			default:	goto yy118;
			}
yy8:
#line 124 "src/parser/scanner.re"
			{
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			token->opcode = MK_T_IDENTIFIER;
			return 0;
		}
#line 195 "src/parser/scanner.c"
yy9:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy170;
			default:	goto yy118;
			}
yy10:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'R':
			case 'r':	goto yy166;
			default:	goto yy118;
			}
yy11:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'N':
			case 'n':	goto yy157;
			default:	goto yy118;
			}
yy12:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy151;
			default:	goto yy118;
			}
yy13:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy135;
			case 'R':
			case 'r':	goto yy136;
			default:	goto yy118;
			}
yy14:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych >= 0x01) goto yy131;
yy15:
#line 439 "src/parser/scanner.re"
			{
			status = MK_SCANNER_RETCODE_ERR;
			break;
		}
#line 243 "src/parser/scanner.c"
yy16:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case '"':	goto yy125;
			default:	goto yy17;
			}
yy17:
#line 181 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_NOT;
			return 0;
		}
#line 258 "src/parser/scanner.c"
yy18:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x00) goto yy15;
			goto yy120;
yy19:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy15;
			}
yy20:
			yych = *++YYCURSOR;
			goto yy118;
yy21:
			yych = *++YYCURSOR;
			goto yy118;
yy22:
			++YYCURSOR;
#line 133 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_OPEN;
			return 0;
		}
#line 337 "src/parser/scanner.c"
yy24:
			++YYCURSOR;
#line 139 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_CLOSE;
			return 0;
		}
#line 346 "src/parser/scanner.c"
yy26:
			++YYCURSOR;
#line 145 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BRACKET_OPEN;
			return 0;
		}
#line 355 "src/parser/scanner.c"
yy28:
			++YYCURSOR;
#line 151 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BRACKET_CLOSE;
			return 0;
		}
#line 364 "src/parser/scanner.c"
yy30:
			++YYCURSOR;
#line 157 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SBRACKET_OPEN;
			return 0;
		}
#line 373 "src/parser/scanner.c"
yy32:
			++YYCURSOR;
#line 163 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SBRACKET_CLOSE;
			return 0;
		}
#line 382 "src/parser/scanner.c"
yy34:
			++YYCURSOR;
#line 169 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_AT;
			return 0;
		}
#line 391 "src/parser/scanner.c"
yy36:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy113;
			default:	goto yy37;
			}
yy37:
#line 175 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_NOT;
			return 0;
		}
#line 405 "src/parser/scanner.c"
yy38:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '&':	goto yy111;
			default:	goto yy39;
			}
yy39:
#line 199 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_AND;
			return 0;
		}
#line 419 "src/parser/scanner.c"
yy40:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '|':	goto yy109;
			default:	goto yy41;
			}
yy41:
#line 205 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_OR;
			return 0;
		}
#line 433 "src/parser/scanner.c"
yy42:
			++YYCURSOR;
#line 211 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_XOR;
			return 0;
		}
#line 442 "src/parser/scanner.c"
yy44:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '<':	goto yy107;
			case '=':	goto yy105;
			default:	goto yy45;
			}
yy45:
#line 307 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_LESS;
			return 0;
		}
#line 457 "src/parser/scanner.c"
yy46:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy101;
			case '>':	goto yy103;
			default:	goto yy47;
			}
yy47:
#line 313 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_GREATER;
			return 0;
		}
#line 472 "src/parser/scanner.c"
yy48:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy97;
			case '>':	goto yy95;
			default:	goto yy49;
			}
yy49:
#line 229 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ASSIGN;
			return 0;
		}
#line 487 "src/parser/scanner.c"
yy50:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '+':	goto yy91;
			case '=':	goto yy93;
			default:	goto yy51;
			}
yy51:
#line 343 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ADD;
			return 0;
		}
#line 502 "src/parser/scanner.c"
yy52:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy89;
			default:	goto yy53;
			}
yy53:
#line 355 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MUL;
			return 0;
		}
#line 516 "src/parser/scanner.c"
yy54:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy87;
			default:	goto yy55;
			}
yy55:
#line 361 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DIV;
			return 0;
		}
#line 530 "src/parser/scanner.c"
yy56:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy85;
			default:	goto yy57;
			}
yy57:
#line 367 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MOD;
			return 0;
		}
#line 544 "src/parser/scanner.c"
yy58:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '.':	goto yy79;
			case '=':	goto yy81;
			default:	goto yy59;
			}
yy59:
#line 337 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DOT;
			return 0;
		}
#line 559 "src/parser/scanner.c"
yy60:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case ':':	goto yy77;
			default:	goto yy61;
			}
yy61:
#line 397 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_COLON;
			return 0;
		}
#line 573 "src/parser/scanner.c"
yy62:
			++YYCURSOR;
#line 403 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DOTCOMMA;
			return 0;
		}
#line 582 "src/parser/scanner.c"
yy64:
			++YYCURSOR;
#line 409 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_COMMA;
			return 0;
		}
#line 591 "src/parser/scanner.c"
yy66:
			++YYCURSOR;
#line 415 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_QUESTION;
			return 0;
		}
#line 600 "src/parser/scanner.c"
yy68:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy76;
yy69:
#line 421 "src/parser/scanner.re"
			{
			s->active_char += (YYCURSOR - start);
			token->opcode = MK_T_IGNORE;
			return 0;
		}
#line 612 "src/parser/scanner.c"
yy70:
			++YYCURSOR;
#line 427 "src/parser/scanner.re"
			{
			s->active_line++;
			s->active_char = 0;
			token->opcode = MK_T_IGNORE;
			return 0;
		}
#line 622 "src/parser/scanner.c"
yy72:
			++YYCURSOR;
#line 434 "src/parser/scanner.re"
			{
			status = MK_SCANNER_RETCODE_EOF;
			break;
		}
#line 630 "src/parser/scanner.c"
yy74:
			yych = *++YYCURSOR;
			goto yy15;
yy75:
			++YYCURSOR;
			yych = *YYCURSOR;
yy76:
			switch (yych) {
			case '\t':
			case '\r':
			case ' ':	goto yy75;
			default:	goto yy69;
			}
yy77:
			++YYCURSOR;
#line 331 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DOUBLECOLON;
			return 0;
		}
#line 652 "src/parser/scanner.c"
yy79:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '.':	goto yy83;
			default:	goto yy80;
			}
yy80:
#line 385 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_INCLUSIVE_RANGE;
			return 0;
		}
#line 666 "src/parser/scanner.c"
yy81:
			++YYCURSOR;
#line 265 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_CONCATASSIGN;
			return 0;
		}
#line 675 "src/parser/scanner.c"
yy83:
			++YYCURSOR;
#line 391 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_EXCLUSIVE_RANGE;
			return 0;
		}
#line 684 "src/parser/scanner.c"
yy85:
			++YYCURSOR;
#line 259 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MODASSIGN;
			return 0;
		}
#line 693 "src/parser/scanner.c"
yy87:
			++YYCURSOR;
#line 253 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DIVASSIGN;
			return 0;
		}
#line 702 "src/parser/scanner.c"
yy89:
			++YYCURSOR;
#line 247 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MULASSIGN;
			return 0;
		}
#line 711 "src/parser/scanner.c"
yy91:
			++YYCURSOR;
#line 373 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_INCR;
			return 0;
		}
#line 720 "src/parser/scanner.c"
yy93:
			++YYCURSOR;
#line 235 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ADDASSIGN;
			return 0;
		}
#line 729 "src/parser/scanner.c"
yy95:
			++YYCURSOR;
#line 325 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DOUBLEARROW;
			return 0;
		}
#line 738 "src/parser/scanner.c"
yy97:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy99;
			default:	goto yy98;
			}
yy98:
#line 271 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_EQUALS;
			return 0;
		}
#line 752 "src/parser/scanner.c"
yy99:
			++YYCURSOR;
#line 283 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_IDENTICAL;
			return 0;
		}
#line 761 "src/parser/scanner.c"
yy101:
			++YYCURSOR;
#line 301 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_GREATEREQUAL;
			return 0;
		}
#line 770 "src/parser/scanner.c"
yy103:
			++YYCURSOR;
#line 223 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTRIGHT;
			return 0;
		}
#line 779 "src/parser/scanner.c"
yy105:
			++YYCURSOR;
#line 295 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_LESSEQUAL;
			return 0;
		}
#line 788 "src/parser/scanner.c"
yy107:
			++YYCURSOR;
#line 217 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTLEFT;
			return 0;
		}
#line 797 "src/parser/scanner.c"
yy109:
			++YYCURSOR;
#line 193 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_OR;
			return 0;
		}
#line 806 "src/parser/scanner.c"
yy111:
			++YYCURSOR;
#line 187 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_AND;
			return 0;
		}
#line 815 "src/parser/scanner.c"
yy113:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy115;
			default:	goto yy114;
			}
yy114:
#line 277 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_NOTEQUALS;
			return 0;
		}
#line 829 "src/parser/scanner.c"
yy115:
			++YYCURSOR;
#line 289 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_NOTIDENTICAL;
			return 0;
		}
#line 838 "src/parser/scanner.c"
yy117:
			++YYCURSOR;
			yych = *YYCURSOR;
yy118:
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy8;
			}
yy119:
			++YYCURSOR;
			yych = *YYCURSOR;
yy120:
			switch (yych) {
			case 0x00:	goto yy121;
			case '"':	goto yy123;
			case '\\':	goto yy122;
			default:	goto yy119;
			}
yy121:
			YYCURSOR = YYMARKER;
			switch (yyaccept) {
			case 0: 	goto yy5;
			case 1: 	goto yy15;
			default:	goto yy17;
			}
yy122:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy121;
			default:	goto yy119;
			}
yy123:
			++YYCURSOR;
#line 113 "src/parser/scanner.re"
			{
			token->opcode = MK_T_STRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 945 "src/parser/scanner.c"
yy125:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case 0x00:	goto yy121;
			case '"':	goto yy128;
			case '\\':	goto yy127;
			default:	goto yy125;
			}
yy127:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy121;
			default:	goto yy125;
			}
yy128:
			++YYCURSOR;
#line 103 "src/parser/scanner.re"
			{
			token->opcode = MK_T_ISTRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 973 "src/parser/scanner.c"
yy130:
			++YYCURSOR;
			yych = *YYCURSOR;
yy131:
			switch (yych) {
			case 0x00:	goto yy121;
			case '\'':	goto yy133;
			case '\\':	goto yy132;
			default:	goto yy130;
			}
yy132:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy121;
			default:	goto yy130;
			}
yy133:
			++YYCURSOR;
#line 93 "src/parser/scanner.re"
			{
			token->opcode = MK_T_CHAR;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 1002 "src/parser/scanner.c"
yy135:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy142;
			default:	goto yy118;
			}
yy136:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy137;
			default:	goto yy118;
			}
yy137:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy138;
			default:	goto yy118;
			}
yy138:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy139;
			default:	goto yy118;
			}
yy139:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy140;
			default:	goto yy118;
			}
yy140:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy141;
			}
yy141:
#line 80 "src/parser/scanner.re"
			{
			s->active_char += sizeof("create")-1;
			token->opcode = MK_T_CREATE;
			return 0;
		}
#line 1114 "src/parser/scanner.c"
yy142:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy143;
			default:	goto yy118;
			}
yy143:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy144;
			default:	goto yy118;
			}
yy144:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'C':
			case 'c':	goto yy145;
			default:	goto yy118;
			}
yy145:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy146;
			default:	goto yy118;
			}
yy146:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'I':
			case 'i':	goto yy147;
			default:	goto yy118;
			}
yy147:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy148;
			default:	goto yy118;
			}
yy148:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'N':
			case 'n':	goto yy149;
			default:	goto yy118;
			}
yy149:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy150;
			}
yy150:
#line 86 "src/parser/scanner.re"
			{
			s->active_char += sizeof("collection")-1;
			token->opcode = MK_T_COLLECTION;
			return 0;
		}
#line 1240 "src/parser/scanner.c"
yy151:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy152;
			default:	goto yy118;
			}
yy152:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'U':
			case 'u':	goto yy153;
			default:	goto yy118;
			}
yy153:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy154;
			default:	goto yy118;
			}
yy154:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy155;
			default:	goto yy118;
			}
yy155:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy156;
			}
yy156:
#line 74 "src/parser/scanner.re"
			{
			s->active_char += sizeof("values")-1;
			token->opcode = MK_T_VALUES;
			return 0;
		}
#line 1345 "src/parser/scanner.c"
yy157:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy158;
			case 'T':
			case 't':	goto yy159;
			default:	goto yy118;
			}
yy158:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy162;
			default:	goto yy118;
			}
yy159:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy160;
			default:	goto yy118;
			}
yy160:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy161;
			}
yy161:
#line 68 "src/parser/scanner.re"
			{
			s->active_char += sizeof("into")-1;
			token->opcode = MK_T_INTO;
			return 0;
		}
#line 1445 "src/parser/scanner.c"
yy162:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'R':
			case 'r':	goto yy163;
			default:	goto yy118;
			}
yy163:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy164;
			default:	goto yy118;
			}
yy164:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy165;
			}
yy165:
#line 62 "src/parser/scanner.re"
			{
			s->active_char += sizeof("insert")-1;
			token->opcode = MK_T_INSERT;
			return 0;
		}
#line 1536 "src/parser/scanner.c"
yy166:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'U':
			case 'u':	goto yy167;
			default:	goto yy118;
			}
yy167:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy168;
			default:	goto yy118;
			}
yy168:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy169;
			}
yy169:
#line 56 "src/parser/scanner.re"
			{
			s->active_char += sizeof("true")-1;
			token->opcode = MK_T_TRUE;
			return 0;
		}
#line 1627 "src/parser/scanner.c"
yy170:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy171;
			default:	goto yy118;
			}
yy171:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy172;
			default:	goto yy118;
			}
yy172:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy173;
			default:	goto yy118;
			}
yy173:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy174;
			}
yy174:
#line 50 "src/parser/scanner.re"
			{
			s->active_char += sizeof("false")-1;
			token->opcode = MK_T_FALSE;
			return 0;
		}
#line 1725 "src/parser/scanner.c"
yy175:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy176;
			default:	goto yy118;
			}
yy176:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy177;
			default:	goto yy118;
			}
yy177:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy117;
			default:	goto yy178;
			}
yy178:
#line 44 "src/parser/scanner.re"
			{
			s->active_char += sizeof("null")-1;
			token->opcode = MK_T_NULL;
			return 0;
		}
#line 1816 "src/parser/scanner.c"
yy179:
			yych = *++YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy182;
			default:	goto yy121;
			}
yy180:
			yyaccept = 0;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy181:
			switch (yych) {
			case '.':	goto yy179;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy180;
			default:	goto yy5;
			}
yy182:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy182;
			default:	goto yy184;
			}
yy184:
#line 35 "src/parser/scanner.re"
			{
			token->opcode = MK_T_DOUBLE;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 1877 "src/parser/scanner.c"
yy185:
			yych = *++YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy186;
			default:	goto yy121;
			}
yy186:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':	goto yy186;
			default:	goto yy5;
			}
yy188:
			++YYCURSOR;
#line 379 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DECR;
			return 0;
		}
#line 1941 "src/parser/scanner.c"
yy190:
			++YYCURSOR;
#line 319 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_ARROW;
			return 0;
		}
#line 1950 "src/parser/scanner.c"
yy192:
			++YYCURSOR;
#line 241 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SUBASSIGN;
			return 0;
		}
#line 1959 "src/parser/scanner.c"
yy194:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case 'x':	goto yy185;
			default:	goto yy181;
			}
		}
#line 444 "src/parser/scanner.re"

	}

	return status;
}