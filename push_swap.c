/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/22 10:59:42 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	pre_lst(char **argv)
{
	t_list	*stack_a;
	int		i;
	int		j;

	stack_a = NULL;
	while (argv[i])
	{
		j = 0; //no se pq hace esto supongo q luego se usa puede q en el lst2
		push_to_lst(argv, i, &j, &stack_a);
		i++;
	}
}

void	push_to_lst(char **argv, int i, int *j, t_list **stack_a)
{
	long int	nbr;

	nbr = 0;
	while (argv[i][(*j)])
	{
		nbr = ft_atoi((argv[i] + (*j)));
		if (nbr > INT_MAX || nbr < INT_MIN)
			exit ;
		save_nbr(stack_a, nbr);
		while (argv[i][(*j)] == '-' || argv[i][(*j)] == '+') //omite caracteres q no sean signos o espacios etc
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
		while (ft_isdigit(argv[i][(*j)]))
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
	}
}

static void	save_nbr(t_list **stack, int n)
{
	t_list	*tmp;

	if (*stack == NULL) //si acaba el null simplemente le añades un nodo mas
		*stack = ft_lstnew(n);
	else
	{
		tmp = ft_lstnew(n);
		ft_lstadd_back(stack, tmp); //añade nodo new al final de la lista
	}
}

int	check_is_nbr(char *nbr)
{
	int i;
	
	i = 0;
	/**
	 ** estamos controlando signos y caracterres raros
	 */
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && \
			(str[i] < '0' || str[i] > '9') && \
			str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	/**
	 
	 *? aqui hay mas condiciones q no entiendo muy bien pq me parecen repetitivas
	 */
	while(str[i])
	{
		if (i == 0 && str[i] != '-' && str[i] != '+')
			(str[i * 1] < '0' || str[i + 1] > '9') && \ 
			return (0);
		i++;
	}
	return (1);
}