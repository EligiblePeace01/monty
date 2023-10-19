#include "monty.h"

/**
 * pchar - print the char of the int in the top element according to asci
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (__isascii(tmp->n))
		dprintf(STDOUT_FILENO, "%c\n", tmp->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
}


/**
 * pstr -  prints the string starting at the top of the stack to the end
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	while (tmp && tmp->n > 0 && tmp->n < 128)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");
}
