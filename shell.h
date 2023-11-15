#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;

int _putchar(char c);

char *_strdup(char *str);

size_t find_newline(const char *str);

void _puts(char *str);

int _strcmp(char *s1, char *s2);

void execute_external_cmd(char *cmd);

char *get_env(char *name);

void execute_cmd(char *name);

int tokenizer(char *command, const char *delim, char *tokens[]);

#endif
