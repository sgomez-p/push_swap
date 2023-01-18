/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/17 11:05:13 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_mov(t_stack **stack_a)
{
	t_stack			*current;
	int				num;

	if(!stack_a || !*stack_a)
		return ;
	current = *stack_a;
	if(!current)
		return ;
	num = current->n;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->next = *stack_a;// como hemos recorrido arriba ahora esta es la ult pos
	*stack_a = current;
	current->n = num;
}

void	rb_mov(t_stack **stack_b)
{
	t_stack	*current;
	int		num;

	if(!stack_b || !*stack_b)
		return ;
	current = *stack_b;
	if(!current->next)
		return ;
	num = current->n;
	current = current->next;
	while (current->next->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->next = *stack_b;// como hemos recorrido arriba ahora esta es la ult pos
	*stack_b = current;
	current->n = num;
}

void	rr_mov(t_stacks *s)
{
	if(!s)
		return ;
	ra_mov(&s->stack_a);
	rb_mov(&s->stack_b);
}

void	rra_mov(t_stack **stack_a)
{
    t_stack	*current;
    t_stack	*last_node;
    t_stack *temp;

    if (!stack_a)
        return ;
    last_node = NULL;
    //current = (t_stack *)malloc(sizeof(t_stack));
    current = *stack_a;
	if(!current)
		return ;
    while (current->next != NULL)
    {
        last_node = current;
        current = current->next;
    }
    last_node->next = NULL;
    temp = *stack_a;
    *stack_a = current;
    current->next = temp;
    //free(current);
}

void	rrb_mov(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last_node;

	if (!stack_b)
        return ;
	last_node = NULL;
	//current = (t_stack *)malloc(sizeof(t_stack));
	current = *stack_b;
	while (current->next != NULL)
	{
		last_node = current;
		current = current->next;
	}
	last_node->next = NULL;
	current->next = *stack_b;
	*stack_b = current;
	//free(current);
}

void	rrr_mov(t_stacks *s)
{
	if(!s)
		return ;
	rra_mov(&s->stack_a);
	rrb_mov(&s->stack_b);
}

void	pa_mov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a || !stack_b)
		return;
	if (!*stack_b)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb_mov(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp;

    if (!stack_a || !*stack_a || !stack_b)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
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


/*
void	ft_order3(char **argv)
{
	int i;
	
	i = 0;
	if(argv[i] != NULL)
	{
		if(argv[i] > argv[i + 1] && argv[i + 1] > argv[i + 2])
			printf("%s", "Ordenado");
		
	}
}*/