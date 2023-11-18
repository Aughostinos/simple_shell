#include "main.h"
/**
 * exe_cmd - Executes a command
 * @cmd: Command to execute
 */
void exe_cmd(char **argv)
{
	char *cmd = NULL;

	argv[0] = cmd;

	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Exexution Error");
	}
}

