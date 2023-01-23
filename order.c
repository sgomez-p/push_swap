/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/23 22:14:37 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void order3(t_stack **stack_a)
{
		int first;
		int second;
		int third;
		
		if (!stack_a || !*stack_a)
			return ;

		first = (*stack_a)->n;
		second = (*stack_a)->next->n;
		third = (*stack_a)->next->next->n;
		ft_putstr("\norder3 70:");
		print_stack_a(*stack_a);
		while (!(first < second && second < third))
		{
			if (first > second && first > third)
			{	
				ra_mov(stack_a);
				//sa_mov(stack_a);
			}
			else if (first > second && third > second)
			{ 
				sa_mov(stack_a);
				rra_mov(stack_a);
			}
			else if (second > first && second > third)
				ra_mov(stack_a);

			first = (*stack_a)->n;
			second = (*stack_a)->next->n;
			third = (*stack_a)->next->next->n;
		}
		ft_putstr("\norder3 87:");
		print_stack_a(*stack_a);
}

void order4(t_stack **stack_a)
{
    order3(stack_a);
    while ((*stack_a)->next->next->next)
    {
        if ((*stack_a)->n > (*stack_a)->next->next->next->n)
            rra_mov(stack_a);
        else
            ra_mov(stack_a);
    }
    if ((*stack_a)->n > (*stack_a)->next->n)
        sa_mov(stack_a);
}

void order5(t_stack **stack_a, t_stack **stack_b)
{
	int first;
	int second;

	first = INT_MAX;
	second = INT_MAX;
	t_stack *temp = *stack_a;
	t_stack *temp_b;
	
	while (temp != NULL) 
	{
		if (temp->n <= first) 
		{
			second = first;
			first = temp->n;
		} 
		else if (temp->n <= second) 
		{
			second = temp->n;
		}
			temp = temp->next;
	}
	while ((*stack_a)->n != first)
		{
			ra_mov(stack_a);
		}
	pb_mov(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
	while ((*stack_a)->n != second) 
	{
	ra_mov(stack_a);
	}
	//print_stacks(*stack_a, *stack_b);
	pb_mov(stack_a, stack_b);
	temp_b = *stack_b;
	//print_stacks(*stack_a, *stack_b);
	order3(stack_a);
	//print_stacks(*stack_a, *stack_b);
	if(temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
}

void setup_pos(t_stack *s) // asignamos las posiciones donde se encuentra actualmente cada numero
{
	int i;

	i = 1;
	while(s->next != NULL)
	{	
		
		s->pos = i;
		s = s->next;
		i++;	
	}
}

int get_lenstack(t_stack *stack)
{
	int i;
	
	if (!stack)
		return (0);
	i = 0;
	while(stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current;
    printf("Stack A: ");
    current = stack_a;
    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\nStack B: ");
    current = stack_b;
    while (current != NULL)
    {
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");
}

void print_stack_a(t_stack *stack_a)
{
	t_stack *current;
	printf("Stack A: ");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d ", current->n);
		current = current->next;
	}
	printf("\n");
}


void site_pos(t_stack *s) {
	t_stack *current;
	int count;

	current = s;
	while (current != NULL) {
		count = 1;
		t_stack *temp = s;
		while (temp != NULL) {
			if (current->n > temp->n) {
				count++;
			}
			temp = temp->next;
		}
		current->site = count;
		current = current->next;
	}

}

void find_smallest_numbers(t_stack **stack_a, int *pos1, int *pos2)
{
    int i;
    t_stack *temp;
    int min1, min2;
    min1 = min2 = INT_MAX;
    temp = *stack_a;
    i = 0;
    while (temp != NULL)
    {
        if (temp->n < min1)
        {
            min2 = min1;
            min1 = temp->n;
            *pos1 = i;
        }
        else if (temp->n < min2)
        {
            min2 = temp->n;
            *pos2 = i;
        }
        temp = temp->next;
        i++;
    }
}

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