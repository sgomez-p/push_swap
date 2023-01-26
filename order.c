/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/26 12:18:52 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void quicksort(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
    int i;
    int j;
    int temp;
    t_stack *current;

    if (low < high)
    {
        i = low;
        j = high;
        current = *stack_a;
        while (i < j)
        {
            while (current->n <= current->next->n && i < high)
            {
                current = current->next;
                i++;
            }
            while (current->next->n > current->next->next->n && j > low)
            {
                current = current->next;
                j--;
            }
            if (i < j)
            {
                temp = current->next->n;
                current->next->n = current->next->next->n;
                current->next->next->n = temp;
            }
    }
    quicksort(stack_a, stack_b, low, j);
    quicksort(stack_a, stack_b, i, high);
    }

}

int partition(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
    int pivot = (*stack_a)[high].n;
    int i = (low - 1);
    int j;
    t_stack temp;
    for (j = low; j <= high - 1; j++)
    {
        if ((*stack_a)[j].n <= pivot)
        {
            i++;
            temp = (*stack_a)[i];
            (*stack_a)[i] = (*stack_a)[j];
            (*stack_a)[j] = temp;
            pb_mov(stack_a, stack_b);
        }
    }
    temp = (*stack_a)[i + 1];
    (*stack_a)[i + 1] = (*stack_a)[high];
    (*stack_a)[high] = temp;
    pb_mov(stack_a, stack_b);
    return (i + 1);
}

int find_pivot(t_stack **stack_a, int low, int high)
{
    int mid;

    mid = (low + high) / 2;
    if ((*stack_a)[low].n > (*stack_a)[mid].n && (*stack_a)[low].n < (*stack_a)[high].n)
        return (low);
    else if ((*stack_a)[mid].n > (*stack_a)[low].n && (*stack_a)[mid].n < (*stack_a)[high].n)
        return (mid);
    else
		return (high);
}

void divide_a(t_stack **stack_a, t_stack **stack_b)
{
    int pivot;
    int size = get_lenstack(*stack_a);
    pivot = find_pivot(stack_a, 0, size - 1);

    while (get_lenstack(*stack_a) > 0)
    {
        if ((*stack_a)->n < pivot)
        {
            pb_mov(stack_a, stack_b);
        }
        else
        {
            ra_mov(stack_a);
        }
    }

    if (get_lenstack(*stack_b) > 0)
        divide_b(stack_b, stack_a);

    while (get_lenstack(*stack_b) > 0)
        pa_mov(stack_b, stack_a);

    if (get_lenstack(*stack_a) > 1)
        divide_a(stack_a, stack_b);
}

void divide_b(t_stack **stack_b, t_stack **stack_a)
{
    int pivot;
    int size = get_lenstack(*stack_b);
    pivot = find_pivot(stack_b, 0, size - 1);

    while (get_lenstack(*stack_b) > 0)
    {
        if ((*stack_b)->n >= pivot)
        {
            pa_mov(stack_b, stack_a);
        }
        else
        {
            rb_mov(stack_b);
        }
    }

    if (get_lenstack(*stack_a) > 1)
        divide_a(stack_a, stack_b);

    while (get_lenstack(*stack_a) > 0)
        pb_mov(stack_a, stack_b);

    if (get_lenstack(*stack_b) > 1)
       divide_b(stack_b, stack_a);
}


void order500(t_stack **stack_a, t_stack **stack_b, int size)
{
    quicksort(stack_a, stack_b, 0, size - 1);
}

void add_elem(t_stack **stack, int elem)
{
    t_stack *new;
    if (!(new = (t_stack *)malloc(sizeof(t_stack))))
        return;
    new->n = elem;
    new->next = *stack;
    *stack = new;
}

void	reverseorder3(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    if (!stack_a || !*stack_a)
        return ;

    first = (*stack_a)->n;
    second = (*stack_a)->next->n;
    third = (*stack_a)->next->next->n;

    while (!(first > second && second > third))
    {
        if (first < second && first < third)
        {   
            rra_mov(stack_a);
        }
        else if (first < second && third < second)
        { 
            sa_mov(stack_a);
            ra_mov(stack_a);
        }
        else if (second < first && second < third)
            rra_mov(stack_a);

        first = (*stack_a)->n;
        second = (*stack_a)->next->n;
        third = (*stack_a)->next->next->n;
    }
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

			first = (*stack_a)->n;
			second = (*stack_a)->next->n;
			third = (*stack_a)->next->next->n;
		}
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
			if (first > get_lenstack(*stack_a)/2)
				rra_mov(stack_a);
			else
				ra_mov(stack_a);
		}
	pb_mov(stack_a, stack_b);
	//print_stacks(*stack_a, *stack_b);
	while ((*stack_a)->n != second) 
	{
		if (second > get_lenstack(*stack_a)/2)
				rra_mov(stack_a);
			else
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
	//print_stacks(*stack_a, *stack_b);
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