#include "monty.h"

/**
  * _add - adds the top two elements of the stack.
  * @stack: pointer to stack pointer
  * @line_number: the line index of the opcode
  *
  */

void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		error_exit(stack);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
