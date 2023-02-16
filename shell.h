#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>



/* SHELL INTIALIZATION FUNCTION PROTOTYPES */
int main(int ac, char **av, char **env);
void prompt(void);
void EOFF(char *buffer);
void quitsh(char **cmd);


/* MAKE NEW CHILD PROCESS FUNCTION PROTOTYPES */
void makchild(char **cmd, char *name, char **env, int cycles);


/* COMMAND TOKENAZIATION FUNCTION PROTOTYPES */
char **_strtok(char *buffer, const char *s);

/* HELPER FUNCTION PROTOTYPES */
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _atoi(char *str);
char *_strcat(char *dest, char *src);

/* EXECUTION AN HANDLING PATH AND ENV FUNCTION PROTOTYPES*/



/* FREE MEMORY FUNCTION PROTOTYPES*/
void free_memo(char **cmd);
void exfree(char **cmd);

#endif
