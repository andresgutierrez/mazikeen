
#ifndef MK_H
#define MK_H

/* List of tokens and their names */
typedef struct _mk_token_names {
	unsigned int code;
	char *name;
} mk_token_names;

/* Active token state */
typedef struct _mk_scanner_state {
	int active_token;
	char* start;
	char* end;
	unsigned int start_length;
	int mode;
	unsigned int active_line;
	unsigned int active_char;
	unsigned int class_line;
	unsigned int class_char;
	unsigned int method_line;
	unsigned int method_char;
	char *active_file;
} mk_scanner_state;

/* Extra information tokens */
typedef struct _mk_scanner_token {
	int opcode;
	char *value;
	int len;
} mk_scanner_token;

typedef struct _mk_parser_token {
	int opcode;
	char *token;
	int token_len;
	int free_flag;
} mk_parser_token;

typedef struct _mk_parser_status {
	int status;
	mk_scanner_state *scanner_state;
	mk_scanner_token *token;
	char *syntax_error;
	unsigned int syntax_error_len;
	unsigned int number_brackets;
} mk_parser_status;

typedef struct _mk_ast_node {
	int type;
	struct _mk_ast_node *left;
	struct _mk_ast_node *right;
} mk_ast_node;

#define XX_PARSING_OK 1
#define XX_PARSING_FAILED 0

int mk_get_token(mk_scanner_state *state, mk_scanner_token *token);

#endif
