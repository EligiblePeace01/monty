#include "monty.h"

/**
 * pop - remove element from the stack
 * @stack: the stack
 * @line_number: the line which are executed
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(tmp->prev);
		tmp->prev = NULL;
		file_var.top = tmp;
	}
	else
	{
		free(*stack);
		file_var.top = NULL;
	}
}
