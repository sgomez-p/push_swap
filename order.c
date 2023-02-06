/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:25 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/02 20:24:35 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	int		i;
	int		j;
	int		temp;
	t_stack	*current;

	if (low < high)
	{
		i = low;
		j = high;
		current = *stack_a;
		while (i < j)
		{
			while (current->nbr <= current->next->nbr && i < high)
			{
				current = current->next;
				i++;
			}
			while (current->next->nbr > current->next->next->nbr && j > low)
			{
				current = current->next;
				j--;
			}
			if (i < j)
			{
				temp = current->next->nbr;
				current->next->nbr = current->next->next->nbr;
				current->next->next->nbr = temp;
			}
		}
		quicksort(stack_a, stack_b, low, j);
		quicksort(stack_a, stack_b, i, high);
	}
}

int	partition(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	int		pivot;
	int		i;
	int		j;
	t_stack	temp;

	pivot = (*stack_a)[high].nbr;
	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	{
		if ((*stack_a)[j].nbr <= pivot)
		{
			i++;
			temp = (*stack_a)[i];
			(*stack_a)[i] = (*stack_a)[j];
			(*stack_a)[j] = temp;
			pb_mov(stack_a, stack_b);
		}
	}
	temp = (*stack_a)[i + 1];
	(*stack_a)[i + 1] = (*stack_a)[high];
	(*stack_a)[high] = temp;
	pb_mov(stack_a, stack_b);
	return (i + 1);
}

int	find_pivot(t_stack **stack_a, int low, int high)
{
	int	mid;

	mid = (low + high) / 2;
	if ((*stack_a)[low].nbr > (*stack_a)[mid].nbr
		&& (*stack_a)[low].nbr < (*stack_a)[high].nbr)
		return (low);
	else if ((*stack_a)[mid].nbr > (*stack_a)[low].nbr
			&& (*stack_a)[mid].nbr < (*stack_a)[high].nbr)
		return (mid);
	else
		return (high);
}

void	divide_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pivot;
	int	size;

	size = get_lenstack(*stack_a);
	pivot = find_pivot(stack_a, 0, size - 1);
	while (get_lenstack(*stack_a) > 0)
	{
		if ((*stack_a)->nbr < pivot)
		{
			pb_mov(stack_a, stack_b);
		}
		else
		{
			ra_mov(stack_a);
		}
	}
	if (get_lenstack(*stack_b) > 0)
		divide_b(stack_b, stack_a);
	while (get_lenstack(*stack_b) > 0)
		pa_mov(stack_b, stack_a);
	if (get_lenstack(*stack_a) > 1)
		divide_a(stack_a, stack_b);
}

void	divide_b(t_stack **stack_b, t_stack **stack_a)
{
	int	pivot;
	int	size;

	size = get_lenstack(*stack_b);
	pivot = find_pivot(stack_b, 0, size - 1);
	while (get_lenstack(*stack_b) > 0)
	{
		if ((*stack_b)->nbr >= pivot)
		{
			pa_mov(stack_b, stack_a);
		}
		else
		{
			rb_mov(stack_b);
		}
	}
	if (get_lenstack(*stack_a) > 1)
		divide_a(stack_a, stack_b);
	while (get_lenstack(*stack_a) > 0)
		pb_mov(stack_a, stack_b);
	if (get_lenstack(*stack_b) > 1)
		divide_b(stack_b, stack_a);
}

void	order500(t_stack **stack_a, t_stack **stack_b, int size)
{
	quicksort(stack_a, stack_b, 0, size - 1);
}

void	add_elem(t_stack **stack, int elem)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return ;
	new->nbr = elem;
	new->next = *stack;
	*stack = new;
}

void	reverseorder3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a)
		return ;
	first = (*stack_a)->nbr;
	second = (*stack_a)->next->nbr;
	third = (*stack_a)->next->next->nbr;
	while (!(first > second && second > third))
	{
		if (first < second && first < third)
		{
			rra_mov(stack_a);
		}
		else if (first < second && third < second)
		{
			sa_mov(stack_a);
			ra_mov(stack_a);
		}
		else if (second < first && second < third)
			rra_mov(stack_a);
		first = (*stack_a)->nbr;
		second = (*stack_a)->next->nbr;
		third = (*stack_a)->next->next->nbr;
	}
}

