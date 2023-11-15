#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* first task */
void display_prompt(void);
char *read_command(void);
char *parse_command(char *cmd);
void execute_command(char *cmd);

#endif
