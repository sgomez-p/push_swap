/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/29 14:49:05 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	check_duplicate(struct stack **current)
{
	int aux;
	stack	new_node;

	aux = new_node->next;
	while(new_node->next != '\0')
	{
		if(new_node == aux)
			quit();
		aux = new_node->next;
	}
	new_node = new_node->next;
}

void	ra_mov(struct stack **stack_a)
{
	struct 	stack	*current;
	int num;
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
}

void	rb_mov(struct stack **stack_b)
{
	
	struct 	stack	*current;
	int num;
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
}

void	rr_mov(struct stack **stack_a, struct stack **stack_b)
{
	ra_mov(t_list **stack_a);
	rb_mov(t_list **stack_b);
}

void	rra_mov(struct stack **stack_a)
{
	stack	*current;
	struct stack *Last;
	
	*Last = NULL;
	current = (stack*)malloc(sizeof(stack));
	current->next = *stack_a;
	while(new_node->next != NULL)
	{
		Last = new_node; /* probar a borrar esta opción yo creo que no hace falta pillar los alores en esta variable*/
		new_node = new_node->next;
	}
	Last->next = NULL;
	current->next = *stack_a;
	*current = new_node; /* estamos updateando los valores de  nuestro stack*/
}

void	rrb_mov(struct stack **stack)
{	
	stack	*current;
	struct stack *Last;
	
	*Last = NULL;
	current = (stack*)malloc(sizeof(stack));
	current->next = *stack_a;
	while(new_node->next != NULL)
	{
		Last = new_node; /* probar a borrar esta opción yo creo que no hace falta pillar los alores en esta variable*/
		new_node = new_node->next;
	}
	Last->next = NULL;
	current->next = *stack_a;
	*current = new_node; /* estamos updateando los valores de  nuestro stack*/
}

void	sa_mov(struct stack **stack)
{
	stack	*new_node;
	int		i;
	int		aux;
	
	aux = 0;
	while (new_node->next != NULL)
	
	if(i >= 1)
	{
		aux = new_node->next;
		new_node->next = new_node->next->next;
		new_node->next->next = aux;
	}
	free (aux); /*no se si hay q hacerlo pq no hago alloc previamente*/
	return (0);
}

void	sb_mov(struct stack **stack)
{
	struct	stack	stack_b;
	stack	*current;
	stack	new_node;
	int		i;
	int		aux;
	
	aux = 0;
	if(i <= 1)
	{
		aux = new_node->next;
		new_node->next = new_node->next->next;
		new_node->next->next = aux;
	}
	free (aux); /*no se si hay q hacerlo pq no hago alloc previamente*/
	return (0);
}

void	ss_mov(struct stack **stack)
{
	sa_mov(stack_a);
	sb_mov(stack_b);
}
