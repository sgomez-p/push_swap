/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/17 17:14:07 by sgomez-p         ###   ########.fr       */
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

void order3(t_stack **stack_a) //no hace falta pasarnos nada al stackb asi q lo nombro a todo con a para aclarar
{
	int first;
	int	second;
	int third;

    t_stack *current;

    if (!stack_a || !*stack_a)
        return ;

    current = *stack_a;
    first = current->n;
    second = current->next->n;
    third = current->next->next->n;
    ft_putstr("cucu");
    while (!(first < second) && (second < third))
    {
        ft_putstr("primer");
        if (first > second && first > third)
		{
			ra_mov(stack_a);
			current = *stack_a;
			first = current->n;
			second = current->next->n;
			third = current->next->next->n;
        }
		else if (first > second && second > third)
        {
			ft_putstr("segun");
            sa_mov(stack_a);
            current = *stack_a;
            first = current->n;
            second = current->next->n;
            third = current->next->next->n;
        }
        else if (second > first && second > third)
        {
            rra_mov(stack_a);
            current = *stack_a;
            first = current->n;
            second = current->next->n;
            third = current->next->next->n;
			ft_putstr("tercer");
			
        }
    }
}

void order5(t_stack **stack_a, t_stack **stack_b)
{
int pos1, pos2;
int i;
t_stack *temp_b;
t_stack *temp;
site_pos(*stack_a);

// Find the two smallest numbers using the sites
temp = *stack_a;
pos1 = 0;
pos2 = 0;
i = 0; 
while (temp != NULL)
{
    if (temp->site == 1)
    {
        pos1 = i;
    }
    else if (temp->site == 2)
    {
        pos2 = i;
    }
    temp = temp->next;
    i++;
}

// Move the two smallest numbers to the beginning of stack_a
if (pos1 > pos2)
{
    if (pos1 > 2)
    {
        i = 0;
        while (i < pos1 - 2)
        {
            rra_mov(stack_a);
            i++;
        }
    }
    if (pos2 > 1)
    {
        i = 0;
        while (i < pos2 - 1)
        {
            ra_mov(stack_a);
            i++;
        }
    }
}
else
{
    if (pos2 > 2)
    {
        i = 0;
        while (i < pos2 - 2)
        {
            rra_mov(stack_a);
            i++;
        }
    }
    if (pos1 > 1)
    {
        i = 0;
        while (i < pos1 - 1)
        {
            ra_mov(stack_a);
            i++;
        }
    }

}
// Move the two smallest numbers to stack_b
	pb_mov(stack_a, stack_b);
	pb_mov(stack_a, stack_b);

// Sort the remaining 3 numbers in stack_a
	order3(stack_a);

// Move the two smallest numbers back to stack_a
	temp_b = *stack_b;
	if (temp_b->next->n < temp_b->next->next->n)
	{
    	sb_mov(stack_b);
	}
	temp_b = *stack_b;
	pa_mov(stack_b, stack_a);
	pa_mov(stack_b, stack_a);
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

void site_pos(t_stack *s)
{
    t_stack *current;
    int count;

    current = s;
    while (current != NULL)
    {
        count = 0;
        t_stack *temp = s;
        while (temp != NULL)
        {
            if (current->n > temp->n)
            {
                count++;
            }
            temp = temp->next;
        }
        current->site = count + 1;
        current = current->next;
    }
}


