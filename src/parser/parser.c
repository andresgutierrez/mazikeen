/** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
#line 8 "language.lemon"

#include "language.inc.h"

#line 11 "language.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/*
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands.
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    mk_TOKENTYPE     is the data type used for minor tokens given
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is mk_TOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.
**    mk_ARG_SDECL     A static variable declaration for the %extra_argument
**    mk_ARG_PDECL     A parameter declaration for the %extra_argument
**    mk_ARG_STORE     Code to store %extra_argument into yypParser
**    mk_ARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 21
#define YYACTIONTYPE unsigned char
#define mk_TOKENTYPE mk_parser_token*
typedef union {
  mk_TOKENTYPE yy0;
  mk_ast_node* yy15;
  int yy41;
} YYMINORTYPE;
#define YYSTACKDEPTH 100
#define mk_ARG_SDECL mk_parser_status *status;
#define mk_ARG_PDECL ,mk_parser_status *status
#define mk_ARG_FETCH mk_parser_status *status = yypParser->status
#define mk_ARG_STORE yypParser->status = status
#define YYNSTATE 25
#define YYNRULE 11
#define YYERRORSYMBOL 11
#define YYERRSYMDT yy41
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
static YYACTIONTYPE yy_action[] = {
 /*     0 */    37,    1,    2,    3,   20,   10,    9,   21,   11,   14,
 /*    10 */    19,   24,    4,    7,   25,   26,   27,    8,   15,    5,
 /*    20 */    13,   28,    6,   12,   22,   17,   16,   23,   18,   29,
};
static YYCODETYPE yy_lookahead[] = {
 /*     0 */    12,   13,   14,   15,    6,    6,   16,    9,    9,   19,
 /*    10 */    17,   18,    1,    4,    0,    0,    0,    5,    7,    2,
 /*    20 */    10,    0,    3,   19,   18,    3,    8,    3,    5,    0,
};
#define YY_SHIFT_USE_DFLT (-3)
static signed char yy_shift_ofst[] = {
 /*     0 */    11,   14,   15,   16,   17,   19,    9,   12,   10,   -1,
 /*    10 */    21,   10,   -3,   -3,   -3,   18,   22,   23,   24,   -2,
 /*    20 */    29,   24,   -3,   -3,   -3,
};
#define YY_REDUCE_USE_DFLT (-13)
static signed char yy_reduce_ofst[] = {
 /*     0 */   -12,  -13,  -13,  -13,  -13,  -13,  -13,  -13,  -10,  -13,
 /*    10 */   -13,    4,  -13,  -13,  -13,  -13,  -13,  -13,   -7,  -13,
 /*    20 */   -13,    6,  -13,  -13,  -13,
};
static YYACTIONTYPE yy_default[] = {
 /*     0 */    36,   36,   36,   36,   36,   36,   36,   36,   36,   36,
 /*    10 */    36,   36,   33,   35,   34,   36,   36,   36,   36,   36,
 /*    20 */    36,   36,   30,   32,   31,
};
#define YY_SZ_ACTTAB (sizeof(yy_action)/sizeof(yy_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
**
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  YYMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
  int yyerrcnt;                 /* Shifts left before out of the error */
  mk_ARG_SDECL                /* A place to hold %extra_argument */
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/*
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void mk_Trace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *yyTokenName[] = {
  "$",             "INSERT",        "INTO",          "IDENTIFIER",  
  "VALUES",        "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "CREATE",      
  "COLLECTION",    "COMMA",         "INTEGER",       "error",       
  "mk_language",   "mk_command",    "mk_insert",     "mk_create_coll",
  "mk_values_list",  "mk_create_coll_field_list",  "mk_create_coll_field",  "mk_expr",     
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *yyRuleName[] = {
 /*   0 */ "mk_language ::= mk_command",
 /*   1 */ "mk_command ::= mk_insert",
 /*   2 */ "mk_command ::= mk_create_coll",
 /*   3 */ "mk_insert ::= INSERT INTO IDENTIFIER VALUES PARENTHESES_OPEN mk_values_list PARENTHESES_CLOSE",
 /*   4 */ "mk_create_coll ::= CREATE COLLECTION IDENTIFIER PARENTHESES_OPEN mk_create_coll_field_list PARENTHESES_CLOSE",
 /*   5 */ "mk_create_coll_field_list ::= mk_create_coll_field_list COMMA mk_create_coll_field",
 /*   6 */ "mk_create_coll_field_list ::= mk_create_coll_field",
 /*   7 */ "mk_create_coll_field ::= IDENTIFIER",
 /*   8 */ "mk_values_list ::= mk_values_list COMMA mk_expr",
 /*   9 */ "mk_values_list ::= mk_expr",
 /*  10 */ "mk_expr ::= INTEGER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *mk_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(yyTokenName)/sizeof(yyTokenName[0])) ){
    return yyTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/*
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to mk_ and mk_Free.
*/
void *mk_Alloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(YYCODETYPE yymajor, YYMINORTYPE *yypminor){
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor( yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/*
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from mk_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void mk_Free(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  /* if( pParser->yyidx<0 ) return YY_NO_ACTION;  */
  i = yy_shift_ofst[stateno];
  if( i==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
#ifdef YYFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
           && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
           yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
      }
#endif
      return yy_find_shift_action(pParser, iFallback);
    }
#endif
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  yyParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;

  i = yy_reduce_ofst[stateno];
  if( i==YY_REDUCE_USE_DFLT ){
    return yy_default[stateno];
  }
  if( iLookAhead==YYNOCODE ){
    return YY_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer ot the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
  if( yypParser->yyidx>=YYSTACKDEPTH ){
     mk_ARG_FETCH;
     yypParser->yyidx--;
#ifndef NDEBUG
     if( yyTraceFILE ){
       fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
     }
#endif
     while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     mk_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = yyNewState;
  yytos->major = yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 12, 1 },
  { 13, 1 },
  { 13, 1 },
  { 14, 7 },
  { 15, 6 },
  { 17, 3 },
  { 17, 1 },
  { 18, 1 },
  { 16, 3 },
  { 16, 1 },
  { 19, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  mk_ARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0
        && yyruleno<sizeof(yyRuleName)/sizeof(yyRuleName[0]) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0:
#line 18 "language.lemon"
{
	status->ret = yymsp[0].minor.yy15;
}
#line 546 "language.c"
        break;
      case 1:
      case 2:
#line 22 "language.lemon"
{
	yygotominor.yy15 = yymsp[0].minor.yy15;
}
#line 554 "language.c"
        break;
      case 3:
#line 30 "language.lemon"
{
	yygotominor.yy15 = mk_ret_insert(yymsp[-4].minor.yy0, yymsp[-1].minor.yy15);
}
#line 561 "language.c"
        break;
      case 4:
#line 34 "language.lemon"
{
	yygotominor.yy15 = mk_ret_create_coll(yymsp[-3].minor.yy0, yymsp[-1].minor.yy15);
}
#line 568 "language.c"
        break;
      case 5:
      case 8:
#line 38 "language.lemon"
{
	yygotominor.yy15 = mk_ret_list(yymsp[-2].minor.yy15, yymsp[0].minor.yy15);
}
#line 576 "language.c"
        break;
      case 6:
      case 9:
#line 42 "language.lemon"
{
	yygotominor.yy15 = mk_ret_list(yymsp[0].minor.yy15, NULL);
}
#line 584 "language.c"
        break;
      case 7:
#line 46 "language.lemon"
{
	yygotominor.yy15 = mk_ret_coll_field_def(yymsp[0].minor.yy0);
}
#line 591 "language.c"
        break;
      case 10:
#line 58 "language.lemon"
{
    yygotominor.yy15 = mk_ret_literal(MK_T_INTEGER, yymsp[0].minor.yy0);
}
#line 598 "language.c"
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yypParser,yygoto);
  if( yyact < YYNSTATE ){
    yy_shift(yypParser,yyact,yygoto,&yygotominor);
  }else if( yyact == YYNSTATE + YYNRULE + 1 ){
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  mk_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  mk_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  mk_ARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 12 "language.lemon"

	fprintf(stderr, "%s\n", status->scanner_state->start);
	status->status = MK_PARSING_FAILED;
	status->ret = NULL;

#line 646 "language.c"
  mk_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  mk_ARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  mk_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "mk_Alloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void mk_(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  mk_TOKENTYPE yyminor       /* The value for the token */
  mk_ARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
    if( yymajor==0 ) return;
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  mk_ARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,yymajor);
    if( yyact<YYNSTATE ){
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      if( yyendofinput && yypParser->yyidx>=0 ){
        yymajor = 0;
      }else{
        yymajor = YYNOCODE;
      }
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else if( yyact == YY_ERROR_ACTION ){
      int yymx;
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_shift_action(yypParser,YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }else{
      yy_accept(yypParser);
      yymajor = YYNOCODE;
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}

/**
 * Wrapper to alloc memory within the parser
 */
static void *mk_wrapper_alloc(size_t bytes)
{
	return malloc(bytes);
}

/**
 * Wrapper to free memory within the parser
 */
static void mk_wrapper_free(void *pointer)
{
	free(pointer);
}

/**
 * Creates a parser_token to be passed to the parser
 */
static void mk_parse_with_token(void* mk_parser, int opcode, int parsercode, mk_scanner_token *token, mk_parser_status *parser_status)
{
	mk_parser_token *pToken;

	pToken = malloc(sizeof(mk_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;

	mk_(mk_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

mk_ast_node *mk_parse_command(char *program, size_t program_length, char *file_path, char **error_msg)
{
	char *error;
	mk_scanner_state *state;
	mk_scanner_token token;
	int scanner_status, status = SUCCESS;
	mk_parser_status *parser_status = NULL;
	void* mk_parser;

	/**
	 * Start the reentrant parser
	 */
	mk_parser = mk_Alloc(mk_wrapper_alloc);

	parser_status = malloc(sizeof(mk_parser_status));
	state = malloc(sizeof(mk_scanner_state));

	parser_status->status = MK_PARSING_OK;
	parser_status->scanner_state = state;
	parser_status->ret = NULL;
	parser_status->token = &token;
	parser_status->syntax_error = NULL;
	parser_status->number_brackets = 0;

	/**
	 * Initialize the scanner state
	 */
	state->active_token = 0;
	state->start = program;
	state->start_length = 0;
	state->active_file = file_path;
	state->active_line = 1;
	state->active_char = 1;
	state->class_line = 0;
	state->class_char = 0;
	state->method_line = 0;
	state->method_char = 0;

	state->end = state->start;

	token.value = NULL;

	while (0 <= (scanner_status = mk_get_token(state, &token))) {

		state->active_token = token.opcode;

		state->start_length = (program + program_length - state->start);
		//fprintf(stderr, "%d\n", token.opcode);

		switch (token.opcode) {

			case MK_T_IGNORE:
				break;

			case MK_T_INSERT:
				mk_(mk_parser, MK_INSERT, NULL, parser_status);
				break;
			case MK_T_INTO:
				mk_(mk_parser, MK_INTO, NULL, parser_status);
				break;
			case MK_T_VALUES:
				mk_(mk_parser, MK_VALUES, NULL, parser_status);
				break;

			case MK_T_CREATE:
				mk_(mk_parser, MK_CREATE, NULL, parser_status);
				break;
			case MK_T_COLLECTION:
				mk_(mk_parser, MK_COLLECTION, NULL, parser_status);
				break;

			case MK_T_PARENTHESES_OPEN:
				mk_(mk_parser, MK_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case MK_T_PARENTHESES_CLOSE:
				mk_(mk_parser, MK_PARENTHESES_CLOSE, NULL, parser_status);
				break;
			case MK_T_COMMA:
				mk_(mk_parser, MK_COMMA, NULL, parser_status);
				break;

			case MK_T_INTEGER:
				mk_parse_with_token(mk_parser, MK_T_INTEGER, MK_INTEGER, &token, parser_status);
				break;
			/*case MK_T_DOUBLE:
				mk_parse_with_token(mk_parser, MK_T_DOUBLE, MK_DOUBLE, &token, parser_status);
				break;
			case MK_T_STRING:
				mk_parse_with_token(mk_parser, MK_T_STRING, MK_STRING, &token, parser_status);
				break;
			case MK_T_ISTRING:
				mk_parse_with_token(mk_parser, MK_T_ISTRING, MK_ISTRING, &token, parser_status);
				break;
			case MK_T_CHAR:
				mk_parse_with_token(mk_parser, MK_T_CHAR, MK_CHAR, &token, parser_status);
				break;*/
			case MK_T_IDENTIFIER:
				mk_parse_with_token(mk_parser, MK_T_IDENTIFIER, MK_IDENTIFIER, &token, parser_status);
				break;

			default:
				parser_status->status = MK_PARSING_FAILED;
				if (*error_msg == NULL) {
					int length = (48 + strlen(file_path));
					*error_msg = malloc(sizeof(char) * length);
					snprintf(*error_msg, length, "Scanner: unknown opcode %d on in %s line %d", token.opcode, file_path, state->active_line);
					fprintf(stderr, "%s\n", *error_msg);
				}
				break;
		}

		if (parser_status->status != MK_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {
			case MK_SCANNER_RETCODE_ERR:
			case MK_SCANNER_RETCODE_IMPOSSIBLE:
				if (*error_msg == NULL) {
					*error_msg = malloc(sizeof(char) * 1024);
					if (state->start) {
						snprintf(*error_msg, 1024, "Scanner error: %d %s", scanner_status, state->start);
					} else {
						snprintf(*error_msg, 1024, "Scanner error: %d", scanner_status);
					}
					fprintf(stderr, "%s\n", *error_msg);
					status = FAILURE;
				}
				break;
			default:
				mk_(mk_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != MK_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error && error_msg) {
			fprintf(stderr, "%s\n", "syntax error");
		}
	}

	if (status != FAILURE) {
		if (parser_status->status == MK_PARSING_OK) {
			mk_ast_node *root = malloc(sizeof(mk_ast_node));
			assert(parser_status->ret != NULL);
			memcpy(root, parser_status->ret, sizeof(mk_ast_node));
			return root;
		}
	}

	mk_Free(mk_parser, mk_wrapper_free);

	return NULL;
}