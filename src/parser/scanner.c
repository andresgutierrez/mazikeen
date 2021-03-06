/* Generated by re2c 0.14.3 on Wed Oct 11 19:08:51 2017 */
#line 1 "src/parser/scanner.re"

#include <string.h>
#include "../mk.h"
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

		
#line 23 "src/parser/scanner.c"
		{
			YYCTYPE yych;
			unsigned int yyaccept = 0;

			yych = *YYCURSOR;
			switch (yych) {
			case 0x00:	goto yy75;
			case '\t':
			case '\r':
			case ' ':	goto yy71;
			case '\n':	goto yy73;
			case '!':	goto yy39;
			case '"':	goto yy21;
			case '$':	goto yy22;
			case '%':	goto yy59;
			case '&':	goto yy41;
			case '\'':	goto yy17;
			case '(':	goto yy25;
			case ')':	goto yy27;
			case '*':	goto yy55;
			case '+':	goto yy53;
			case ',':	goto yy67;
			case '-':	goto yy2;
			case '.':	goto yy61;
			case '/':	goto yy57;
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
			case ':':	goto yy63;
			case ';':	goto yy65;
			case '<':	goto yy47;
			case '=':	goto yy51;
			case '>':	goto yy49;
			case '?':	goto yy69;
			case '@':	goto yy37;
			case 'A':
			case 'B':
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
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case 'a':
			case 'b':
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
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy24;
			case 'C':
			case 'c':	goto yy13;
			case 'D':
			case 'd':	goto yy15;
			case 'E':
			case 'e':	goto yy16;
			case 'F':
			case 'f':	goto yy9;
			case 'I':
			case 'i':	goto yy11;
			case 'N':
			case 'n':	goto yy7;
			case 'T':
			case 't':	goto yy10;
			case 'U':
			case 'u':	goto yy14;
			case 'V':
			case 'v':	goto yy12;
			case '[':	goto yy33;
			case '\\':
			case '_':	goto yy23;
			case ']':	goto yy35;
			case '^':	goto yy45;
			case '{':	goto yy29;
			case '|':	goto yy43;
			case '}':	goto yy31;
			case '~':	goto yy19;
			default:	goto yy77;
			}
yy2:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '-':	goto yy214;
			case '0':	goto yy220;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy206;
			case '=':	goto yy218;
			case '>':	goto yy216;
			default:	goto yy3;
			}
yy3:
#line 378 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SUB;
			return 0;
		}
#line 154 "src/parser/scanner.c"
yy4:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case 'x':	goto yy211;
			default:	goto yy207;
			}
yy5:
#line 24 "src/parser/scanner.re"
			{
			token->opcode = MK_T_INTEGER;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 172 "src/parser/scanner.c"
yy6:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy207;
yy7:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case 'U':
			case 'u':	goto yy201;
			default:	goto yy121;
			}
yy8:
#line 153 "src/parser/scanner.re"
			{
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			token->opcode = MK_T_IDENTIFIER;
			return 0;
		}
#line 194 "src/parser/scanner.c"
yy9:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy196;
			default:	goto yy121;
			}
yy10:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'R':
			case 'r':	goto yy192;
			default:	goto yy121;
			}
yy11:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'F':
			case 'f':	goto yy181;
			case 'N':
			case 'n':	goto yy183;
			default:	goto yy121;
			}
yy12:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy175;
			default:	goto yy121;
			}
yy13:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy159;
			case 'R':
			case 'r':	goto yy160;
			default:	goto yy121;
			}
yy14:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy156;
			default:	goto yy121;
			}
yy15:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy144;
			case 'R':
			case 'r':	goto yy145;
			default:	goto yy121;
			}
yy16:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'X':
			case 'x':	goto yy138;
			default:	goto yy121;
			}
yy17:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych >= 0x01) goto yy134;
yy18:
#line 468 "src/parser/scanner.re"
			{
			status = MK_SCANNER_RETCODE_ERR;
			break;
		}
