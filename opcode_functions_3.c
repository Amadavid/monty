#include"monty.h"

/**
*_div - Divide's the Second element By the Top Element'S of Stack
*@doubly: Head of LINKED LIST
*@cline: Line Numb
*Return: No Return
*/
void _div(stack_t **doubly, unsigned int cline)
{

	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	_pop(doubly, cline);
}

/**
*mon_mul - Multiplies the Top Element's To
*the Second Top Element's of The Stack
*
*@doubly: Head of LINKED LIST
*@cline: Line Numb
*Return: No Return
*/
void mon_mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}


/**
*mon_mod - Determine's the remaining of The Division of The Second Element
*By The Top Element of the Stack
*
*@doubly: Head of LINKED LIST
*@cline: Line Numb;
*Return: No Return
*/
void mon_mod(stack_t **doubly, unsigned int cline)
{

	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}

/**
*mon_pchar - Output the Char Value of The First Element's
*Followed by a New line.
*
*@doubly: Head of LINKED LIST
*@cline: Line Numb;
*Return: No Return
*/
void mon_pchar(stack_t **doubly, unsigned int cline)
{

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}

/**
*mon_pstr - Output the String at The Top of Stack.
*@doubly: Head of LINKED LIST
*@cline: Line Numb;
*Return: No Return
*/
void mon_pstr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
