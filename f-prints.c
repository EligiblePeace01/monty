#include "monty.h"

/**
 * pall - print all element in the stack
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
		return;
	while (tmp)
	{
		dprintf(STDOUT_FILENO, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print the number in the top of the stack
 * @stack: the stack
 * @line_number: the line which are executed
*/
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!stack || !tmp)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", tmp->n);
}
