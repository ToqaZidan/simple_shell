#include "shell.h"
/**
 * _atoi - a function that converts string to integer.
 * @str: An input string.
 * Return: integer from conversion.
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		if (*str >= '0' && *str <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*str - '0');
		}
		else if (*str < '0' || *str > '9')
		{
			if (null_flag == 1)
				break;
		}
		str++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
