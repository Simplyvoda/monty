#include "monty.h"

/**
 * main - driver function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc == 2)
		read_file(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return(0);
}

/**
 * read_file - read monty files
 * @argv: argument name
 * Return: void
 */

void read_file(char *argv)
{
	int count = 0;
	size_t bufsize = 0;
	char *args = NULL;
	stack_t *stack = NULL;
	FILE *file = NULL;
	char *line = NULL;

	file = fopen(argv[1], "r");
	if (file)
	{
		while (getline(&line, &bufsize, file) != -1) /* getline returns -1 if theres an error or all lines have been read */
		{
			count++;
			args = strtok(line, " \n\t\r");
			while (args != NULL && *args == '#')
			{
				args = strtok(NULL, " \n\t\r");
			}
			ops(&stack, args, count);
		}
		free(line);
		free_stack(stack);
		fclose(file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
