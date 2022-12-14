/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/14 09:46:54 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(struct stack **current)
{
	int 			aux;
	struct stack	*new_node;

	aux = new_node->next;
	while(new_node->next != '\0')
	{
		if(new_node == aux)
			quit();
		aux = new_node->next;
	}
	new_node = new_node->next;
}

void	ra_mov(stacks **stack_a) // (struct stack **current)
{
	struct 	stack	*current;
	int 			num;
	current = (struct stack*)malloc(sizeof(struct stack));
	
	current = *stack_a;
	num = current->n;
	current = current->next;
	while(current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = num;
	free(num);
}

void	rb_mov(stacks **stack_b)
{
	
	struct 	stack	*current;
	int num;
	current = (struct stack*)malloc(sizeof(struct stack));
	
	current = *stack_b;
	num = current->n;
	current = current->next;
	while(current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = num;
	free(num);
}

void	rr_mov(stacks *s)
{
	ra_mov(&s->stack_a);
	rb_mov(&s->stack_b);
}

void	rra_mov(stacks **stack_a)
{
	struct stack	*current;
	struct stack 	*Last_node;
	struct stack	*new_node;

	Last_node = NULL;
	current = (stack*)malloc(sizeof(stack));
	current->next = *stack_a;
	while(new_node->next != NULL)
	{
		Last_node = new_node; /* probar a borrar esta opción yo creo que no hace falta pillar los alores en esta variable*/
		new_node = new_node->next;
	}
	Last_node->next = NULL;
	current->next = *stack_a;
	*current = new_node; /* estamos updateando los valores de  nuestro stack*/
}

void	rrb_mov(stacks **stack_b)
{	
	struct stack	*current;
	struct stack 	*Last_node;
	struct stack	*new_node;
	
	*Last_node = NULL;
	current = (stack*)malloc(sizeof(stack));
	current->next = *stack_b;
	while(new_node->next != NULL)
	{
		Last_node = new_node; /* probar a borrar esta opción yo creo que no hace falta pillar los alores en esta variable*/
		new_node = new_node->next;
	}
	Last_node->next = NULL;
	current->next = *stack_b;
	*current = *new_node; /* estamos updateando los valores de  nuestro stack*/
}

void	rrr_mov(stacks *s)
{
	rra_mov(&s->stack_a);
	rrb_mov(&s->stack_b);
}

void	pa_mov(stacks **stack_a, stacks **stack_b)
{
	struct stack	*new_node;
	struct stack	*new_node_2;

	new_node = (stack*)malloc(sizeof(stack));
	new_node_2 = (stack*)malloc(sizeof(stack));
	new_node_2 = *stack_b;
	new_node->next = *stack_a; //copia a partir del segundo
	new_node->n = new_node_2->n;
	new_node_2 = new_node_2->next;
	*stack_a = new_node;
	*stack_b = new_node_2;
	//mira si está vacio ya en algoritmo
}

void	pb_mov(stacks *stack_a, stacks *stack_b)
{
	int				aux;
	struct stack	*new_node;

	aux = stack_a->n;
	if(check_empty(*stack_a) == 0)
		stack_b = aux;
		new_node->n = new_node->next;
	free (aux);
}

void	sa_mov(stacks **stack_a)
{
	struct stack	*new_node;
	int				i;
	int				aux;
	
	aux = 0;
	while (new_node->next != NULL)
		i++;
	if(i >= 1)
	{
		aux = new_node->next;
		new_node->n = new_node->next;
		new_node->next = aux;
	}
	free (aux);
	/*hace falta return(0) ? */
}

void	sb_mov(struct stack **stack_b)
{
	struct stack	*new_node;
	int				i;
	int				aux;
	
	aux = 0;
	while (new_node->next != NULL)
		i++;
	if(i >= 1)
	{
		aux = new_node->next;
		new_node->n = new_node->next;
		new_node->next = aux;
	}
	free (aux);
	return (0);
}

void	ss_mov(struct stacks *s)
{
	sa_mov(&s->stack_a);
	sb_mov(&s->stack_b);
}

int	check_empty(stacks *s)
{
	int i;

	i = 0;
	while (s->next != NULL)
		i++;
	if (i > 1)
		return(0);
	else
		return(1);
}