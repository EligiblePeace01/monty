#include "monty.h"

/**
 * rotl - make the top one in the last
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;

	tmp = *stack;
	if (!tmp)
		return;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		free_all();
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->next = NULL;
	new->n = tmp->n;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	pop(stack, line_number);
}


/**
 * rotr - make the last one is the top
 * @stack: the stack
 * @line_number: the line which are excuted
*/
void rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp)
		return;
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*stack = tmp;
}