#line 267 "src/parser/scanner.c"
yy19:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case '"':	goto yy128;
			default:	goto yy20;
			}
yy20:
#line 210 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_NOT;
			return 0;
		}
#line 282 "src/parser/scanner.c"
yy21:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x00) goto yy18;
			goto yy123;
yy22:
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
			case 'z':	goto yy120;
			default:	goto yy18;
			}
yy23:
			yych = *++YYCURSOR;
			goto yy121;
yy24:
			yych = *++YYCURSOR;
			goto yy121;
yy25:
			++YYCURSOR;
#line 162 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_OPEN;
			return 0;
		}
#line 361 "src/parser/scanner.c"
yy27:
			++YYCURSOR;
#line 168 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_PARENTHESES_CLOSE;
			return 0;
		}
#line 370 "src/parser/scanner.c"
yy29:
			++YYCURSOR;
#line 174 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BRACKET_OPEN;
			return 0;
		}
#line 379 "src/parser/scanner.c"
yy31:
			++YYCURSOR;
#line 180 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BRACKET_CLOSE;
			return 0;
		}
#line 388 "src/parser/scanner.c"
yy33:
			++YYCURSOR;
#line 186 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SBRACKET_OPEN;
			return 0;
		}
#line 397 "src/parser/scanner.c"
yy35:
			++YYCURSOR;
#line 192 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SBRACKET_CLOSE;
			return 0;
		}
#line 406 "src/parser/scanner.c"
yy37:
			++YYCURSOR;
#line 198 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_AT;
			return 0;
		}
#line 415 "src/parser/scanner.c"
yy39:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy116;
			default:	goto yy40;
			}
yy40:
#line 204 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_NOT;
			return 0;
		}
#line 429 "src/parser/scanner.c"
yy41:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '&':	goto yy114;
			default:	goto yy42;
			}
yy42:
#line 228 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_AND;
			return 0;
		}
#line 443 "src/parser/scanner.c"
yy43:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '|':	goto yy112;
			default:	goto yy44;
			}
yy44:
#line 234 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_OR;
			return 0;
		}
#line 457 "src/parser/scanner.c"
yy45:
			++YYCURSOR;
#line 240 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_BITWISE_XOR;
			return 0;
		}
#line 466 "src/parser/scanner.c"
yy47:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '<':	goto yy110;
			case '=':	goto yy108;
			default:	goto yy48;
			}
yy48:
#line 336 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_LESS;
			return 0;
		}
#line 481 "src/parser/scanner.c"
yy49:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy104;
			case '>':	goto yy106;
			default:	goto yy50;
			}
yy50:
#line 342 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_GREATER;
			return 0;
		}
#line 496 "src/parser/scanner.c"
yy51:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy100;
			case '>':	goto yy98;
			default:	goto yy52;
			}
yy52:
#line 258 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ASSIGN;
			return 0;
		}
#line 511 "src/parser/scanner.c"
yy53:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '+':	goto yy94;
			case '=':	goto yy96;
			default:	goto yy54;
			}
yy54:
#line 372 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ADD;
			return 0;
		}
#line 526 "src/parser/scanner.c"
yy55:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy92;
			default:	goto yy56;
			}
yy56:
#line 384 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MUL;
			return 0;
		}
#line 540 "src/parser/scanner.c"
yy57:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy90;
			default:	goto yy58;
			}
yy58:
#line 390 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DIV;
			return 0;
		}
#line 554 "src/parser/scanner.c"
yy59:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy88;
			default:	goto yy60;
			}
yy60:
#line 396 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MOD;
			return 0;
		}
#line 568 "src/parser/scanner.c"
yy61:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '.':	goto yy82;
			case '=':	goto yy84;
			default:	goto yy62;
			}
yy62:
#line 366 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DOT;
			return 0;
		}
