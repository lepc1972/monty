#include "monty.h"

global_t global;

/**
* free_stack      - Free the memory
*/

void free_stack(void)
{
if (global.head != NULL)
{
while (global.head->next != NULL)
{
global.head = global.head->next;
free(global.head->prev);
}
free(global.head);
}
}


/**
* find_function   - Find function to match argument
*
* @stack:           Head of stack data structure
* @line_number:     current line in monty file
*/

void find_function(stack_t **stack, unsigned int line_number)
{
unsigned int i = 0;
instruction_t functions[] = {
{"push", o_push}, {"pall", o_pall},
{"pint", o_pint}, {"pop", o_pop},
{"swap", o_swap}, {"add", o_add},
{"nop", o_nop}, {NULL, NULL}
};

while (functions[i].opcode != NULL)
{
if (strcmp(global.op_name, functions[i].opcode) == 0)
{
functions[i].f(stack, line_number);
break;
}
i++;
}

/* Could not find command in array, invalid command */
if (functions[i].opcode == NULL)
{
printf("L%u: unknown instruction %s\n", line_number, global.op_name);
exit(EXIT_FAILURE);
}
}


/**
* main     - Interprets Monty bytecodes
*
* @argc:     Number of arguments
* @argv:     Array of arguments
*
* Return:    Success: EXIT_SUCCESS
*            Failure: EXIT_FAILURE
*/

int main(int argc, char **argv)
{
stack_t *head = NULL;
FILE *fp;
char *line = NULL;
size_t line_length = 0;
unsigned int line_number = 1;

if (argc < 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

fp = fopen(argv[1], "r");
if (fp == NULL)
{
printf("Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
atexit(free_stack);

while (getline(&line, &line_length, fp) != -1)
{
global.op_name = strtok(line, "\n\t\r\v\f ");
global.value = strtok(NULL, "\n\t\r\v\f ");

if (global.op_name != NULL)
{
find_function(&head, line_number);
}
line_number++;
}

free(line);
fclose(fp);

exit(EXIT_SUCCESS);
}
