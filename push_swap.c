/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:30:44 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/16 13:25:39 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_next_move(t_stack *stack, int nbr, int len)
{ //almacena la posicion del numero que buscamos y lo almacena en first
	int first;
	int last;
	int i;

	i = 0;
	first = 0;
	last = -len;
	while (stack != NULL)
	{
		if (stack->site == nbr)
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

void orderstock(t_stack **stack_a, t_stack **stack_b)
{
	int len;
	int move;
	int next;

	next = 0;
	move = 0;
	len = get_lenstack(*stack_a);
	while (len)
	{
		move = get_next_move(*stack_a, ++next, len--); //busca el siguiente y la len se reduce
		while (move > 0 && move--)
			ra_mov(stack_a);
		while (move < 0 && move++)
			rra_mov(stack_a);
		pb_mov(stack_a, stack_b);
	}
	while (next--)
		pa_mov(stack_a, stack_b);
}

static void filter_by_stack(t_stack **stack)
{
	int stack_len;
	t_stack *aux;
	aux = NULL;
	stack_len = get_lenstack(*stack);
	if (stack_len == 2)
		sa_mov(stack);
	else if (stack_len == 3)
		order3(stack);
	else if (stack_len == 4)
		order4(stack, &aux);
	else if (stack_len == 5)
		order5(stack, &aux);
	//else if (stack_len == 500)
	//	quicksort(stack, 500);
	else
		orderstock(stack, &aux);
}

void ft_freestack(t_stack **stack)
{
	t_stack *aux;

	aux = *stack;
	while (aux != NULL)
	{
		aux = aux->next;
		free(*stack);
		*stack = aux;
	}
}

static void setup_list(t_stack **stack, int nbr)
{
	t_stack *aux;
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->nbr = nbr;
	new->pos = 1;
	new->site = 1;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		aux = *stack;
		if (aux->nbr > new->nbr)
			aux->site += 1;
		else
			new->site += 1;
		while (new->pos++ && aux->next != NULL)
		{
			aux = aux->next;
			if (aux->nbr > new->nbr)
				aux->site += 1;
			else
				new->site += 1;
		}
		aux->next = new;
	}
}

int nbr_is_valid(char *str_nbr, t_stack **stack)
{
	int nbr;
	int read;

	while (ft_isspace(*str_nbr))
		str_nbr++;
	read = check_nbr(str_nbr);
	if (!read)
		return (0);
	if (!valid_range_int(str_nbr))
		return (0);
	nbr = ft_atoi(str_nbr);
	if (exists(nbr, *stack))
		return (0);
	setup_list(stack, nbr); //
	str_nbr += read;
	while (ft_isspace(*str_nbr))
		str_nbr++;
	if (*str_nbr != '\0')
		return (nbr_is_valid(str_nbr, stack));
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	int i;
	int error;

	i = 0;
	error = 0;
	stack_a = NULL;
	while (++i < argc)
	{
		if (!nbr_is_valid(argv[i], &stack_a))
		{
			write(1, "Error\n", 7);
			error = EINVAL; // se podria probar con devolver (-1) ? este error es para cuando el argumento introducido no es valido
			break;
		}
	}
	if (!error && !isordered(stack_a))
		filter_by_stack(&stack_a);
	ft_freestack(&stack_a);
	return (error);
}

/*
void create_stack(t_stacks *situ, int argc, char **argv)
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

void write_stack_a(t_stack *stack_a)
{
	t_stack *current;

	current = stack_a;
	while (current != NULL)
	{
		ft_putnbr(current->nbr);
		ft_putchar('\n');
		current = current->next;
	}
	// free(current);
}

void write_stack_b(t_stack *stack_b)
{
	t_stack *current;

	if (stack_b == NULL)
	{
		ft_putstr("    ");
		return;
	}
	current = stack_b;
	while (current != NULL)
	{
		ft_putstr("       ");
		ft_putnbr(current->nbr);
		current = current->next;
		ft_putstr("\n");
	}
	// free(current);
} */