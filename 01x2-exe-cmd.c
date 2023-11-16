#include "main.h"
/**
 * exe_cmd - Executes a command
 * @cmd: Command to execute
 */
void exe_cmd(char *cmd)
{
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Exexution Error");
	}
}

