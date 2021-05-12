#include "monty.h"
/**
 * error_arguments -Main entry
 *Description: not file or more than valid args
 * Return: void
 **/
void error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error -Main entry
 *Description: message if is not possible open the file
 * @argv: args received by main, in this case te filename
 * Return: void
 **/
void operror(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}