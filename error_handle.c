#include "main.h"

/**
* printerr - print the error
* @error_info:  struct of the error
* @message: the type of error
*/
void printerr(error_h_t *error_info, const char *message)
{
	dprintf(STDERR_FILENO, "%s: %u: %s: %s\n", error_info->fname,
										error_info->line_count,
										error_info->argv[0],
										message);
}
