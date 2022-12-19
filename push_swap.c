/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/19 15:51:41 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stacks *situ, int argc, char **argv)
{
	int				i;
	t_stack			*current;

	(current = (t_stack *)malloc(sizeof(t_stack)));
	if (!current)
		exit(1);
	situ->stack_a = current;
	i = 0;
	if (!(current->next))
		exit(1);
	while (++i < argc)
	{
		current->n = ft_atoi(argv[i]);
		current->next = NULL;
		if (i + 1 < argc)
		{
			current->next = (t_stack *)malloc(sizeof(t_stack));
			if (!(current->next))
				exit(1);
		}
		current = current->next;
		if (i == (argc - 1))
			current->next = NULL;
		else
			current = current->next;
		i++;
	}
	free (current);
}

void	write_stack_a(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		ft_putnbr((int)current->n);
		while (current->next)
			current = current->next;
	}
	ft_putstr("\n");
	free(current);
}

void	write_stack_b(t_stack *stack_b)
{
	t_stack	*current;

	current = stack_b;
	while (current != NULL)
	{
		ft_putstr("         ");
		ft_putnbr(current->n);
		while (current->next)
			current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stacks	current;

	create_stack(&current, argc, argv);
	write_stack_a(current.stack_a);
	write_stack_b(current.stack_b);
}
