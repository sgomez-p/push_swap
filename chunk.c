/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/15 19:01:54 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void merge_sort(t_stacks *stack)
{
    int size = (stack)->size;
    if (size < 2)
        return;

    // Dividir la pila en dos
    int half_size = size / 2;
    t_stack *stack_a = (stack)->stack_a;
    t_stack *stack_b = (stack)->stack_b;

    while (stack_a->next && half_size > 1)
    {
        stack_a = stack_a->next;
        half_size--;
    }

    stack_b = stack_a->next;
    stack_a->next = NULL;
    stack_a = (stack)->stack_a;

    t_stacks *left = malloc(sizeof(t_stacks));
    t_stacks *right = malloc(sizeof(t_stacks));

    left->size = size / 2;
    right->size = size - size / 2;

    left->stack_a = stack_a;
    left->stack_b = NULL;
    right->stack_a = stack_b;
    right->stack_b = NULL;

    // Ordenar cada pila por separado
    merge_sort(left);
    merge_sort(right);

    // Unir las dos pilas ordenadas
    stack = NULL;
    while (left->stack_a || right->stack_a)
    {
        if (!left->stack_a)
        {
            pb_mov(&right->stack_a, &right->stack_b);
            continue;
        }
        if (!right->stack_a)
        {
            pb_mov(&left->stack_a, &left->stack_b);
            continue;
        }

        if (left->stack_a->nbr < right->stack_a->nbr)
            pb_mov(&left->stack_a, &left->stack_b);
        else
            pb_mov(&right->stack_a, &right->stack_b);
    }
    // Fusionar las pilas auxiliares de regreso a la pila original
    while (left->stack_b)
        pa_mov(&stack_a, &left->stack_b);
    while (right->stack_b)
        pa_mov(&stack_b, &right->stack_b);
    free(left);
    free(right);
}





/*
int sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    int size = get_lenstack(*stack_a);
    if (size == 0)
        return 0;

    int max_moves = 7000;
    if (size <= 5)
        return insertion_sort(stack_a, stack_b, size);
    else if (size <= 100)
        max_moves = 700;
    else if (size <= 500)
        max_moves = 7000;

    return quicksort(stack_a, stack_b, size, max_moves);
}*/