#line 583 "src/parser/scanner.c"
yy63:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case ':':	goto yy80;
			default:	goto yy64;
			}
yy64:
#line 426 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_COLON;
			return 0;
		}
#line 597 "src/parser/scanner.c"
yy65:
			++YYCURSOR;
#line 432 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DOTCOMMA;
			return 0;
		}
#line 606 "src/parser/scanner.c"
yy67:
			++YYCURSOR;
#line 438 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_COMMA;
			return 0;
		}
#line 615 "src/parser/scanner.c"
yy69:
			++YYCURSOR;
#line 444 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_QUESTION;
			return 0;
		}
#line 624 "src/parser/scanner.c"
yy71:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy79;
yy72:
#line 450 "src/parser/scanner.re"
			{
			s->active_char += (YYCURSOR - start);
			token->opcode = MK_T_IGNORE;
			return 0;
		}
#line 636 "src/parser/scanner.c"
yy73:
			++YYCURSOR;
#line 456 "src/parser/scanner.re"
			{
			s->active_line++;
			s->active_char = 0;
			token->opcode = MK_T_IGNORE;
			return 0;
		}
#line 646 "src/parser/scanner.c"
yy75:
			++YYCURSOR;
#line 463 "src/parser/scanner.re"
			{
			status = MK_SCANNER_RETCODE_EOF;
			break;
		}
#line 654 "src/parser/scanner.c"
yy77:
			yych = *++YYCURSOR;
			goto yy18;
yy78:
			++YYCURSOR;
			yych = *YYCURSOR;
yy79:
			switch (yych) {
			case '\t':
			case '\r':
			case ' ':	goto yy78;
			default:	goto yy72;
			}
yy80:
			++YYCURSOR;
#line 360 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DOUBLECOLON;
			return 0;
		}
#line 676 "src/parser/scanner.c"
yy82:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '.':	goto yy86;
			default:	goto yy83;
			}
yy83:
#line 414 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_INCLUSIVE_RANGE;
			return 0;
		}
#line 690 "src/parser/scanner.c"
yy84:
			++YYCURSOR;
#line 294 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_CONCATASSIGN;
			return 0;
		}
#line 699 "src/parser/scanner.c"
yy86:
			++YYCURSOR;
#line 420 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_EXCLUSIVE_RANGE;
			return 0;
		}
#line 708 "src/parser/scanner.c"
yy88:
			++YYCURSOR;
#line 288 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MODASSIGN;
			return 0;
		}
#line 717 "src/parser/scanner.c"
yy90:
			++YYCURSOR;
#line 282 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_DIVASSIGN;
			return 0;
		}
#line 726 "src/parser/scanner.c"
yy92:
			++YYCURSOR;
#line 276 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_MULASSIGN;
			return 0;
		}
#line 735 "src/parser/scanner.c"
yy94:
			++YYCURSOR;
#line 402 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_INCR;
			return 0;
		}
#line 744 "src/parser/scanner.c"
yy96:
			++YYCURSOR;
#line 264 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_ADDASSIGN;
			return 0;
		}
#line 753 "src/parser/scanner.c"
yy98:
			++YYCURSOR;
#line 354 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DOUBLEARROW;
			return 0;
		}
#line 762 "src/parser/scanner.c"
yy100:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy102;
			default:	goto yy101;
			}
yy101:
#line 300 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_EQUALS;
			return 0;
		}
#line 776 "src/parser/scanner.c"
yy102:
			++YYCURSOR;
#line 312 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_IDENTICAL;
			return 0;
		}
#line 785 "src/parser/scanner.c"
yy104:
			++YYCURSOR;
#line 330 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_GREATEREQUAL;
			return 0;
		}
#line 794 "src/parser/scanner.c"
yy106:
			++YYCURSOR;
#line 252 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTRIGHT;
			return 0;
		}
#line 803 "src/parser/scanner.c"
yy108:
			++YYCURSOR;
#line 324 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_LESSEQUAL;
			return 0;
		}
