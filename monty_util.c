#include "monty.h"

/**
  * error_exit - free stack and exit
  * @stack: pointer to the top of stack
  *
  */

void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}

/**
  * _isdigit - check if the arg is a number
  * @str: the arg being passed
  *
  * Return: 1 if arg is a number, 0 otherwise
  */

int _isdigit(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
