#include "monty.h"

/**
 * nop - do nothing
 * @stack: the stack
 * @line_number: the line which are executed
*/
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number)
{
	(void) line_number;
}
