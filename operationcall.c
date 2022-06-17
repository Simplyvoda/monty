#include "monty.h"

/**
 * ops - function to handle opcodes
 * @stack: stack or queue
 * @arg: arguments
 * @count: line command
 * Return: nothing
 */
void ops(stack_t **stack, char *args, unsigned int count)/* add item if it doesnt work */
{
	int i;

	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(args, op[i].opcode) == 0)
		{
			op[i].f(stack, count);
			return;
		}
	}
	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", count, op);
	exit(EXIT_FAILURE);
} /* review this file */
