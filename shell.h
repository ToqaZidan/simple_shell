#ifndef _SHELL_H_
#define _SHELL_H_
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
  * struct builtins - struct for the builtins
  * @builtin: the name of the builtin
  * @function: the associated function to be called for each builtin
  */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

/*======== execute.c ========*/

/* Execute a command with its entire path */
int execute(data_of_program *data);

/*======== builtins_list.c ========*/

/* If match a builtin, executes it */
int builtins_list(data_of_program *data);


/*======== find_in_path.c ========*/

/* Creates an array of the path directories */
char **tokenize_path(data_of_program *data);

/* Search for program in path */
int find_program(data_of_program *data);

/*======== builtins_env.c ========*/

/* Shows the environment where the shell runs */
int builtin_env(data_of_program *data);

/* create or override a variable of environment */
int builtin_set_env(data_of_program *data);

/* delete a variable of environment */
int builtin_unset_env(data_of_program *data);


/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/


/*======== env_management.c ========*/

/* Gets the value of an environment variable */
char *env_get_key(char *name, data_of_program *data);

/* Overwrite the value of the environment variable */
int env_set_key(char *key, char *value, data_of_program *data);

/* Remove a key from the environment */
int env_remove_key(char *key, data_of_program *data);

/* prints the current environ */
void print_environ(data_of_program *data);
/*======== handle_print.c ========*/

/* Prints a string in the standar output */
int _print(char *string);

/* Prints a string in the standar error */
int _printe(char *string);

/* Prints a string in the standar error */
int _print_error(int errorcode, data_of_program *data);

char *str_duplicate(char *string);

/* SHELL INTIALIZATION FUNCTION PROTOTYPES */
int main(int ac, char **av, char **env);
void prompt(void);
void EOFF(char *buffer);
void quitsh(char **cmd);


/* MAKE NEW CHILD PROCESS FUNCTION PROTOTYPES */
void makchild(char **cmd, char *name, char **env, int cycles);


/* COMMAND TOKENAZIATION FUNCTION PROTOTYPES */
char **_strrtok(char *buffer, const char *s);
char *_strtok(char *line, char *delim);

/* HELPER FUNCTION PROTOTYPES */
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _atoi(char *str);
char *_strcat(char *dest, char *src);
char *str_duplicate(char *string);

/* EXECUTION AN HANDLING PATH */
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);


/* FREE MEMORY FUNCTION PROTOTYPES*/
void free_memo(char **cmd);
void exfree(char **cmd);

#endif
