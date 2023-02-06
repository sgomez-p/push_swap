/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/06 08:58:39 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size_by_stacklen(int pos, int stack_len, int tot_chunks)
{ //determina tamaño de chunk segun la longitud del stack y el total de chunks en los q se van a dividir
	int	size;

	size = 0;
	if (stack_len == 100)
	{
		if (pos < 51)
			size = 20;
		else if (pos < 91)
			size = 15;
		else if (pos < 101)
			size = 10;
	}
	else if (stack_len == 500)
	{
		if (pos < 251)
			size = 50;
		else if (pos < 401)
			size = 25;
		else if (pos < 501)
			size = 20;
	}
	else
		size = stack_len / tot_chunks;
	return (size);
}

t_chunk_sizes	get_chunk_sizes(int pos, int stack_len, int tot_chunks)
{ // aporta info del tamaño minimo, maximo y medio de chunk
	t_chunk_sizes	chunk;

	chunk.size = get_chunk_size_by_stacklen(pos, stack_len, tot_chunks);
	chunk.max = (1 + pos / chunk.size) * chunk.size;
	chunk.min = chunk.max - chunk.size;
	chunk.mid = chunk.size + (chunk.max - chunk.size) / 2;
	return (chunk);
}

t_chunk_order	get_chunk_next_pos(t_stack *stack, int max, int stack_len)
{ // contiene info sobre el siguiente elemento a ser manipulado
	int				i;
	t_chunk_order	first;
	t_chunk_order	last;

	i = 0;
	first.pos = -1;
	while (stack != NULL)
	{
		if (stack->site <= max && first.pos == -1)
		{
			first.nbr = stack->site;
			first.pos = i;
		}
		if (stack->site <= max && first.pos != -1)
		{
			last.nbr = stack->site;
			last.pos = (stack_len - i) * -1;
		}
		stack = stack->next;
		i++;
	}
	if (first.pos <= (last.pos * -1))
		return (first);
	return (last);
}

void	stack_b_nextchunk(t_stack **stack_a, t_stack **stack_b,
		t_chunk *chunk)
{ //prepara el chunk para ser utilizado moviendo de un stack al otro
	int		len_a;
	t_stack	*aux;

	len_a = get_lenstack(*stack_a);
	while (1)
	{
		aux = *stack_b;
		if (aux->site >= chunk->sizes.min)
			break ;
		if (chunk->order.pos != 0)
		{
			rrr_mov(stack_a, stack_b);
			chunk->order = get_chunk_next_pos(*stack_a, chunk->sizes.max,
					len_a); //mirar si hace falta pos.nbr
		}
		else
			rrb_mov(stack_b);
	}
}

void	push_src_to_dts(t_stack **src, t_stack **dst)
{ // mueve todo de un stack a otro
	int		len;
	t_stack	*aux;

	len = get_lenstack(*src);
	aux = *src;
	while (aux->site != len)
	{
		rrb_mov(dst);
		aux = *src;
	}
	while (len--)
		pa_mov(src, dst);
}

static t_stack_values	get_stack_value(t_stack *stack, int min)
{ //contiene info sobre el stack: el 1 segundo minimo y max del stack
	t_stack_values	result;

	result.first = stack->site;
	result.second = stack->next->site;
	result.min = min;
	result.max = 0;
	while (stack != NULL)
	{
		if (result.max < stack->site)
			result.max = stack->site;
		if (result.min > stack->site && result.min > min)
			result.min = stack->site;
		if (result.min == min && result.min < stack->site)
			result.min = stack->site;
		result.last = stack->site;
		stack = stack->next;
	}
	return (result);
}

static int	get_stackb_move(t_stack_values s, int nbr)
{ //determina el movimiento para mover un elemento a stack_b
	if (s.first > nbr && s.first > s.second)
	{
		if (s.last == s.min && s.first == s.max && s.last > nbr)
			return (0);
		return (1);
	}
	else if (s.first > nbr && s.second == s.max)
		return (1);
	else if (s.first < nbr && s.last < nbr && s.last > s.first)
		return (-1);
	return (0);
}

static int	move_stacks(t_stack **stack_a, t_stack **stack_b, t_chunk c)
{ 
	int	b_moves;

	b_moves = get_stackb_move(get_stack_value(*stack_b, c.sizes.min),
			c.order.nbr); //se pasa el chunk y se comprueba 
	if (b_moves > 0 && c.order.pos > 0) // si b_moves > 0 hay q mover hacia inicio d stack
		rrr_mov(stack_a, stack_b);
	else if (b_moves < 0 && c.order.pos < 0)
		rrr_mov(stack_a, stack_b);
	else
	{
		if (c.order.pos > 0)
			ra_mov(stack_a);
		else if (c.order.pos < 0)
			ra_mov(stack_a);
		if (b_moves > 0)
			rb_mov(stack_b);
		else if (b_moves < 0)
			rb_mov(stack_b);
		else if (c.order.pos == 0)
			return (0);
	}
	return (1);
}

void	pre_pb(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk)
{
	if (get_lenstack(*stack_b) > 2)
	{
		stack_b_nextchunk(stack_a, stack_b, chunk);
		while (1)
		{
			if (!move_stacks(stack_a, stack_b, *chunk))
				break ;
			chunk->order.pos -= (chunk->order.pos > 0);
			chunk->order.pos += (chunk->order.pos < 0);
		}
	}
	else
	{
		while (chunk->order.pos > 0 && chunk->order.pos--)
			ra_mov(stack_a);
		while (chunk->order.pos < 0 && chunk->order.pos++)
			rra_mov(stack_a);
	}
}
