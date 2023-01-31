/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:26:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/31 10:49:54 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

int	ft_validation(int argc, char **argv)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_only_spaces(argv[i]) == 1)
		{
			ft_nbr(argv[i]);
			ft_valid_str(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

int	ft_only_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == ' '
			|| str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_nbr(const char *str)
{
	int	i;

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
		if (str[i] >= '0' && str[i] <= '9') //checkea q es numero
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t') //se mete si espacio
		{
			if (sign != 0 && nbr == 0)
				ft_error();
			nbr = 0; //no se si hacen algo, pq reinicializan
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-') &&
					(sign == 0 && nbr == 0)) &&
					(str[i + 1] != '\0'))
			//si es el primer signo y no es ell final
			sign++;
		else
			ft_error();
		i++;
	}
}

int	check_dup(int n, t_stack *stack)
{
	int i;

	i = stack->nbr;
	while (i >= 0)
	{
		if (stack->nbr == n)
			return (0);
		i--;
	}
	return (1);
}