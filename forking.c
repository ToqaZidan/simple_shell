#include "shell.h"

/**
 * makchild - A function that creates a sub-process.
 * @cmd: The pointer to tokenized command.
 * @name: The pointer to shell name.
 * @env: The pointer to enviromental variables.
 * @cycles: Number of cycles executed.
 * Return: Nothing.
 */
void makchild(char **cmd, char *name, char **env, int cycles)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free(cmd);
	}
	else if (pid == 0)
	{
		execute(data_of_program *data);
		execute(cmd, name, env, cycles);
	/* you should use this in your function declaration */

		free(cmd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free(cmd);
		}
		free(cmd);
	}
}