#line 812 "src/parser/scanner.c"
yy110:
			++YYCURSOR;
#line 246 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_BITWISE_SHIFTLEFT;
			return 0;
		}
#line 821 "src/parser/scanner.c"
yy112:
			++YYCURSOR;
#line 222 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_OR;
			return 0;
		}
#line 830 "src/parser/scanner.c"
yy114:
			++YYCURSOR;
#line 216 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_AND;
			return 0;
		}
#line 839 "src/parser/scanner.c"
yy116:
			++YYCURSOR;
			switch ((yych = *YYCURSOR)) {
			case '=':	goto yy118;
			default:	goto yy117;
			}
yy117:
#line 306 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_NOTEQUALS;
			return 0;
		}
#line 853 "src/parser/scanner.c"
yy118:
			++YYCURSOR;
#line 318 "src/parser/scanner.re"
			{
			s->active_char += 3;
			token->opcode = MK_T_NOTIDENTICAL;
			return 0;
		}
#line 862 "src/parser/scanner.c"
yy120:
			++YYCURSOR;
			yych = *YYCURSOR;
yy121:
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
			case 'z':	goto yy120;
			default:	goto yy8;
			}
yy122:
			++YYCURSOR;
			yych = *YYCURSOR;
yy123:
			switch (yych) {
			case 0x00:	goto yy124;
			case '"':	goto yy126;
			case '\\':	goto yy125;
			default:	goto yy122;
			}
yy124:
			YYCURSOR = YYMARKER;
			switch (yyaccept) {
			case 0: 	goto yy5;
			case 1: 	goto yy18;
			default:	goto yy20;
			}
yy125:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy124;
			default:	goto yy122;
			}
yy126:
			++YYCURSOR;
#line 142 "src/parser/scanner.re"
			{
			token->opcode = MK_T_STRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 969 "src/parser/scanner.c"
yy128:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case 0x00:	goto yy124;
			case '"':	goto yy131;
			case '\\':	goto yy130;
			default:	goto yy128;
			}
yy130:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy124;
			default:	goto yy128;
			}
yy131:
			++YYCURSOR;
#line 132 "src/parser/scanner.re"
			{
			token->opcode = MK_T_ISTRING;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 997 "src/parser/scanner.c"
yy133:
			++YYCURSOR;
			yych = *YYCURSOR;
yy134:
			switch (yych) {
			case 0x00:	goto yy124;
			case '\'':	goto yy136;
			case '\\':	goto yy135;
			default:	goto yy133;
			}
yy135:
			++YYCURSOR;
			yych = *YYCURSOR;
			switch (yych) {
			case '\n':	goto yy124;
			default:	goto yy133;
			}
yy136:
			++YYCURSOR;
#line 122 "src/parser/scanner.re"
			{
			token->opcode = MK_T_CHAR;
			token->value = strndup(q, YYCURSOR - q - 1);
			token->len = YYCURSOR - q - 1;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 1026 "src/parser/scanner.c"
yy138:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'I':
			case 'i':	goto yy139;
			default:	goto yy121;
			}
yy139:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy140;
			default:	goto yy121;
			}
yy140:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy141;
			default:	goto yy121;
			}
yy141:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy142;
			default:	goto yy121;
			}
yy142:
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
			case 'z':	goto yy120;
			default:	goto yy143;
			}
yy143:
#line 115 "src/parser/scanner.re"
			{
			s->active_char += sizeof("exists")-1;
			token->opcode = MK_T_EXISTS;
			return 0;
		}
#line 1131 "src/parser/scanner.c"
yy144:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy149;
			default:	goto yy121;
			}
yy145:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy146;
			default:	goto yy121;
			}
yy146:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'P':
			case 'p':	goto yy147;
			default:	goto yy121;
			}
yy147:
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
			case 'z':	goto yy120;
			default:	goto yy148;
			}