void	order3(t_stack **stack_a)
{
	int		first;
	int		second;
	int		third;
	t_stack	*aux;

	while (!isordered(*stack_a))
	{
		aux = *stack_a;
		first = aux->nbr;
		second = aux->next->nbr;
		third = aux->next->next->nbr;
		if (first > second && first > third)
		{
			ra_mov(stack_a);
		}
		else if (first > second && third > second)
		{
			sa_mov(stack_a);
			rra_mov(stack_a);
		}
		else if (second > first && second > third)
			ra_mov(stack_a);
		else
			break ;
	}
}

void order4(t_stack **stack_a, t_stack **stack_b)
{
	int		first;
	int		second;
	t_stack *temp;
	t_stack *temp_b;
	temp = *stack_a;
	first = INT_MAX;
	second = INT_MAX;
	while (temp != NULL)
	{
		if (temp->nbr <= first)
		{
			second = first;
			first = temp->nbr;
		}
		else if (temp->nbr <= second)
		{
			second = temp->nbr;
		}
		temp = temp->next;
	}
	while ((*stack_a)->nbr != first)
	{
		if (first > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	while ((*stack_a)->nbr != second)
	{
		if (second > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	if (temp->nbr > temp->next->nbr)
		sa_mov(stack_a);
	temp_b = *stack_b;
	if (temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
	print_stack_a(*stack_a);
}


void	order5(t_stack **stack_a, t_stack **stack_b)
{
	int		first;
	int		second;
	t_stack	*temp;
	t_stack	*temp_b;

	first = INT_MAX;
	second = INT_MAX;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->nbr <= first)
		{
			second = first;
			first = temp->nbr;
		}
		else if (temp->nbr <= second)
		{
			second = temp->nbr;
		}
		temp = temp->next;
	}
	while ((*stack_a)->nbr != first)
	{
		if (first > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	while ((*stack_a)->nbr != second)
	{
		if (second > get_lenstack(*stack_a) / 2)
			rra_mov(stack_a);
		else
			ra_mov(stack_a);
	}
	pb_mov(stack_a, stack_b);
	temp_b = *stack_b;
	order3(stack_a);
	if (temp_b->next->next && (temp_b->next > temp_b->next->next))
		sb_mov(stack_b);
	pa_mov(stack_a, stack_b);
	pa_mov(stack_a, stack_b);
}

void	setup_pos(t_stack *s)
// asignamos las posiciones donde se encuentra actualmente cada numero
{
	int i;

	i = 1;
	while (s->next != NULL)
	{
		s->pos = i;
		s = s->next;
		i++;
	}
}

int	get_lenstack(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	printf("Stack A: ");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\nStack B: ");
	current = stack_b;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}

void	print_stack_a(t_stack *stack_a)
{
	t_stack	*current;

	printf("Stack A: ");
	current = stack_a;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}

/*
void	site_pos(t_stack *s)
{
	t_stack	*current;
	int		count;
	t_stack	*temp;

	current = s;
	while (current != NULL)
	{
		count = 1;
		temp = s;
		while (temp != NULL)
		{
			if (current->nbr > temp->nbr)
			{
				count++;
			}
			temp = temp->next;
		}
		current->site = count;
		current = current->next;
	}
} */
/*
void	find_smallest_numbers(t_stack **stack_a, int *pos1, int *pos2)
{
	int		i;
	t_stack	*temp;

	int min1, min2;
	min1 = min2 = INT_MAX;
	temp = *stack_a;
	i = 0;
	while (temp != NULL)
	{
		if (temp->nbr < min1)
		{
			min2 = min1;
			min1 = temp->nbr;
			*pos1 = i;
		}
		else if (temp->nbr < min2)
		{
			min2 = temp->nbr;
			*pos2 = i;
		}
		temp = temp->next;
		i++;
	}
}

long	small_finder(t_stack *stack)
{
	int	small;

	small = stack->nbr;
	while (stack != NULL)
	{
		if (small >= stack->nbr)
			small = stack->nbr;
		stack = stack->next;
	}
	return (small);
}

long	biggest_finder(t_stack *stack) // hacemos por algo el stack a?
{
	int big;

	big = stack->nbr;
	while (stack != NULL)
	{
		if (big <= stack->nbr)
			big = stack->nbr;
		stack = stack->next;
	}
	return (big);
}
*/