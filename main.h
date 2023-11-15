#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* first task */
char *get_cmd(void);
char *parse_cmd(char *cmd);
void exe_cmd(char *cmd);

#endif

