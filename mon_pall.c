#include "monty.h"
/**
 *mon_pall - prints all the values on the stack
 * @stack: a pointer to the head node of the stack
 * @line_number: current line number
 */
void mon_pall(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
		return;

	printf("%d\n", (*stack)->n);
	mon_pall(&(*stack)->next, line_number);
}
