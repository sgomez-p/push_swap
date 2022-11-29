/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/29 14:44:58 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* lo primero q haremos es pasarle los numeros y las columnas para verlo gráficamente.
Me tiene que crear un stack con ellos. Los n los recibimos como un str*/
void	create_stack(situation *situ, int argc, char **argv)
{
	int		i;
	stack		*current;

	situ->movements = NULL;
	situ->stack_b = NULL;
	current = (stack*)malloc(sizeof(stack));
	error_manage((int)(current))
	situ->stack_a = current;
	i = 0;
	error_manage(!(i >= argc -1)); /*gestion de si se ha hecho bien el malloc*/
	while(++i < argc)
	{
		current->n = ft_atoi(argv[i]);
		current->next = NULL;
		if(i + 1 < argc)
		{
			current->next = (stack*)malloc(sizeof(stack));
			/*error*/
			current = current->next;
		}
		situ->final_a = current; /*hacer la funcion para q nos pille el ultimo nodo*/
		free(current);
	}
}

int	write_stack_a(struct stack *stack)
{
	struct	stack	*current;

	current = stack;
	while(current != NULL)
	{
		ft_putnbr(current->n);
		while(current->next)
			current = current->next;
	}
	ft_putstr("\n");
}

int	write_stack_b(struct stack *stack)
{
	struct stack *current;

	current = stack;
	while(current != NULL)
	{
		ft_putstr("         ");
		ft_putnbr(current->next);
		while(current->next)
			current = current->next;
	}
}
/*
void error_no_nbr(int argc, char **argv)
{	
	int	i;
	
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (check_is_nbr(argv[i]) == 0)
				exit(0);
			i++;
		}
	}
} 


int	check_is_nbr(char **argc)
{
	int i;
	
	i = 1;
	if(argc[i] < '0' || argc[i] > '9')
		return (0);
	i++;
	return (1);
} */

int main(int argc, char **argv)
{
	struct situation current;
	create_stack(&current, argc, argv);
	write_stack_a(&current.stack_a);
	write_stack_b(&current.stack_b);
}