/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/13 20:09:20 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void prequick_sort(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    size = get_lenstack(*stack_a);
    if (size <= 1)
        return;
    quicksort(stack_a, stack_b, size);
}

void quicksort(t_stack **stack_a, t_stack **stack_b, int size)
{
    int pivot_index;
    if (size <= 1)
        return;
    pivot_index = partition(stack_a, stack_b, size);
    quicksort(stack_a, stack_b, pivot_index);
    quicksort(stack_a, stack_b, size - pivot_index - 1);
}


int get_pivot(t_stack *stack_a, int size)
{
    int pivot_index;
    t_stack *current;
    current = stack_a;
    pivot_index = size / 2;
    while (pivot_index > 0)
    {
        current = current->next;
        pivot_index--;
    }
    return (current->nbr);
}

int move_pivot_to_top(t_stack **stack_a, t_stack **stack_b, int pivot)
{
    int i;
    int size;
    size = get_lenstack(*stack_a);
    i = 0;
    while ((*stack_a)->nbr != pivot)
    {
        if ((*stack_a)->nbr > pivot)
        {
            pb_mov(stack_a, stack_b);
            size--;
        }
        else
        {
            ra_mov(stack_a);
            i++;
        }
    }
    return (i);
}

int partition(t_stack **stack_a, t_stack **stack_b, int size)
{
    int pivot_index;
    int i;
    if (size <= 0)
        return 0;
    pivot_index = get_pivot(*stack_a, size);
    pivot_index = move_pivot_to_top(stack_a, stack_b, pivot_index);
    i = 0;
    while (i < size - 1 && (*stack_a))
    {
        if ((*stack_a)->nbr < (*stack_a)->next->nbr)
        {
            pb_mov(stack_a, stack_b);
            size--;
        }
        else
        {
            ra_mov(stack_a);
            i++;
        }
    }
    return (i);
}