yy148:
#line 103 "src/parser/scanner.re"
			{
			s->active_char += sizeof("drop")-1;
			token->opcode = MK_T_DROP;
			return 0;
		}
#line 1229 "src/parser/scanner.c"
yy149:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy150;
			default:	goto yy121;
			}
yy150:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'B':
			case 'b':	goto yy151;
			default:	goto yy121;
			}
yy151:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy152;
			default:	goto yy121;
			}
yy152:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy153;
			default:	goto yy121;
			}
yy153:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy154;
			default:	goto yy121;
			}
yy154:
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
			case 'z':	goto yy120;
			default:	goto yy155;
			}
yy155:
#line 97 "src/parser/scanner.re"
			{
			s->active_char += sizeof("database")-1;
			token->opcode = MK_T_DATABASE;
			return 0;
		}
#line 1341 "src/parser/scanner.c"
yy156:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy157;
			default:	goto yy121;
			}
yy157:
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
			case 'z':	goto yy120;
			default:	goto yy158;
			}
yy158:
#line 91 "src/parser/scanner.re"
			{
			s->active_char += sizeof("use")-1;
			token->opcode = MK_T_USE;
			return 0;
		}
#line 1425 "src/parser/scanner.c"
yy159:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy166;
			default:	goto yy121;
			}
yy160:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy161;
			default:	goto yy121;
			}
yy161:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'A':
			case 'a':	goto yy162;
			default:	goto yy121;
			}
yy162:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy163;
			default:	goto yy121;
			}
yy163:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy164;
			default:	goto yy121;
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
			case 'z':	goto yy120;
			default:	goto yy165;
			}
yy165:
#line 79 "src/parser/scanner.re"
			{
			s->active_char += sizeof("create")-1;
			token->opcode = MK_T_CREATE;
			return 0;
		}
#line 1537 "src/parser/scanner.c"
yy166:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy167;
			default:	goto yy121;
			}
yy167:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy168;
			default:	goto yy121;
			}
yy168:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'C':
			case 'c':	goto yy169;
			default:	goto yy121;
			}
yy169:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy170;
			default:	goto yy121;
			}
yy170:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'I':
			case 'i':	goto yy171;
			default:	goto yy121;
			}
yy171:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy172;
			default:	goto yy121;
			}
yy172:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'N':
			case 'n':	goto yy173;
			default:	goto yy121;
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
			case 'z':	goto yy120;
			default:	goto yy174;
			}
yy174:
#line 85 "src/parser/scanner.re"
			{
			s->active_char += sizeof("collection")-1;
			token->opcode = MK_T_COLLECTION;
			return 0;
		}
#line 1663 "src/parser/scanner.c"
yy175:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy176;
			default:	goto yy121;
			}
yy176:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'U':
			case 'u':	goto yy177;
			default:	goto yy121;
			}
yy177:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy178;
			default:	goto yy121;
			}
yy178:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy179;
			default:	goto yy121;
			}
yy179:
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
			case 'z':	goto yy120;
			default:	goto yy180;
			}
yy180:
#line 73 "src/parser/scanner.re"
			{
			s->active_char += sizeof("values")-1;
			token->opcode = MK_T_VALUES;
			return 0;
		}
#line 1768 "src/parser/scanner.c"
yy181:
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
			case 'z':	goto yy120;
			default:	goto yy182;
			}
yy182:
#line 109 "src/parser/scanner.re"
			{
			s->active_char += sizeof("if")-1;
			token->opcode = MK_T_IF;
			return 0;
		}
#line 1845 "src/parser/scanner.c"
yy183:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy184;
			case 'T':
			case 't':	goto yy185;
			default:	goto yy121;
			}
yy184:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy188;
			default:	goto yy121;
			}
yy185:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'O':
			case 'o':	goto yy186;
			default:	goto yy121;
			}
yy186:
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
			case 'z':	goto yy120;
			default:	goto yy187;
			}
