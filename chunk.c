/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/10 11:45:34 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk_sizes get_chunk_sizes(int b_len, int maxstack_len, int tot_chunks)
{
	t_chunk_sizes chunk_sizes;
	chunk_sizes.min = maxstack_len / tot_chunks;
	chunk_sizes.max = chunk_sizes.min + 1;
	if (maxstack_len % tot_chunks <= b_len)
		chunk_sizes.max--;
	chunk_sizes.size = maxstack_len - b_len;
	return chunk_sizes;
}

t_chunk_item get_chunk_next_item(t_stack *stack, int chunk_size, int remaining_len)
{
	t_stack *current = stack;
	int i = 0;
	while (i < remaining_len - chunk_size)
	{
		current = current->next;
		i++;
	}
	t_chunk_item item;
	item.nbr = current->nbr;
	item.pos = current->pos;
	return item;
}

void prepare_pushb(t_stack **stack_a, t_stack **stack_b, t_chunk *c)
{
	int i = 0;
	t_stack *current = *stack_a;
	stack_b = stack_b;
	while (current->nbr != c->item.nbr)
	{
		if (i < c->sizes.min)
			ra_mov(stack_a);
		else
			rra_mov(stack_a);
		current = *stack_a;
		i++;
	}
}

void	push_src_to_dts(t_stack **stack_a, t_stack **stack_b)
{ // mueve todo de un stack a otro
	int		len;
	t_stack	*aux;

	len = get_lenstack(*stack_a);
	aux = *stack_a;
	while (aux->site != len)
	{
		rrb_mov(stack_b);
		aux = *stack_a;
		//ft_putstr("p src to dst while\n");
	}
	while (len--)
		pa_mov(stack_a, stack_b);
	//ft_putstr("salimos de aca");
}


void order_with_chunks(t_stack **stack_a, t_stack **stack_b, int tot_chunks)
{
	int b_len;
	int maxstack_len;
	t_chunk c;

	maxstack_len = get_lenstack(*stack_a);
	b_len = 0;
	while (b_len < maxstack_len)
	{
		c.sizes = get_chunk_sizes(b_len, maxstack_len, tot_chunks);
		c.item = get_chunk_next_item(*stack_a, c.sizes.max, c.sizes.size);
		prepare_pushb(stack_a, stack_b, &c);
		pb_mov(stack_a, stack_b);
		b_len++;
	}
	push_src_to_dts(stack_b, stack_a);
}

