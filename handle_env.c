#include "shell.h"

int str_compare(char *string1, char *string2, int number);
/**
  * env_get_key - gets the value of an environment variable
  * @key: the environment variable of interest
  * @data: struct of the program's data
  * Return: a pointer to the value of the variable or NULL if it doesn't exist
  */
char *env_get_key(char *key, data_of_program *data)
{
	int i, key_length = 0;

	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (NULL);
	key_length = _strlen(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		data->env[i][key_length] == '=')
		{
			return (data->env[i] + key_length + 1);
		}
	}
	return (NULL);
}

/**
  * env_set_key - overwrite the value of the environment variable
  * or create it if does not exist.
  * @key: name of the variable to set
  * @value: new value
  * @data: struct of the program's data
  * Return: 1 if the parameters are NULL, 2 if there is an erroror 0 if sucess.
  */
int env_set_key(char *key, char *value, data_of_program *data)
{
	int i, key_length = 0, is_new_key = 1;
	/* validate the arguments */
	if (key == NULL || value == NULL || data->env == NULL)
		return (1);
	key_length = _strlen(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		data->env[i][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[i]);
			break;
		}
	}
		data->env[i] = _strcat(str_duplicate(key), "=");
		data->env[i] = _strcat(data->env[i], value);
		if (is_new_key)
		{
			data->env[i + 1] = NULL;
		}
		return (0);
}
/**
  * env_remove_key - remove a key from the environment
  * @key: the key to remove
  * @data: the sructure of the program's data
  * Return: 1 if the key was removed, 0 if the key does not exist;
  */

int env_remove_key(char *key, data_of_program *data)
{
	int i, key_length = 0;
	/* validate the arguments */
	if (key == NULL || data->env == NULL)
		return (0);

	/* obtains the leng of the variable requested */
	key_length = _strlen(key);
	for (i = 0; data->env[i]; i++)
	{
		if (str_compare(key, data->env[i], key_length) &&
		 data->env[i][key_length] == '=')
		{
			free(data->env[i]);
			i++;
			for (; data->env[i]; i++)
			{
				data->env[i - 1] = data->env[i];
			}
			data->env[i - 1] = NULL;
			return (1);
		}
	}
	return (0);
}
/**
  * print_environ - prints the current environ
  * @data: struct for the program's data
  * Return: nothing
  */
void print_environ(data_of_program *data)
{
	int j;

	for (j = 0; data->env[j]; j++)
	{
		_print(data->env[j]);
		_print("\n");
	}
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
	else
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}
