#include "main.h"

/**
 * _strtok - Function that splits the string in tokens
 * @str: a string to be splitted
 * @separator: char separator
 *
 * Return: a token
 */
char *_strtok(char *str, const char *separator)
{
	static char *a;
	char *token = NULL;

	if (!str)
	{
		str = a;
		if (!str)
			return (NULL);
	}
	str += strspn(str, separator);
	if (!*str)
	{
		a = NULL;
		return (NULL);
	}
	token = str;
	str = strpbrk(token, separator);
	if (str)
	{
		*str = '\0';
		a = str + 1;
	}
	else
		a = NULL;
	return (token);
}
