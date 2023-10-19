#include "monty.h"

/**
 * push - push element to the stack
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int num;

	num = getnum(file_var.opcode, line_number);
	tmp = *stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (file_var.mode == STACK || !*stack)
	{
		new->n = num;
		new->prev = NULL;
		new->next = *stack;
		if (*stack)
			tmp->prev = new;
		tmp = new;
		file_var.top = new;
	}
	else if (file_var.mode == QUEUE)
	{
		new->n = num;
		new->next = NULL;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
