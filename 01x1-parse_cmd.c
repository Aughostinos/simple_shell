#include "main.h"

/**
 * parse_cmd - Parses the command and removes the newline character
 * @cmd: Command string
 *
 * Return: Pointer to the parsed command
 */
char *parse_cmd(char *cmd)
{
	char *newline = strchr(cmd, '\n');
	if (newline)
		*newline = '\0'; /* Remove newline at the end */
	return cmd;
}

