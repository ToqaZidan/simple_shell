#include "shell.h"

void str_reverse(char *string);
void long_to_string(long number, char *string, int base);

/**
  * _print - writes a array of chars in the standar output
  * @string: pointer to the array of chars
  * Return: the number of bytes writed or .
  * On error, -1 is returned, and errno is set appropriately.
  */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _strlen(string)));
}
/**
  * _printe - writes a array of chars in the standar error
  * @string: pointer to the array of chars
  * Return: the number of bytes writed or .
  * On error, -1 is returned, and errno is set appropriately.
  */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, _strlen(string)));
}
/**
  * _print_error - writes a array of chars in the standart error
  * @data: a pointer to the program's data'
  * @errorcode: error code to print
  * Return: the number of bytes writed or .
  * On error, -1 is returned, and errno is set appropriately.
  */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';
	if (string[0] == '-')
		inNegative = 1;
	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';
	string[index] = '\0';
	str_reverse(string);
}
void str_reverse(char *string)
{

	int i = 0, length = _strlen(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
/**
  * str_duplicate - duplicates an string
  * @string: String to be copied
  * Return: pointer to the array
  */
char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);
	length = _strlen(string) + 1;
	result = malloc(sizeof(char) * length);
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);	
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}
	return (result);
}
