/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/04/20 19:20:46 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    while (i < size)
    {
        j = i;
        while (j < size)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int *save_20_smallest_nums(t_stack *stack_a)
{
	int *smallest = malloc(sizeof(int) * 20);
	t_stack *temp = stack_a;
	int i = 0;
	while (temp != NULL && i < 20)
	{
		smallest[i] = temp->data;
		temp = temp->next;
		i++;
	}
	while (i < 20)
	{
		smallest[i] = INT_MAX;
		i++;
	}
	sort_array(smallest, 20);
	return smallest;
}

void top_and_bottom_plus_detector_smallest(t_stack *stack_a, int *top_movements, int *bottom_movements)
{
	t_stack *current_a = stack_a;
	t_stack *temp = stack_a;
	*top_movements = 0;
	*bottom_movements = 0;
	while (temp != NULL)
	{
		if (temp->data < current_a->data)
			(*top_movements)++;
		else
			(*bottom_movements)++;
		temp = temp->next;
	}
}

int find_best_move(t_stack *stack_a, int num)
{
	int ra_moves = 0;
	int rra_moves = 0;
	// count moves for ra
	t_stack *temp = stack_a;
	while (temp != NULL && temp->data != num)
	{
		ra_moves++;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		// number not found in stack_a
		return -1;
	}

	// count moves for rra
	temp = stack_a;
	while (temp->next != NULL && temp->next->data != num)
	{
		temp = temp->next;
		rra_moves++;
	}
	if (temp->next == NULL)
	{
		// number not found in stack_a
		return -1;
	}

	// determine the best move
	if (ra_moves <= rra_moves)
	{
		// best move is ra
		return ra_moves;
	}
	else
	{
		// best move is rra
		return -rra_moves;
	}

}

void insert_in_order(t_stack **stack_a, t_stack **stack_b, int num)
{
    int moves = 0;
    // find the correct position in stack_b
    t_stack *temp = *stack_b;
    while (temp != NULL && num < temp->data)
    {
        temp = temp->next;
        moves++;
    }

    // perform the necessary moves to insert the number
    if (moves == 0)
    {
        // push num to the top of stack_b
        pb_mov(stack_a, stack_b);
    }
    else
    {
        int best_move = find_best_move(*stack_a, num);
        if (best_move > 0)
        {
            // perform ra best_move times
            while (best_move--)
            {
                ra_mov(stack_a);
            }
        }
        else if (best_move < 0)
        {
            // perform rra_mov abs(best_move) times
            while (best_move++)
            {
                rra_mov(stack_a);
            }
        }
        else
        {
            // number is already in the correct position
            return;
        }
    } // Agregamos una llave de cierre aquí

    while (*stack_b != NULL)
    {
        int best_move = find_best_move(*stack_b, (*stack_b)->data);
        if (best_move > 0)
        {
            // perform rb best_move times
            while (best_move--)
            {
                rb_mov(stack_b);
            }
        }
        else if (best_move < 0)
        {
            // perform rrb_mov abs(best_move) times
            while (best_move++)
            {
                rrb_mov(stack_b);
            }
        }

        // push top of stack_b to stack_a
        pa_mov(stack_a, stack_b);
    }
}




void push_20_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int *smallest = save_20_smallest_nums(*stack_a);
	int i = 0;
	while (i < 20)
	{
		insert_in_order(stack_a, stack_b, smallest[i]);
		i++;
	}
	free(smallest);
}

void sort_stack_b(t_stack **stack_b, t_stack **stack_a)
{
	int i = 0;
	int *smallest = malloc(sizeof(int) * 5);
	t_stack *temp = *stack_b;
	while (temp != NULL && i < 5)
	{
		smallest[i] = temp->data;
		temp = temp->next;
		i++;
	}
	while (i < 5)
	{
		smallest[i] = INT_MAX;
		i++;
	}
	sort_array(smallest, 5);

	i = 0;
	while (i < 5)
	{
		int best_move = find_best_move(*stack_b, smallest[i]);
		if (best_move > 0)
		{
			// perform rb best_move times
			while (best_move--)
			{
				rb_mov(stack_b);
			}
		}
		else if (best_move < 0)
		{
			// perform rrb_mov abs(best_move) times
			while (best_move++)
			{
				rrb_mov(stack_b);
			}
		}

		// push num to stack_b
		pa_mov(stack_a, stack_b);
		i++;
	}
	free(smallest);
}

void push_all_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		pa_mov(stack_a, stack_b);
	}
}

void sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int i = 0;
	int *smallest = malloc(sizeof(int) * 5);
	t_stack *temp = *stack_a;
	while (temp != NULL && i < 5)
	{
		smallest[i] = temp->data;
		temp = temp->next;
		i++;
	}
	while (i < 5)
	{
		smallest[i] = INT_MAX;
		i++;
	}
	sort_array(smallest, 5);

	i = 0;
	while (i < 5)
	{
		int best_move = find_best_move(*stack_a, smallest[i]);
		if (best_move > 0)
		{
			// perform ra best_move times
			while (best_move--)
			{
				ra_mov(stack_a);
			}
		}
		else if (best_move < 0)
		{
			// perform rra_mov abs(best_move) times
			while (best_move++)
			{
				rra_mov(stack_a);
			}
		}

		// push num to stack_b
		pb_mov(stack_a, stack_b);
		i++;
	}
	free(smallest);
}

void remove_20_smallest_nums(t_stack **stack_a, int *smallest, t_stack **stack_b)
{
	int i = 0;
	while (i < 20)
	{
		int best_move = find_best_move(*stack_a, smallest[i]);
		if (best_move > 0)
		{
			// perform ra best_move times
			while (best_move--)
			{
				ra_mov(stack_a);
			}
		}
		else if (best_move < 0)
		{
			// perform rra_mov abs(best_move) times
			while (best_move++)
			{
				rra_mov(stack_a);
			}
		}

		// push num to stack_b
		pb_mov(stack_a, stack_b);
		i++;
	}
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	push_20_smallest_to_b(stack_a, stack_b);
	sort_stack_b(stack_b, stack_a);
	push_all_to_a(stack_a, stack_b);
}

void sort_100(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int *smallest;


    for (i = 0; i < 5; i++) {
        smallest = save_20_smallest_nums(*stack_a);
		remove_20_smallest_nums(stack_a, smallest, stack_b);
        free(smallest);
        push_20_smallest_to_b(stack_a, stack_b);
    }

    sort_stack_b(stack_b, stack_a);
    push_all_to_a(stack_a, stack_b);
    sort_stack_a(stack_a, stack_b);
}
