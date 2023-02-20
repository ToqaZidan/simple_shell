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
		execute(cmd, name, env, cycles);

		free_memo(cmd);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			exfree(cmd);
		}
		free_memo(cmd);
	}
}


/**
  * change_dir - function changes working directory.
  * @path: The new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
