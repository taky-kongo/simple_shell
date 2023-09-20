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
