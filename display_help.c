#include "shell.h"

/**
 * dis_help - Display help messages for built-in commands
 * @builtin_name: Name of the built-in command.
 * Return: None
 */
int dis_help(const char *builtin_name)
{
	if (builtin_name == NULL)
	{
		write(STDOUT_FILENO, HELP_MSG, sizeof(HELP_MSG) - 1);
	}
	else if (strcmp(builtin_name, "cd") == 0)
	{
		write(STDOUT_FILENO, HELP_CD_MSG, sizeof(HELP_CD_MSG) - 1);
	}
	else if (strcmp(builtin_name, "exit") == 0)
	{
		write(STDOUT_FILENO, HELP_EXIT_MSG, sizeof(HELP_EXIT_MSG) - 1);
	}
	else if (strcmp(builtin_name, "env") == 0)
	{
		write(STDOUT_FILENO, HELP_ENV_MSG, sizeof(HELP_ENV_MSG) - 1);
	}
	else if (strcmp(builtin_name, "setenv") == 0)
	{
		write(STDOUT_FILENO, HELP_SETENV_MSG, sizeof(HELP_SETENV_MSG) - 1);
	}
	else if (strcmp(builtin_name, "unsetenv") == 0)
	{
		write(STDOUT_FILENO, HELP_UNSETENV_MSG, sizeof(HELP_UNSETENV_MSG) - 1);
	}
	else
	{
		write(STDERR_FILENO, "help: Builtin not found\n",
		sizeof("help: Builtin not found\n") - 1);
	}
	return (0);
}
