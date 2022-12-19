/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:26:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/16 10:59:32 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int		ft_validation(int argc, char **argv)
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]))
		{
			ft_nbr(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

int		ft_only_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_nbr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	ft_error();
}



void	ft_valid_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
				(sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_error();
		i++;
	}
}


/*
void	ft_check_duplicate(data *new, stacks *stacks) // esto de data tengo que mirar como hacermelo
{
	int			*dup;

	if (!(dup = (int *)malloc(sizeof(int) * (new->next))))
		exit(1);
	dup = ft_intcpy(dup, new->a, new->next);
	ft_quick_sort(dup, 0, new->next - 1);
	ft_search_duplicate(dup, new->next - 1);
	stacks->stack_a = new->next;
	stacks->stack_b = 0;
	stacks->min = dup[0];
	stacks->med = dup[new->next / 2];
	stacks->max = dup[new->next - 1];
	free(dup);
}
*/


void	ft_search_duplicate(const int *dup, int cont)
{
	int i;

	i = 0;
	while (i != cont)
	{
		if (dup[i] == dup[i + 1])
			ft_error();
		i++;
	}
}