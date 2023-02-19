#include "shell.h"

/*********** MAIN FUNCTION *********/
/**
 * main - A function that runs the shell.
 * @ac: The number of  arguments inputed.
 * @av: The pointer to array of  arguments inputed.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */

int main(int ac, __attribute__ ((unused)) char **av,__attribute__ ((unused)) char **env)
{
	char *buffer = NULL, **cmd = NULL;
	size_t buf_size = 0;
	ssize_t nchar_readed = 0;
	int cycles = 0;
	data_of_program *data = NULL;
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
			cmd = _strrtok(buffer, " \0");
			free(buffer);
			if (_strcmp(cmd[0], "exit") != 0)
				exfree(cmd);

			else
				/*makchild(cmd, av[0], env, cycles);*/
				execute(data);
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
 * @cmd: The pointer to tokenized command.
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

/**----------------------------------------------------------------------*/
/**
  * main - initialize the variables of the program
  * @argc: number of values received from the command line
  * @argv: values received from the command line
  * @env: number of values received from the command line
  * Return: zero on succes.
  */
/**
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);
	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}
*/
/**
  * handle_ctrl_c - print the prompt in a new line
  * when the signal SIGINT (ctrl + c) is send to the program
  * @UNUSED: option of the prototype
  */
/*
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}
*/
/**
  * inicialize_data - inicialize the struct with the info of the program
  * @data: pointer to the structure of data
  * @argv: array of arguments pased to the program execution
  * @env: environ pased to the program execution
  * @argc: number of values received from the command line
  */
/**
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
*/
/**
  * sisifo - its a infinite loop that shows the prompt
  * @prompt: prompt to be printed
  * @data: its a infinite loop that shows the prompt
  */
/**
void sisifo(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
	}
}
*/
