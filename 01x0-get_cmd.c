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
	ssize_t nread;

	nread = getline(&cmd, &len, stdin);
	if (nread == -1)
	{
	if (feof(stdin))
	{
		/* End of file*/
		free(cmd);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("get command");
		exit(EXIT_FAILURE);
	}
	}


	return (cmd);
}
