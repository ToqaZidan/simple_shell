#include "shell.h"

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


/**
 * _strlen - A function finds the length of the string
 * @str: The input string
 * Return: The length of the string
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * _strcmp - A funtion compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: 1 if strings are the same, 0 if not
 */
int _strcmp(char *str1, char *str2)
{
	unsigned int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}

	return (1);
}



/**
 * _strcpy - A function copies a string to another string
 * @dest: The pointer to the copyed string
 * @src: The pointer to string to copy for
 * Return: A pointer to copied string
 */

char *_strcpy(char *dest, char *src)
{
	char *n = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (n);
}



/**
 * _strcat - a function concatenates two strings.
 * @dest: an input string
 * @src: an input string
 * Return: A pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}
