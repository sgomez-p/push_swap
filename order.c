/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/10 17:18:18 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	small_finder(t_stack *stack)
{
	int small;

	small = stack->n;
	while (stack != NULL)
	{
		if (small >= stack->n)
			small = stack->n;
		stack = stack->next;
	}
	return (small);
}

long	biggest_finder(t_stack *stack) // hacemos por algo el stack a?
{
	int big;

	big = stack->n;
	while (stack != NULL)
	{
		if (big <= stack->n)
			big = stack->n;
		stack = stack->next;
	}
	return (big);
}

int get_lenstack(t_stack *stack)
{
	int i;
	
	i = 0;
	while(stack->next != NULL)
	{
		i++;
		stack->next;
	}
	return (i);
}

void order3(t_stack **stack_a) //no hace falta pasarnos nada al stackb asi q lo nombro a todo con a para aclarar
{
	int first;
	int	second;
	int third;

	t_stack	*aux;
	
	aux = *stack_a;
	first = aux->n;
	second = aux->next->n;
	third = aux->next->next->n;
	
	while(1)
	{
		if (second > third && second > first)
			rra_mov(**stack_a);
		else if(first > second && first > third)
			ra_mov(**stack_a);
		else if (first > second)
			sa_mov(**stack_a);
		else
			break ;
	}
	
}

void	order5(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	t_stack *aux;
	
	aux = *stack_b;
	first = aux->n;
	second = aux->next->n;
	if (get_lenstack(*stack_a) == 5)
	{
		pb_mov(stack_a, stack_b);
		pb_mov(stack_a, stack_b);
		order3(stack_a);
		if (first > second)
			sb_mov(*stack_b);
		pa_mov(stack_a, stack_b);
		pa_mov(stack_a, stack_b);
	}
	
}

/*
void	ft_translate(t_stack *stack)
{
	if(
		small_finder(stack_a)
}
*/