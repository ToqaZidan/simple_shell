#include "shell.h"

/*********** MAIN FUNCTION *********/
/**
 * main - A function that runs the shell.
 * @ac: The number of  arguments inputed.
 * @av: The pointer to array of  arguments inputed.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **cmd = NULL;
	size_t buf_size = 0;
	ssize_t nchar_readed = 0;
	int cycles = 0;
	(void)ac;

	while (1)
	{
		cycles++;
		prompt();
		nchar_readed = getline(&buffer, &buf_size, stdin);
		if (nchar_readed == EOF)
			EOFF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			cmd = _strtok(buffer, " \0");
			free(buffer);
			if (_strcmp(cmd[0], "exit") != 0)
				exfree(cmd);
				
			else if (_strcmp(cmd[0], "cd") != 0)
				change_dir(cmd[1]);

			else
				makchild(cmd, av[0], env, cycles);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (nchar_readed == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*********** PRINT PROMPT FUNCTION *********/
/**
 * prompt - A function that prints the prompt to user
 * Return: Nothing.
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Shell$ ", 7);
}



/*********** EOF HANDLING FUNCTION *********/
/**
 * EOFF - A function checks if buffer is END OF FILE (EOF)
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */

void EOFF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}


/*********** EXIT HANDLING FUNCTION *********/
/**
 * quitsh - A function exits or quit the shell.
 * @cmd: The pointer to tokenized cmd.
 * Return: Nothing.
 */

void quitsh(char **cmd)
{
	int state = 0;

	if (cmd[1] == NULL)
	{
		free_memo(cmd);
		exit(EXIT_SUCCESS);
	}

	state = _atoi(cmd[1]);
	free_memo(cmd);
	exit(state);
}

/**
 * handle - A function to handle Ctr + C signal.
 * @sigint: The signal to handle.
 * Return: Nothing.
 */
void handle(int sigint)
{
	(void)sigint;
	write(STDOUT_FILENO, "\nShell$ ", 8);
}
