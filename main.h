#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**macros**/
#define BUFFSIZE 32
#define BUFFER_LEN 20

/**environnement**/
extern char **environ;

/**tools.c**/
int _strcmp(const char *s1, const char *s2);
int _putchar(char c);
void _puts(char *str);
int _atoi(char *s);
char *_strdup(char *str);

/**tools1.c**/
int prompt(const char *prompt, unsigned int size);
i
#endif
