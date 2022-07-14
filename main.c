#include "monty.h"
#include "extern.h"

/**
  * main - executes the commandline arguments
  * @ac: counts the opcode.
  * @av: opcodes
  *
  * Return: 0
  */

int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		error_exit(&stack);
	}
	file_reader(av[1], &stack);
	free_dlistint(stack);

	return (0);
}
