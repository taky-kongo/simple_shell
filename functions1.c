#include "main.h"

/**
 * _getenv - Get the content of a global variable
 * @env_var: Variable to extract from environ
 *
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *_getenv(char *env_var)
{
	int i = 0;
	const char cutter[] = "=";
	char *env_tok, *envdup, *env_tok_dup;

	if (env_var != NULL)
	{
		if (environ == NULL)
			return (NULL);
		envdup = _strdup(environ[i]);
		while (envdup != NULL)
		{
			env_tok = strtok(envdup, cutter);
			if (_strcmp(env_tok, env_var) == 0)
			{
				env_tok = strtok(NULL, cutter);
				env_tok_dup = _strdup(env_tok);
				free(envdup);
				return (env_tok_dup);
			}
			i++;
			free(envdup);
			envdup = _strdup(environ[i]);
		}
	}
	return (NULL);
}

/**
 * cmd_not_found - print no found if not command
 * @args: an array of args
 * @counter: Times that the shell has been executed
 *
 * Return: Exit status
 */
int cmd_not_found(char **args, int counter)
{
	if (isatty(STDIN_FILENO))
		_puts("hsh");
	else
		_puts("./hsh");
	printf(": %d: %s: not found\n", counter, args[0]);
	return (-1);
}

/**
 * handle_path - Verify if the first command can be executed
 * @args: Array of entries by the user
 *
 * Return: 0 if success, or -1 if the exe file doesn't exit
 */
int handle_path(char **args)
{
	char *PATH = NULL, *PATH_aux = NULL, *dir_path = NULL, *cmd_path = NULL;
	char *test_cph[121];
	int exist_status = -1, i = 0;

	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);
	PATH_aux = (_strdup(PATH));
	dir_path = strtok(PATH_aux, ":");
	if (dir_path == NULL)
		return (-1);
	free(PATH);
	while (exist_status == -1 && dir_path != NULL)
	{
		cmd_path = concat_cmd(dir_path, args[0]);
		test_cph[i] = cmd_path;
		exist_status = is_exist_file(test_cph[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;
	free(PATH_aux);
	free_grid(test_cph, i);
	if (exist_status == 0)
	{
		args[0] = test_cph[i];
		return (0);
	}
	else
	{
		free(test_cph[i]);
		return (-1);
	}
}
