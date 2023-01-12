/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:33 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/12 12:09:24 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	check_duplicate(t_stack *current)
{
    int				aux;

    while (current != NULL)
    {
        aux = current->n;
        while (current->next != NULL)
        {
            if (current->n == aux)
                exit(1);
            aux = current->next->n;
            current = current->next;
        }
        current = current->next;
    }
} */


void	ra_mov(t_stack **stack_a)
{
	t_stack			*current;
	int				num;

	current = (t_stack *)malloc(sizeof(t_stack));
	if(!stack_a)
		return ;
	current = *stack_a;
	if(!current)
		return ;
	num = current->n;
	current = current->next;
	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}
	current->n = num; // como hemos recorrido arriba ahora esta es la ult pos
	//free(num);
}

void	rb_mov(t_stack **stack_b)
{
	t_stack	*current;
	int		num;

	current = (t_stack *)malloc(sizeof(t_stack));
	if(!stack_b)
		return ;
	current = *stack_b;
	if(!current)
		return ;
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
	if(!s)
		return ;
	ra_mov(&s->stack_a);
	rb_mov(&s->stack_b);
}

void	rra_mov(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*last_node;

	if (!stack_a)
        return ;
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
	free(current);
}

void	rrb_mov(t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*last_node;

	if (!stack_b)
        return ;
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
	free(current);
}

void	rrr_mov(t_stacks *s)
{
	if(!s)
		return ;
	rra_mov(&s->stack_a);
	rrb_mov(&s->stack_b);
}

void	pa_mov(t_stack ***stack_a, t_stack ***stack_b)
{
	t_stack	*new_node;
	t_stack	*new_node_2;

	
	//new_node_2 = (t_stack *)malloc(sizeof(t_stack));
	
	if (!stack_a || !stack_b)
		return ;
	//if((int)new_node == 0 || (int)new_node_2 == 0 || (int)new_node == -1 || 
	//(int)new_node_2 == -1)
	//	ft_error();
	
	new_node_2 = *stack_b[0];
	if (!new_node_2)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->n = new_node_2->n;
	new_node->next = *stack_a[0];
	*stack_a[0] = new_node;
	*stack_b[0] = new_node_2->next;
	free(new_node_2);
}

void	pb_mov(t_stack ***stack_a, t_stack ***stack_b)
{
	t_stack	*new_node;
	t_stack	*new_node_2;
	
	//new_node_2 = (t_stack *)malloc(sizeof(t_stack));
	
	if (!stack_a || !stack_b)
		return ;
	//if((int)new_node == 0 || (int)new_node_2 == 0 || (int)new_node == -1 || 
	//(int)new_node_2 == -1)
	//	ft_error();
	
	new_node_2 = *stack_a[0];
	if (!new_node_2)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->n = new_node_2->n;
	new_node->next = *stack_b[0];
	*stack_b[0] = new_node;
	*stack_a[0] = new_node_2->next;
	free(new_node_2);
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