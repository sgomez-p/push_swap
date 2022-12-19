/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/16 12:46:34 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_init_stacks(data *new, stacks *s)
{
	s->stack_a = create_stack(new->stack_a, new->count);
	s->stack_b = NULL;
}

void	create_stack(stacks *situ, int argc, char **argv)
{
	int				i;
	const int 			buff;
	struct stack	*current;
	struct


	current = (stack*)malloc(sizeof(stack));
	situ->stack_a = current;
	i = 0;
	
	if(!(current->next = (stack*)malloc(sizeof(stack))));
				exit(1);
	while(++i < argc)
	{
		current->n = ft_atoi(argv[i]);
		current->next = NULL;
		if(i + 1 < argc)
		{
			if(!(current->next = (stack*)malloc(sizeof(stack))));
				exit(1);
		}
		current = current->next;
		if (i == (argc - 1))
			current->next = NULL;
		else
			current = current->next;
		i++;
	}
	return (current); //aqui he visto q cogen first = current y luego pone return de first pero no lo entiendo
}

void	write_stack_a(struct stack **stack_a)
{
	struct	stack	*current;

	current = *stack_a;
	while(current != NULL)
	{
		ft_putnbr((int)current->n);
		while(current->next)
			current = current->next;
	}
	ft_putstr("\n");
	//free(current); no se si tiene q hacerse free
}

void	write_stack_b(struct stack **stack_b) // he tenido q cambiar a doble puntero o se caga y ademas quiero tenerlo como staks pero no me funciona el main si lo hago
{
	struct stack *current;

	current = *stack_b;
	while(current != NULL)
	{
		ft_putstr("         ");
		ft_putnbr(current->n);
		while(current->next)
			current = current->next;
	}
}

int main(int argc, char **argv)
{
	stacks	current;
	create_stack(&current, argc, argv);
	write_stack_a(&current.stack_a);
	write_stack_b(&current.stack_b);
}