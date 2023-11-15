#include "shell.h"

/**
 * create_envi - Creates an array of Enviroment Variables
 * @environ: Array to store Enviroment Variables
 */

void create_envi(char **environ)
{
	int i;

	for (i = 0; environ[i]; i++)
		environ[i] = _strdup(environ[i]);
	environ[i] = NULL;
}

/**
 * free_env - Frees the memory of the created Enviroment Variables array
 * @env:  Array of Environment variables
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
