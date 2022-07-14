#include "monty.h"

/**
  * _push - push int to a stack
  * @stack: the monty stack.
  * @line_number: the index of the opcode.
  */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	char *arg;
	int operand;

	operand = 0;

	tmp = (stack_t *)malloc(sizeof(stack_t));

	if (!tmp)
	{
		printf("Error: malloc failed\n");
		error_exit(stack);
	}

	arg = strtok(NULL, "\n ");

	if (_isdigit(arg) == 1 && arg != NULL)
	{
		operand = atoi(arg);
	}
	else
	{
		printf("L%d: usage: push integer\n", line_number);
		error_exit(stack);
	}

	if (global_var == 1)
	{
		add_dnodeint_end(stack, operand);
	}

	if (global_var == 0)
	{
		add_dnodeint(stack, operand);
	}

}

/**
  * _pall - prints all the values on the stack, starting
  *          from the top of the stack.
  * @stack: the monty stack.
  * @line_number: opcode index.
  */

void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *process;

	process = *stack;
	while (process != NULL)
	{
		printf("%d\n", process->n);
		process = process->next;
	}
}

/**
  * _pint - prints the value at the top of the stack,
  *           followed by a new line.
  * @stack: monty stack
  * @line_number: opcode index.
  *
  */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *process;

	process = *stack;
	if (process == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		error_exit(stack);
	}
	printf("%d\n", process->n);
}

/**
  * _swap - swaps the top two elements of the stack.
  * @stack: the monty stack
  * @line_number: opcode index
  *
  */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *process;
	int tmp;

	process = *stack;
	if (process == NULL || process->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		error_exit(stack);
	}
	tmp = process->n;
	process->n = process->next->n;
	process->next->n = tmp;
}

/**
  * _pop - removes the top element of the stack.
  * @stack: monty stack.
  * @line_number: opcode index.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		error_exit(stack);
	}
	delete_dnodeint_at_index(stack, 0);
}
