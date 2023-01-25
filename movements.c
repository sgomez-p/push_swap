/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/25 11:57:34 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra_mov(t_stack **stack_a)
{
    t_stack *temp;
    temp = *stack_a;
    if (temp != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next->next = NULL;
    }
    ft_putstr("ra\n");
}

void rb_mov(t_stack **stack_b)
{
    t_stack *temp;
    temp = *stack_b;
    if (temp != NULL)
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next->next = NULL;
    }
    ft_putstr("rb\n");
}

void	rr_mov(t_stacks *s)
{
	ra_mov(&s->stack_a);
	rb_mov(&s->stack_b);
}

void rra_mov(t_stack **stack_a)
{
    t_stack *temp;
    t_stack *last;
    temp = *stack_a;
    if (temp != NULL)
    {
        last = NULL;
        while (temp->next != NULL)
        {
            last = temp;
            temp = temp->next;
        }
        last->next = NULL;
        temp->next = *stack_a;
        *stack_a = temp;
    }
    ft_putstr("rra\n");
}

void	rrb_mov(t_stack **stack_b)
{
    t_stack *temp;
    t_stack *last;
    temp = *stack_b;
    if (temp != NULL)
    {
        last = NULL;
        while (temp->next != NULL)
        {
            last = temp;
            temp = temp->next;
        }
        last->next = NULL;
        temp->next = *stack_b;
        *stack_b = temp;
    }
    ft_putstr("rrb\n");
}

void	rrr_mov(t_stacks *s)
{
	rra_mov(&s->stack_a);
	rrb_mov(&s->stack_b);
}

void pa_mov(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    if (*stack_b)
    {
        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        *stack_a = temp;
    }
    ft_putstr("pa\n");
}

void pb_mov(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;
    if (*stack_a)
    {
        temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = *stack_b;
        *stack_b = temp;
    }
    ft_putstr("pb\n");
}

void sa_mov(t_stack **stack_a) 
{
	t_stack *temp;
	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
    ft_putstr("sa\n");
}



void sb_mov(t_stack **stack_b) 
{
	t_stack *temp;
	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
    ft_putstr("sb\n");
}


void ss_mov(t_stacks *s) 
{
    if (!s)
        return ;
    sa_mov(&s->stack_a);
    sb_mov(&s->stack_b);
}


int	check_empty(t_stack *s)
{
	int	i;

	i = 1; //creo q es mayor q 1
	while (s->next != NULL)
		i++;
	if (i > 1)
		return (0);
	else
		return (1);
}
