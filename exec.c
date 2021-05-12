#include "monty.h"
int number;
/**
 * open_and_read -main entry.
 *Description:Function that open, read the file
 * @argv: arguments received by parameter
 * Return: void
 **/
void open_read(char **argv)
{
/* prototype from struct instructions*/
	void (*p_func)(stack_t **, unsigned int);
	FILE *file;
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	ssize_t line_size = 0;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	file = fopen(argv[1], "r");
	if (file == NULL)
		open_error(argv);
	while ((line_size = getline(&buf, &len, file)) != EOF)
	{
		token = strtok(buf, "\n\t\r ");
		if (token == '\0')
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			if (token == NULL || is_number(token) == -1)
				not_int_err(line_counter);
			number = atoi(token);
        /*p_func will receive the function to execute*/
			p_func = get_op_code(command, line_counter);
     	/* p_func takes the place of the function to execute: push, pall, etc*/
			p_func(&top, line_counter);
		}
		else
		{
			p_func = get_op_code(token, line_counter);
			p_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(file);
	if (buf != NULL)
		free(buf);
	free_stack(top);
}