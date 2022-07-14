#include "monty.h"

/**
 * file_reader - reads the bytecode.
 * @filename: file absolute path.
 * @stack: pointer to the top of the stack
 *
 */
void file_reader(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = line_parser(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = check_opcode(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
/**
 * check_op_code -  checks opcode and execute it.
 * @str: the opcode
 *
 * Return: function, NULL otherwise
 */
instruct_func check_opcode(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

#include "monty.h"

/**
 * line_parser - parses the opcode line.
 * @line: line to be parsed
 *
 * Return: opcode, null otherwise.
 */
char *line_parser(char *line)
{
	char *ocode;

	ocode = strtok(line, "\n ");
	if (ocode == NULL)
		return (NULL);
	return (ocode);
}
