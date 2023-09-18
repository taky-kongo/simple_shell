#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**macros**/
#define BUFFSIZE 32
#define BUFFER_LEN 20

/**environnement**/
extern char **environ;

#endif
