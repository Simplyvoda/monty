#include "monty.h"
/**
 * _isdigit - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/
int _isdigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * cleanStack - Frees mallocs and close de files
 * @stack: Stack
 */
void cleanStack(stack_t **stack)
{
	FILE *file;
	char *line;
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
	fclose(file);
	free(line);
}

/**
 * free_stack - Free a list.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}
