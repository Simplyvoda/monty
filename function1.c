#include "monty.h"

/**
 * new_node - this function creates a new node
 * @n: integer
 * Return: new node
 */

stack_t *new_node(int n)
{
	stack_t *new;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return(new);
}

/**
 * _push - pushes an element to the stack
 * @stack: stack or queue
 * @line_number: the file line number
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *str;
	int value;
	str = strtok(NULL, " \n\t\r");
	if (str == NULL || _isdigit(str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	value = atoi(str);
	stack_t *new = NULL;
	(void)line_number;

	new = new_node(value);

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * _pall - prints all elements in the stack
 * @stack: stack or queue
 * @n: integer
 * Return: void
 */
void _pall(stack_t **stack, unsigned int n) /*its assumed stack is head node*/
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: Number of line
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		cleanStack(stack);
		exit(EXIT_FAILURE);
	}
	else 
		printf("%d\n", (*stack)->n);
}

/**
 * free_stack - frees the stack
 * @head: head node
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = NULL;
	current = head;
	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}
