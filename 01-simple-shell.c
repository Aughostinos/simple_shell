#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - enty point to the program
 *
 * Return: 0 if succeed.
 */

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t readc;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

	readc = getline(&command, &len, stdin);
	if (readc == -1)
	{
		free(command);
		break;
	}

	/*Remove the newline character*/
	if (readc > 0 && command[readc - 1] == '\n')
	{
		command[readc - 1] = '\0';
	}


	/*create a child process*/
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		continue;
	}

	/*child process*/
	if (pid == 0)
	{
		/*Execute the command*/
		char *argv[] = {command, NULL};

		execve(command, argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	}

	return (0);
}
