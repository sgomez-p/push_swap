/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:32:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/14 11:29:35 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			sig;
	long long	num;

	i = 0;
	sig = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * sig > INT_MAX)
			return (-1);
		if (num * sig < INT_MIN)
			return (0);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sig);
}