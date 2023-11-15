#include "shell.h"

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_printe(PROMPT_MSG);
		_printe(" ");
	}
}

/**
 * process_input - Processes the user input
 * @input: User input
 * @count: Execution count
 * @argv: Argument vector
 * @stat: Exit status
 */
void process_input(char *input, int count, char **argv, int *stat)
{
	char **commands, **cmd;
	int i;

	if (input[0] == '\0')
		return;

	history(input);
	commands = parser(input);

	for (i = 0; commands[i] != NULL; i++)
	{
		cmd = parse_cmd(commands[i]);

		if (_strcmp(cmd[0], "exit") == 0)
		{
			free(commands);
			exit_bul(cmd, input, argv, count, *stat);
		}
		else if (check_builtin(cmd) == 0)
		{
			*stat = handle_builtin(cmd, *stat);
			free(cmd);
			continue;
		}
		else
		{
			*stat = find_cmd(cmd, input, count, argv);
		}

		free(cmd);
	}

	free(commands);
}

/**
 * run_shell - Main loop for the shell program
 * @argv: Argument vector
 * Return: Returns exit status
 */
int run_shell(char **argv)
{
	char *input;
	int count = 0, stat = 0;

	signal(SIGINT, signal_to_handle);

	while (1)
	{
		count++;

		display_prompt();
		input = _getline();
		process_input(input, count, argv, &stat);

		free(input);
		wait(&stat);
	}

	return (stat);
}

/**
 * main - Entry point to the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns exit status
 */
int main(int argc, char **argv)
{
	if (argc > 1)
		read_file(argv[1], argv);

	return (run_shell(argv));
}
