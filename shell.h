#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define command_len 1024

extern char **environ;

int _putchar(char c);

char *_strtok(char *str, const char *delim);

char *_strchr(char *str, int c);

char *_strdup(char *str);

void execute_external_cmd(char *cmd);

void execute_cmd(char *name);

int tokenizer(char *command, const char *delim, char *tokens[]);

#endif
