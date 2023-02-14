/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:26:14 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/14 11:45:22 by sgomez-p         ###   ########.fr       */
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
			is_nbr(argv[i]);
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

void	is_nbr(const char *str)
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


int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int isordered(t_stack *stack)
{
	int i;

	i = 1;
	while (stack != NULL)
	{
		if (i != stack->site)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int ft_isint(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int check_nbr(char *const_str_nbr)
{
	char *str_nbr;

	str_nbr = (char *)const_str_nbr;
	if (!(ft_isdigit(str_nbr[0])) &&
		!(ft_isdigit(str_nbr[1]) && (str_nbr[0] == '-' || str_nbr[0] == '+')))
		return (0);
	if (*str_nbr == '-' || *str_nbr == '+')
		str_nbr++;
	while (*str_nbr != '\0' && !ft_isspace(*str_nbr))
	{
		if (!ft_isdigit(*str_nbr))
			return (0);
		str_nbr++;
	}
	return (str_nbr - const_str_nbr);
}


int valid_range_int(const char *str_nbr)
{
	long l;
	long is_signed;

	l = 0;
	is_signed = (long)(str_nbr[0] == '-');
	while (*str_nbr != '\0' && !ft_isspace(*str_nbr) && l < INT_MAX)
	{
		if (ft_isdigit(*str_nbr))
			l = l * 10 + *str_nbr - '0';
		str_nbr++;
	}
	if (l > INT_MAX + is_signed)
		return (0);
	return (1);
}

int exists(int nbr, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}