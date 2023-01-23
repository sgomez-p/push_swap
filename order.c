/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/23 09:51:49 by sgomez-p         ###   ########.fr       */
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
    ft_putstr("\norder3 70:");
    print_stack_a(*stack_a);
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
    ft_putstr("\norder3 87:");
   // print_stack_a(*stack_a);
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

void order4(t_stack **stack_a, t_stack **stack_b) 
{
int small1, small2, big1, big2;
// Find the two smallest and biggest numbers
small1 = small_finder(*stack_a);
big1 = biggest_finder(*stack_a);
if (small1 != big1) {
small2 = small_finder(*stack_a);
big2 = biggest_finder(*stack_a);
} else {
small2 = -1;
big2 = -1;
}
// Move the two smallest numbers to the beginning of stack_a
while ((*stack_a)->n != small1) {
if ((*stack_a)->n == small2) {
pb_mov(stack_a, stack_b);
} else {
ra_mov(stack_a);
}
}
pb_mov(stack_a, stack_b);
while ((*stack_a)->n != small2) {
ra_mov(stack_a);
}
pb_mov(stack_a, stack_b);
// Move the two biggest numbers to the end of stack_a
while ((*stack_a)->n != big1) {
if ((*stack_a)->n == big2) {
pb_mov(stack_a, stack_b);
} else {
ra_mov(stack_a);
}
}
rra_mov(stack_a);
while ((*stack_a)->n != big2) {
if ((*stack_a)->n == big1) {
pb_mov(stack_a, stack_b);
} else {
rra_mov(stack_a);
}
}
rra_mov(stack_a);
// Move the two smallest numbers back to stack_a
pa_mov(stack_b, stack_a);
pa_mov(stack_b, stack_a);
// Sort the remaining 2 numbers in stack_a
if ((*stack_a)->n > (*stack_a)->next->n) {
sa_mov(stack_a);
}
}

/*
void order5(t_stack **stack_a, t_stack **stack_b) 
{
    int pos1, pos2;
	printf("\npreo4:");
    order4(stack_a, stack_b); 
	printf("\n poso4");// ordenamos los primeros 4 números
    find_smallest_numbers(stack_a, &pos1, &pos2); // encontramos la posición del quinto número más pequeño
    while (get_lenstack(*stack_a) > 4) 
	{ // mientras haya más de 4 elementos en el stack
        while (get_lenstack(*stack_a) - 1 != pos2) // mover el quinto número a su posición correcta
            if (pos2 > get_lenstack(*stack_a) / 2)
               ra_mov(stack_a);
			else
				rra_mov(stack_a);
	}
	printf("\n fuerabucle");
	if ((*stack_a)->n == small_finder(*stack_a)) // si el último elemento es el más pequeño
		rra_mov(stack_a);
	print_stacks(*stack_a, *stack_b); //moverlo al principio del stack A
} */

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
			while (i < pos2 - 1)
			{
				rra_mov(stack_a);
				i++;
				ft_putstr("\n rra_movpos2");
			}
		}
		if (pos1 > 1)
		{
			i = 0;
			while (i < pos1)
			{
				ra_mov(stack_a);
				i++;
				ft_putstr("\n ra_movpos1");
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
	// Move the two smallest
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
		*stack_b = NULL;
		ft_putstr("\n 195 order5\n");
	
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