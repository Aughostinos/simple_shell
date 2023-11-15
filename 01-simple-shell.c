#include "shell.h"

/**
 * display_prompt - Displays the command line prompt
 */
void display_prompt(void)
{
	printf("simple_shell> ");
}

/**
 * read_command - Reads a command from standard input
 *
 * Return: Pointer to the read command
 */
char *read_command(void)
{
	char *cmd = NULL;
	size_t len = 0;

	if (getline(&cmd, &len, stdin) == -1)
	{
	if (feof(stdin))
	{
 		/* End of file (Ctrl+D) */
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("readline");
		exit(EXIT_FAILURE);
	}
	}

	return cmd;
}

/**
 * parse_command - Parses the command and removes the newline character
 * @cmd: Command string
 *
 * Return: Pointer to the parsed command
 */
char *parse_command(char *cmd)
{
	char *newline = strchr(cmd, '\n');
	if (newline)
		*newline = '\0'; /* Remove newline at the end */
	return cmd;
}

/**
 * execute_command - Executes a given command
 * @cmd: Command to execute
 */
void execute_command(char *cmd)
{
	char *argv[2];

	argv[0] = cmd;
	argv[1] = NULL;

	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Error");
	}
}

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *cmd;
	char *parsed_cmd;
	pid_t pid;

	while (1)
	{
		display_prompt();
		cmd = read_command();

	parsed_cmd = parse_command(cmd);
	if (strlen(parsed_cmd) == 0)
	{
		free(cmd);
		continue;
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		execute_command(parsed_cmd);
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
