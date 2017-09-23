
#include "../mk.h"

void mk_create_coll(mk_ast_node *node)
{
    char *s = malloc(sizeof(char) * 256);
    snprintf(s, 256, "%s/%s/%s", MK_DATA_DIR, MK_DEFAULT_DB, node->value);
    fprintf(stderr, "%d %s %s\n", node->type, s, node->value);
    free(s);
}
