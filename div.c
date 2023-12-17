#include "monty.h"

/**
 * _div - divides the second top element of the
 * stack by the top element of the stack.
 * @stack: a pointer to the head node of the stack
 * @line_number: a current line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}
