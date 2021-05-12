#include "monty.h"
/**
 * main - Main entry
 * Description: bytecodes interpreter
 * @argc: # of arguments
 * @argv: montyfiles
 * Return: int
 */
int main(int argc, char **argv)
{
    while (argc != 2)
        error();
	open_read(argv);
    return (0);
}