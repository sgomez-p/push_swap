/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/25 12:47:35 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ra_mov(t_list **stack)
{
	struct	stack	stack_a;
	stack	*current;
	stack	new_node;
/*	t_list	*start;
	t_list	*last;

	start = (*stack);
	(*stack) = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = start;
	start->next = NULL; */
	current = (stack*)malloc(sizeof(stack));
	while(new_node->next != '\0')
		new_node = new_node->next;
	if(new_node->next == '\0')
		new_node->next = *current;
}

void	rb_mov(t_list **stack)
{
	
}

void	check_duplicate(stack **current)
{
	int aux;
	stack	new_node;

	aux = new_node->next;
	while(new_node->next != '\0')
	{
		if(new_node == aux)
			quit();
		else
			aux = new_node->next;
	}
	new_node = new_node->next;
}