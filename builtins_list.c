#include "shell.h"

 int str_compare(char *string1, char *string2, int number);

/**
  * builtins_list - search for match and execute the associate builtin
  * @data: struct for the program's data
  * Return: Returns the return of the function executed is there is a match,
  * otherwise returns -1.
  **/
int builtins_list(data_of_program *data)
{
	int iterator;

	builtins options[] = {
		{"env", builtin_env},
		{"setenv", builtin_set_env},
		{"unsetenv", builtin_unset_env},
		{NULL, NULL}
	};
/*walk through the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
		return (options[iterator].function(data));
		}
	}
	return (-1);
}
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);
	if (string1 == NULL || string2 == NULL)
		return (0);
	if (number == 0) /* infinite longitud */
	{
		if (_strlen(string1) != _strlen(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
}