yy187:
#line 67 "src/parser/scanner.re"
			{
			s->active_char += sizeof("into")-1;
			token->opcode = MK_T_INTO;
			return 0;
		}
#line 1945 "src/parser/scanner.c"
yy188:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'R':
			case 'r':	goto yy189;
			default:	goto yy121;
			}
yy189:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'T':
			case 't':	goto yy190;
			default:	goto yy121;
			}
yy190:
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
			case 'z':	goto yy120;
			default:	goto yy191;
			}
yy191:
#line 61 "src/parser/scanner.re"
			{
			s->active_char += sizeof("insert")-1;
			token->opcode = MK_T_INSERT;
			return 0;
		}
#line 2036 "src/parser/scanner.c"
yy192:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'U':
			case 'u':	goto yy193;
			default:	goto yy121;
			}
yy193:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy194;
			default:	goto yy121;
			}
yy194:
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
			case 'z':	goto yy120;
			default:	goto yy195;
			}
yy195:
#line 55 "src/parser/scanner.re"
			{
			s->active_char += sizeof("true")-1;
			token->opcode = MK_T_TRUE;
			return 0;
		}
#line 2127 "src/parser/scanner.c"
yy196:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy197;
			default:	goto yy121;
			}
yy197:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'S':
			case 's':	goto yy198;
			default:	goto yy121;
			}
yy198:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'E':
			case 'e':	goto yy199;
			default:	goto yy121;
			}
yy199:
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
			case 'z':	goto yy120;
			default:	goto yy200;
			}
yy200:
#line 49 "src/parser/scanner.re"
			{
			s->active_char += sizeof("false")-1;
			token->opcode = MK_T_FALSE;
			return 0;
		}
#line 2225 "src/parser/scanner.c"
yy201:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy202;
			default:	goto yy121;
			}
yy202:
			yych = *++YYCURSOR;
			switch (yych) {
			case 'L':
			case 'l':	goto yy203;
			default:	goto yy121;
			}
yy203:
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
			case 'z':	goto yy120;
			default:	goto yy204;
			}
yy204:
#line 43 "src/parser/scanner.re"
			{
			s->active_char += sizeof("null")-1;
			token->opcode = MK_T_NULL;
			return 0;
		}
#line 2316 "src/parser/scanner.c"
yy205:
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
			case '9':	goto yy208;
			default:	goto yy124;
			}
yy206:
			yyaccept = 0;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy207:
			switch (yych) {
			case '.':	goto yy205;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy206;
			default:	goto yy5;
			}
yy208:
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
			case '9':	goto yy208;
			default:	goto yy210;
			}
yy210:
#line 34 "src/parser/scanner.re"
			{
			token->opcode = MK_T_DOUBLE;
			token->value = strndup(start, YYCURSOR - start);
			token->len = YYCURSOR - start;
			s->active_char += (YYCURSOR - start);
			q = YYCURSOR;
			return 0;
		}
#line 2377 "src/parser/scanner.c"
yy211:
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
			case 'f':	goto yy212;
			default:	goto yy124;
			}
yy212:
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
			case 'f':	goto yy212;
			default:	goto yy5;
			}
yy214:
			++YYCURSOR;
#line 408 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_DECR;
			return 0;
		}
#line 2441 "src/parser/scanner.c"
yy216:
			++YYCURSOR;
#line 348 "src/parser/scanner.re"
			{
			s->active_char += 2;
			token->opcode = MK_T_ARROW;
			return 0;
		}
#line 2450 "src/parser/scanner.c"
yy218:
			++YYCURSOR;
#line 270 "src/parser/scanner.re"
			{
			s->active_char++;
			token->opcode = MK_T_SUBASSIGN;
			return 0;
		}
#line 2459 "src/parser/scanner.c"
yy220:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			switch (yych) {
			case 'x':	goto yy211;
			default:	goto yy207;
			}
		}
#line 473 "src/parser/scanner.re"

	}

	return status;
}
