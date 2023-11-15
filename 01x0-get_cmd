#include "main.h"
/**
 * get_cmd - allow the user to write a command
 *
 * Return: Pointer to the command
 */
char *get_cmd(void)
{
	char *cmd = NULL;
	size_t len = 0;

	if (getline(&cmd, &len, stdin) == -1)
	{
	if (feof(stdin))
	{
 		/* End of file  */
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("get command");
		exit(EXIT_FAILURE);
	}
	}

	return cmd;
}

