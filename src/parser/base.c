
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
