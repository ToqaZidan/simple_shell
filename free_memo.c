#include "shell.h"

/**
 * free_memo - A function that frees all the memory allocated for cmd.
 * @cmd: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_memo(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
}


/**
 * exfree - A function that frees all the memory allocated and exit.
 * @cmd: The pointer to allocated cmd memory to free.
 * Return: Nothing.
 */
void exfree(char **cmd)
{
	size_t i = 0;

	if (cmd == NULL)
		return;

	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}

	if (cmd[i] == NULL)
		free(cmd[i]);
	free(cmd);
	exit(EXIT_FAILURE);
}
