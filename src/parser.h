
#define MK_AST_T_INSERT 0
#define MK_AST_T_LIST 1
#define MK_AST_T_CREATE_COLL 2

mk_ast_node *mk_parse_command(char *program, size_t program_length, char *file_path, char **error_msg);
