/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/21 13:41:58 by sgomez-p         ###   ########.fr       */
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
			quit();
		save_nbr(stack_a, nbr);
		while (argv[i][(*j)] == '-' || argv[i][(*j)] == '+')
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
		while (ft_isdigit(argv[i][(*j)]))
			(*j)++;
		while (argv[i][(*j)] == ' ' || argv[i][(*j)] == '\t')
			(*j)++;
	}
}