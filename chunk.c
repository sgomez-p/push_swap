/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/26 12:59:10 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size_by_stacklen(int item, int stack_len, int tot_chunks)
{
	int	size;

	size = 0;
	if (stack_len == 100)
	{
		if (item < 51)
			size = 20;
		else if (item < 91)
			size = 15;
		else if (item < 101)
			size = 10;
	}
	else if (stack_len == 500)
	{
		if (item < 251)
			size = 50;
		else if (item < 401)
			size = 25;
		else if (item < 501)
			size = 20;
	}
	else
		size = stack_len / tot_chunks;
	return (size);
}

static t_chunk_sizes	get_chunk_sizes(int item, int stack_len, int tot_chunks)
{
	t_chunk_sizes	chunk;

	chunk.size = get_chunk_size_by_stacklen(item, stack_len, tot_chunks);
	chunk.max = (1 + item / chunk.size) * chunk.size;
	chunk.min = chunk.max - chunk.size;
	chunk.mid = chunk.size + (chunk.max - chunk.size) / 2;
	return (chunk);
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
		c.item.nbr = get_chunk_next_item(*stack_a, c.sizes.max, maxstack_len - b_len);
		prepare_pushb(stack_a, stack_b, &c);
		pb_mov(stack_a, stack_b);
		if (++b_len == 3)
			reverseorder3(*stack_b);
	}
	push_src_to_dts(stack_b, stack_a);
}

void	push_src_to_dts(t_stack **src, t_stack **dst)
{
	int		len;
	t_stack	*aux;

	len = get_stack_len(*src);
	aux = *src;
	while (aux->order != len)
	{
		rrb_mov(dst);
		aux = *src;
	}
	while (len--)
		pa_mov(src, *dst);
}

static t_stack_stats	get_stack_stats(t_stack *stack, int min)
{
	t_stack_stats	result;

	result.first = stack->order;
	result.second = stack->next->order;
	result.min = min;
	result.max = 0;
	while (stack != NULL)
	{
		if (result.max < stack->order)
			result.max = stack->order;
		if (result.min > stack->order && result.min > min)
			result.min = stack->order;
		if (result.min == min && result.min < stack->order)
			result.min = stack->order;
		result.last = stack->order;
		stack = stack->next;
	}
	return (result);
}

static int	get_stackb_move(t_stack_stats s, int nbr)
{
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

	b_moves = get_stackb_move(get_stack_stats(*stack_b, c.sizes.min), c.item.nbr);
	if (b_moves > 0 && c.item.pos > 0)
		rrr_mov(stack_a, stack_b);
	else if (b_moves < 0 && c.item.pos < 0)
		rrr_mov(stack_a, stack_b);
	else
	{
		if (c.item.pos > 0)
			ra_mov(stack_a);
		else if (c.item.pos < 0)
			ra_mov(stack_a);
		if (b_moves > 0)
			rb_mov(stack_b);
		else if (b_moves < 0 )
			rb_mov(stack_b);
		else if (c.item.pos == 0)
			return (0);
	}
	return (1);
}

static void	prepareb_nextchunk(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk)
{
	int		len_a;
	t_stack	*aux;

	len_a = get_stack_len(*stack_a);
	while (1)
	{
		aux = *stack_b;
		if (aux->order >= chunk->sizes.min)
			break ;
		if (chunk->item.pos != 0)
		{
			rrr_mov(stack_a, stack_b);
			chunk->item.nbr = get_chunk_next_item(*stack_a, chunk->sizes.max, len_a);
		}
		else
			rrb_mov(stack_b); // no se si es rb_mov
	}
}

void	prepare_pushb(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk)
{
	if (get_stack_len(*stack_b) > 2)
	{
		prepareb_nextchunk(stack_a, stack_b, chunk);
		while (1)
		{
			if (!move_stacks(stack_a, stack_b, *chunk))
				break ;
			chunk->item.pos -= (chunk->item.pos > 0);
			chunk->item.pos += (chunk->item.pos < 0);
		}
	}
	else
	{
		while (chunk->item.pos > 0 && chunk->item.pos--)
			ra_mov(stack_a);
		while (chunk->item.pos < 0 && chunk->item.pos++)
			rra_mov(stack_a);
	}
}