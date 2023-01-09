/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/09 15:35:46 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stacks *situ, int argc, char **argv)
{
	t_stack *current;
	int i;

	current = (t_stack *)malloc(sizeof(t_stack));
	if (!current)
	{
		ft_putstr("Error al reservar memoria\n");
		exit(1);
	}
	situ->stack_a = current;
	current->next = NULL;
	i = 1;
	while (i < argc)
	{
		if((check_dup(ft_atoi(argv[i]), (situ->stack_a))))
		{	
			current->n = ft_atoi(argv[i]);
			if (i + 1 < argc)
			{
				current->next = (t_stack *)malloc(sizeof(t_stack));
				if (!(current->next))
				{
					ft_putstr("Error al reservar memoria\n");
					exit(1);
				}
			current = current->next;
			current->next = NULL;
			}
			i++;	
		}
		else
			ft_error();
	}
}

void	write_stack_a(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
		ft_putnbr(current->n);
		ft_putchar('\n');
		current = current->next;
	}
}

void	write_stack_b(t_stack *stack_b)
{
	t_stack	*current;

	if (stack_b == NULL)
	{
		ft_putstr("    ");
		return;
	}
	current = stack_b;
	while (current != NULL)
	{
		ft_putstr("       ");
		ft_putnbr(current->n);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stacks current;
	if (argc < 2)
	{
		ft_putstr("Introduce números a ordenar\n");
		return 0;
	}
	create_stack(&current, argc, argv);
	if(ft_validation(argc,argv))
	{
		write_stack_a(current.stack_a);
		ft_putstr("-------\n");
		ft_putstr("a");
		ft_putstr("    ");
		write_stack_b(current.stack_b);
		ft_putstr("b");
	}
	//free(current);
	return(0);
}
