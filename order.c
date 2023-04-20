/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/04/20 18:20:36 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_elem(t_stack **stack, int elem)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	new->nbr = elem;
	new->next = *stack;
	*stack = new;
}

void	order3(t_stack **stack_a)
{
	int		first;
	int		second;
	int		third;
	t_stack	*aux;

	while (!isordered(*stack_a))
	{
		aux = *stack_a;
		first = aux->nbr;
		second = aux->next->nbr;
		third = aux->next->next->nbr;
		if (first > second && first > third)
		{
			ra_mov(stack_a);
		}
		else if (first > second && third > second)
		{
			sa_mov(stack_a);
			rra_mov(stack_a);
		}
		else if (second > first && second > third)
			ra_mov(stack_a);
		else
			break ;
	}
}

int search_smaller(t_stack *stack)
{
	int		smaller;
	t_stack	*temp;

	smaller = INT_MAX;
	temp = stack;
	while (temp != NULL)
	{
		if (temp->nbr < smaller)
			smaller = temp->nbr;
		temp = temp->next;
	}
	return (smaller);
}

void	move_first_to_top(t_stack **stack, int first)
{
	while ((*stack)->nbr != first)
	{
		if (first > get_lenstack(*stack) / 2)
			rra_mov(stack);
		else
			ra_mov(stack);
	}
}

void order4(t_stack **stack_a, t_stack **stack_b)
{
	int		first;
	first = search_smaller(*stack_a);
	move_first_to_top(stack_a, first);
	pb_mov(stack_a, stack_b);
	order3(stack_a);
	pa_mov(stack_a, stack_b);
}

void	order5(t_stack **stack_a, t_stack **stack_b)
{
	int		first;
	t_stack	*temp_b;

	first = search_smaller(*stack_a);
	move_first_to_top(stack_a, first);
	pb_mov(stack_a, stack_b);
	first = search_smaller(*stack_a);
	move_first_to_top(stack_a, first);
	pb_mov(stack_a, stack_b);
	temp_b = *stack_b;
	order3(stack_a);
	if (temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
}

int	get_lenstack(t_stack *stack)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = stack;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}


/*
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	printf("Stack A: ");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\nStack B: ");
	current = stack_b;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}

void	print_stack_a(t_stack *stack_a)
{
	t_stack	*current;

	printf("Stack A: ");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}
*/