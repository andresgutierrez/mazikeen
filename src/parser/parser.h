
#ifndef MK_PARSER_H
#define MK_PARSER_H

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

typedef struct _mk_ast_node {
	int type;
	char *value;
	int len;
	struct _mk_ast_node *n0;
	struct _mk_ast_node *n1;
	struct _mk_ast_node *n2;
	struct _mk_ast_node *n3;
} mk_ast_node;

typedef struct _mk_parser_status {
	int status;
	mk_ast_node *ret;
	mk_scanner_state *scanner_state;
	mk_scanner_token *token;
	char *syntax_error;
	unsigned int syntax_error_len;
	unsigned int number_brackets;
} mk_parser_status;

#define MK_PARSING_OK 1
#define MK_PARSING_FAILED 0

#define SUCCESS 1
#define FAILURE 0

#define MK_AST_T_INSERT 0
#define MK_AST_T_LIST 1
#define MK_AST_T_CREATE_COLL 2

mk_ast_node *mk_parse_command(char *program, size_t program_length, char *file_path, char **error_msg);
int mk_get_token(mk_scanner_state *state, mk_scanner_token *token);

#endif
