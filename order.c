/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/14 11:31:46 by sgomez-p         ###   ########.fr       */
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

void order4(t_stack **stack_a, t_stack **stack_b) //huele a qlo
{
	int		first;
	int		second;
	t_stack *temp;
	t_stack *temp_b;
	temp = *stack_a;
	first = INT_MAX;
	second = INT_MAX;
	while (temp != NULL)
	{
		if (temp->nbr <= first)
		{
			second = first;
			first = temp->nbr;
		}
		else if (temp->nbr <= second)
		{
			second = temp->nbr;
		}
		temp = temp->next;
	}
	while ((*stack_a)->nbr != first)
	{
		if (first > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	while ((*stack_a)->nbr != second)
	{
		if (second > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	if (temp->nbr > temp->next->nbr)
		sa_mov(stack_a);
	temp_b = *stack_b;
	if (temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
	print_stack_a(*stack_a);
}


void	order5(t_stack **stack_a, t_stack **stack_b)
{
	int		first;
	int		second;
	t_stack	*temp;
	t_stack	*temp_b;

	first = INT_MAX;
	second = INT_MAX;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->nbr <= first)
		{
			second = first;
			first = temp->nbr;
		}
		else if (temp->nbr <= second)
		{
			second = temp->nbr;
		}
		temp = temp->next;
	}
	while ((*stack_a)->nbr != first)
	{
		if (first > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	while ((*stack_a)->nbr != second)
	{
		if (second > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	temp_b = *stack_b;
	order3(stack_a);
	if (temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
}

/*
void	setup_pos(t_stack *s)
// asignamos las posiciones donde se encuentra actualmente cada numero
{
	int i;

	i = 1;
	while (s->next != NULL)
	{
		s->pos = i;
		s = s->next;
		i++;
	}
} */

int	get_lenstack(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

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
