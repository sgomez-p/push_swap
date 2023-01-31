/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/31 11:14:00 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	isordered(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		if (i != stack->order)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	ft_isint(char *str)
{
	int	i;
	int	len;

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

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	create_stack(t_stacks *situ, int argc, char **argv)
{
	t_stack	*current;
	int		i;

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
		if (ft_isint(argv[i]) && (check_dup(ft_atoi(argv[i]), (situ->stack_a))))
		{
			current->nbr = ft_atoi(argv[i]);
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
		ft_putnbr(current->nbr);
		ft_putchar('\n');
		current = current->next;
	}
	//free(current);
}

void	write_stack_b(t_stack *stack_b)
{
	t_stack	*current;

	if (stack_b == NULL)
	{
		ft_putstr("    ");
		return ;
	}
	current = stack_b;
	while (current != NULL)
	{
		ft_putstr("       ");
		ft_putnbr(current->nbr);
		current = current->next;
		ft_putstr("\n");
	}
	//free(current);
}

void	order_with_chunks(t_stack **stack_a, t_stack **stack_b, int tot_chunks)
{
	int		b_len;
	int		maxstack_len;
	t_chunk	c;

	maxstack_len = get_lenstack(*stack_a);
	b_len = 0;
	while (b_len < maxstack_len)
	{
		c.sizes = get_chunk_sizes(b_len, maxstack_len, tot_chunks);
		c.item = get_chunk_next_item(*stack_a, c.sizes.max, maxstack_len
				- b_len);
		prepare_pushb(stack_a, stack_b, &c);
		pb_mov(stack_a, stack_b);
		if (++b_len == 3)
			reverseorder3(stack_b);
	}
	push_src_to_dts(stack_b, stack_a);
}

int	get_next_move_default(t_stack *stack, int nbr, int len)
{
	int	first;
	int	last;
	int	i;

	i = 0;
	first = 0;
	last = -len;
	while (stack != NULL)
	{
		if (stack->order == nbr)
		{
			first = i;
			last = (len - i) * -1;
		}
		stack = stack->next;
		i++;
	}
	if (first <= (last * -1))
		return (first);
	return (last);
}

void	orderbydefault(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	move;
	int	next;

	next = 0;
	move = 0;
	len = get_lenstack(*stack_a);
	while (len)
	{
		move = get_next_move_default(*stack_a, ++next, len--);
		while (move > 0 && move--)
			ra_mov(stack_a);
		while (move < 0 && move++)
			rra_mov(stack_a);
		pb_mov(stack_a, stack_b);
	}
	while (next--)
		pa_mov(stack_a, stack_b);
}

static void	do_rotate(t_stack **stack)
{
	int		stack_len;
	t_stack	*aux;

	aux = NULL;
	stack_len = get_lenstack(*stack);
	if (stack_len == 2)
		sa_mov(stack);
	else if (stack_len == 3)
		order3(stack);
	else if (stack_len == 4)
		order4(stack);
	else if (stack_len == 5)
		order5(stack, &aux);
	else if (stack_len == 100 || stack_len == 500)
		order_with_chunks(stack, &aux, 5);
	else
		orderbydefault(stack, &aux);
}

void	ft_freestack(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		free(*stack);
		*stack = aux;
	}
}

static int	exists(int nbr, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->nbr == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	valid_range_int(const char *s_nbr)
{
	long	l;
	long	is_signed;

	l = 0;
	is_signed = (long)(s_nbr[0] == '-');
	while (*s_nbr != '\0' && !ft_isspace(*s_nbr) && l < INT_MAX)
	{
		if (ft_isdigit(*s_nbr))
			l = l * 10 + *s_nbr - '0';
		s_nbr++;
	}
	if (l > INT_MAX + is_signed)
		return (0);
	return (1);
}

static int	check_nbr(char *const_s_nbr)
{
	char	*s_nbr;

	s_nbr = (char *)const_s_nbr;
	if (!(ft_isdigit(s_nbr[0])) &&
		!(ft_isdigit(s_nbr[1]) && (s_nbr[0] == '-' || s_nbr[0] == '+')))
		return (0);
	if (*s_nbr == '-' || *s_nbr == '+')
		s_nbr++;
	while (*s_nbr != '\0' && !ft_isspace(*s_nbr))
	{
		if (!ft_isdigit(*s_nbr))
			return (0);
		s_nbr++;
	}
	return (s_nbr - const_s_nbr);
}

static void	ft_lstadd_back_nbr(t_stack **stack, int nbr)
{
	t_stack	*aux;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->nbr = nbr;
	new->pos = 1;
	new->order = 1;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		aux = *stack;
		aux->order += (aux->nbr > new->nbr);
		new->order += (new->nbr > aux->nbr);
		while (new->pos++ && aux->next != NULL)
		{
			aux = aux->next;
			aux->order += (aux->nbr > new->nbr);
			new->order += (new->nbr > aux->nbr);
		}
		aux->next = new;
	}
}

int	parse_nbr(char *s_nbr, t_stack **stack)
{
	int	nbr;
	int	read;

	while (ft_isspace(*s_nbr))
		s_nbr++;
	read = check_nbr(s_nbr);
	if (!read)
		return (0);
	if (!valid_range_int(s_nbr))
		return (0);
	nbr = ft_atoi(s_nbr);
	if (exists(nbr, *stack))
		return (0);
	ft_lstadd_back_nbr(stack, nbr);
	s_nbr += read;
	while (ft_isspace(*s_nbr))
		s_nbr++;
	if (*s_nbr != '\0')
		return (parse_nbr(s_nbr, stack));
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		error;

	i = 0;
	error = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		if (!parse_nbr(argv[i], &stack_a))
		{
			write(1, "Error\n", 7);
			error = EINVAL;
			break ;
		}
	}
	if (!error && !isordered(stack_a))
		do_rotate(&stack_a);
	ft_freestack(&stack_a);
	return (error);
}
