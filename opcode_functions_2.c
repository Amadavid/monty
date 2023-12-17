#include "monty.h"
#include <stdio.h>


/**
 * mon_queue - Assign the Format of the Data to a Queue (FIFO)
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}


/**
 * mon_stack - Assign the Format of the Data to a Stack (LIFO)
 *
 * @doubly: Head of the LINKED LIST
 * @cline: Line Numb;
 * Return: No Return
 */
void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * mon_nop - Doesn't do Anythinhg
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * mon_sub - Subtract's the Top Element to the Second Top Element of the Stack
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
