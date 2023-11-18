#include "main.h"

int main(void)
{
	char *cmd = NULL, *cmd_cp = NULL, *token, **argv;
	size_t len = 0;
	ssize_t getcmd;
	int ntoken = 0;

	while (1)
	{
		printf("user $");
		getcmd = getline(&cmd, &len, stdin);
		if (getcmd == -1)
		{
			if (feof(stdin))
			{
				/* End of file  */
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

	/* allocate space for a copy of the cmd */
	cmd_cp = malloc(sizeof(char) * getcmd);
	if (cmd_cp == NULL)
	{
		perror(" memory allocation error");
		return (-1);
	}

	strcpy(cmd_cp, cmd);


	/* tokenizing */
	token = strtok(cmd, " ");

	while (token != NULL)
	{
		ntoken++;
		token = strtok(NULL, " ");
	}
	ntoken++;

	argv = malloc(sizeof(char *) * ntoken);

	/* Store tokens */
	token = strtok(cmd_cp, " ");

	for (int i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	execmd(argv);
	}
}
