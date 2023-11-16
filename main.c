#include "main.h"

/**
 * main - Entry point to simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *cmd;
	char *parsed_cmd;
	pid_t pid;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		cmd = get_cmd();

	parsed_cmd = parse_cmd(cmd);
	if (strlen(parsed_cmd) == 0)
	{
		free(cmd);
		continue;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		exe_cmd(parsed_cmd);
		exit(EXIT_FAILURE); /* execve only returns on error */
	}
	else if (pid > 0)
	{
		/* Parent process */
		wait(NULL); /* Wait for the child process to complete */
	}
	else
	{
		/* Fork failed */
		perror("Fork failed");
	}

	free(cmd);
	}

	return (0);
}

