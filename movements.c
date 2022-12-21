/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/21 13:15:50 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *current)
{
	int				aux;

	aux = current->n;
	while (current->next != '\0')
	{
		if (current->n == aux)
			exit(1);
		aux = current->next->n;
	}
	current = current->next;
}

void	ra_mov(t_stack **stack_a)
{
	t_stack			*current;
	int				num;

	current = (t_stack *)malloc(sizeof(t_stack));
	current = *stack_a;
	num = current->n;
	current = current->next;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = num;
	//free(num);
}

void	rb_mov(t_stack **stack_b)
{
	t_stack	*current;
	int		num;

	current = (t_stack *)malloc(sizeof(t_stack));
	current = *stack_b;
	num = current->n;
	current = current->next;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = num;
	//free(num);
}

void	rr_mov(t_stacks *s)
{
	ra_mov(&s->stack_a);
	rb_mov(&s->stack_b);
}

void	rra_mov(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*last_node;

	last_node = NULL;

	current = (t_stack *)malloc(sizeof(t_stack));
	current->next = *stack_a;
	while (current->next != NULL)
	{
		last_node = current;
		current = current->next;
	}
	last_node->next = NULL;
	current->next = *stack_a;
	*stack_a = current;
}

void	rrb_mov(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last_node;

	last_node = NULL;

	current = (t_stack *)malloc(sizeof(t_stack));
	current->next = *stack_b;
	while (current->next != NULL)
	{
		last_node = current;
		current = current->next;
	}
	last_node->next = NULL;
	current->next = *stack_b;
	*stack_b = current;
}

void	rrr_mov(t_stacks *s)
{
	rra_mov(&s->stack_a);
	rrb_mov(&s->stack_b);
}

void	pa_mov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;
	t_stack	*new_node_2;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node_2 = (t_stack *)malloc(sizeof(t_stack));
	new_node_2 = *stack_b;
	new_node->next = *stack_a;
	new_node->n = new_node_2->n;
	new_node_2 = new_node_2->next;
	*stack_a = new_node;
	*stack_b = new_node_2;
}

void	pb_mov(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;
	t_stack	*new_node_2;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node_2 = (t_stack *)malloc(sizeof(t_stack));
	new_node_2 = *stack_a;
	new_node->next = *stack_b;
	new_node->n = new_node_2->n;
	new_node_2 = new_node_2->next;
	*stack_b = new_node;
	*stack_a = new_node_2;
}


void	sa_mov(t_stack *stack_a)
{
	int				i;
	t_stack			*aux;


	while (stack_a->next != NULL)
		i++;
	if (i >= 1)
	{
		aux = stack_a->next;
		stack_a->n = stack_a->next;
		stack_a->next = aux;
	}
	//free (aux);
}

void	sb_mov(t_stack **stack_b) // revisar si esta bien o mmejor como el de arriba
{
	t_stack	*new_node;
	int				i;
	int				aux;

	aux = 0;
	while (new_node->next != NULL)
		i++;
	if (i >= 1)
	{
		aux = new_node->next;
		new_node->n = new_node->next;
		new_node->next = aux;
	}
	//free (aux);
	return (0);
}

void	ss_mov(t_stacks *s)
{
	sa_mov(&s->stack_a);
	sb_mov(&s->stack_b);
}

int	check_empty(t_stack *s)
{
	int	i;

	i = 0;
	while (s->next != NULL)
		i++;
	if (i > 1)
		return (0);
	else
		return (1);
}
