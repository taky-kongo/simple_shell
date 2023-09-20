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

/**
 * fill_args - Fill an args_list with every input typed by the user
 * @input: String with the input
 * @args_list: args_list to be filled
 *
 * Return: Length of the args_list
 */
int fill_args(char *input, char **args_list)
{
	int i = 0;
	char *options, *aux = input, *command;

	command = _strtok(input, "\n\t\r ");
	args_list[i] = command;
	while (aux != NULL)
	{
		++i;
		options = _strtok(NULL, "\n\t\r ");
		aux = options;
		args_list[i] = options;
	}
	args_list[i] = NULL;
	return (i);
}
