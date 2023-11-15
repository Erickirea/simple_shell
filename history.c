#include "shell.h"

/**
 * history - write file with user inputs
 * @input: user input
 * Return: 0 on success, otherwise -1 if error
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!input || !filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
	{
	perror("open");
		return (-1);
	}
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
		{
			perror("write");
			return (-1);
	}
	return (1);
}

/**
 * parser - Separates command recieved from stdin by ;
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as commands
 */
char **parser(char *input)
{
	char **commands;
	char *command;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * buffsize);
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	command = _strtok(input, ";&");
	for (i = 0; command; i++)
	{
		commands[i] = command;
		command = _strtok(NULL, ";&");
	}
	commands[i] = NULL;

	return (commands);
}
