#include "monty.h"

/**
 * mon_push - Pushes an Element's to Stack
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_push(stack_t **doubly, unsigned int cline)
{
	int n, q;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (q = 0; vglo.arg[q] != '\0'; q++)
	{
		if (!isdigit(vglo.arg[q]) && vglo.arg[q] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * mon_pall - Output Every Value's on Stack
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * mon_pint - Output's Every Value at The Top of Stack
 *
 * @doubly: Head of LINKED LIST
 * @cline: line Numb
 * Return: No Return
 */
void mon_pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * mon_pop - Delete's the TOp Element's of Stack
 *
 * @doubly: Head of the LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * mon_swap - Swap's the Top Two Element's of Stack
 *
 * @doubly: Head of LINKED LIST
 * @cline: Line Numb
 * Return: No Return
 */
void mon_swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
