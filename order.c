/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/19 18:51:49 by sgomez-p         ###   ########.fr       */
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

    while (!(first < second && second < third))
    {
        if (first > second && first > third)
            ra_mov(stack_a);

        else if (first > second && second > third)
            sa_mov(stack_a);

        else if (second > first && second > third)
            rra_mov(stack_a);

        first = (*stack_a)->n;
        second = (*stack_a)->next->n;
        third = (*stack_a)->next->next->n;
    }
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
            if (current->n >= temp->n)
            {
                count++;
            }
            temp = temp->next;
        }
        current->site = count;
        current = current->next;
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
            printf("pos1 es : %d",pos1);
    	}
    	else if (temp->site == 2)
    	{
        	pos2 = i;
            printf("\npos2 es : %d",pos2);
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
                ft_putstr("\n ra_mov");
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
	ft_putstr("\n post site");
	}
// Move the two smallest numbers to stack_b
	ft_putstr("\n pre pb");
	pb_mov(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	pb_mov(stack_a, stack_b);
	print_stacks(*stack_a, *stack_b);
	ft_putstr("\n post");
// Sort the remaining 3 numbers in stack_a
	order3(stack_a);
	print_stacks(*stack_a, *stack_b);

	ft_putstr("\n fuera de order3 ");
// Move the two smallest numbers back to stack_a
	temp_b = *stack_b;
	if(temp_b->next && temp_b->next->next)
		if (temp_b->next->n < temp_b->next->next->n)
		{
    		sb_mov(stack_b);
			ft_putstr("\n if sb");
		}
	*stack_b = temp_b;
	ft_putstr("\n 192 order5");
	pa_mov(stack_b, stack_a);
	print_stacks(*stack_a, *stack_b);
	pa_mov(stack_b, stack_a);
	print_stacks(*stack_a, *stack_b);

	ft_putstr("\n 195 order5\n");
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
