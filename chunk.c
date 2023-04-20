/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/04/20 14:13:46 by sgomez-p         ###   ########.fr       */
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
		j = i + 1;
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

// save the 20 smallest numbers in an array
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

        // push num to stack_b
        pb_mov(stack_a, stack_b);
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

















































































// void rb_or_rrb (t_stack **stack_b)
// {
// 	int i = 0;
// 	int j = 0;
// 	t_stack *temp = *stack_b;
// 	while (temp != NULL)
// 	{
// 		if (temp->data < (*stack_b)->data)
// 			i++;
// 		else
// 			j++;
// 		temp = temp->next;
// 	}
// 	if (i < j)
// 	{
// 		while (i > 0)
// 		{
// 			rb_mov(stack_b);
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		while (j > 0)
// 		{
// 			rrb_mov(stack_b);
// 			j--;
// 		}
// 	}
// }
// int *save_20_smallest_chunk(t_stack *stack_a)
// {
//     int *smallest = malloc(sizeof(int) * 20);
//     int i = 0;
//     int max_number = find_max_number(stack_a);
//     int min_number = find_min_number(stack_a);
//     int range = max_number - min_number;
//     int chunk = range / 20;
//     int current_chunk = min_number;
//     while (i < 20)
//     {
//         smallest[i] = current_chunk;
//         current_chunk += chunk;
//         i++;
//     }
//     return (smallest);
// }

// t_stack *get_last_node(t_stack *stack)
// {
//     if (!stack)
//         return (NULL);
//     while (stack->next != NULL)
//         stack = stack->next;
//     return (stack);
// }

// void find_max_node(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack *current_a = *stack_a;
// 	t_stack *current_b = *stack_b;
// 	t_stack *max_node = *stack_a;
	
// 	while (current_a != NULL)
// 	{
// 		if (current_a->data > max_node->data)
// 			max_node = current_a;
// 		current_a = current_a->next;
// 	}
// 	while (current_b != NULL)
// 	{
// 		if (current_b->data > max_node->data)
// 			max_node = current_b;
// 		current_b = current_b->next;
// 	}
// 	while (max_node != *stack_a)
// 		ra_mov(stack_a);
// 	pb_mov(stack_a, stack_b);
// }

// int is_descending_sorted(t_stack *stack)
// {
// 	int i = 0;
// 	int j = 0;
// 	t_stack *temp = stack;
// 	while (temp != NULL)
// 	{
// 		if (temp->data < stack->data)
// 			i++;
// 		else
// 			j++;
// 		temp = temp->next;
// 	}
// 	if (i == 0)
// 		return (1);
// 	else
// 		return (0);
// }

// int find_smallest_number(t_stack *stack)
// {
// 	int smallest = stack->data;
// 	t_stack *temp = stack;
// 	while (temp != NULL)
// 	{
// 		if (temp->data < smallest)
// 			smallest = temp->data;
// 		temp = temp->next;
// 	}
// 	return (smallest);
// }

// void get_chunk_values(t_stack *stack, int *smallest, int i)
// {
// 	int j = 0;
// 	ft_putstr("get chunk");
// 	int max_number = find_max_number(stack);
// 	int min_number = find_min_number(stack);
// 	int range = max_number - min_number;
// 	int chunk = range / 20;
// 	int current_chunk = min_number;
// 	while (j < 20)
// 	{
// 		smallest[j] = current_chunk;
// 		current_chunk += chunk;
// 		j++;
// 	}
// 	if (i != -1)
// 		smallest[i] = find_smallest_number(stack);
// }

// int is_in_chunk(int number, int *smallest, int i)
// {
// 	int j = 0;

// 	while (j < 20)
// 	{
// 		if (number >= smallest[j] && number < smallest[j + 1])
// 			return (1);
// 		j++;
// 	}
// 	if (i != -1)
// 	{
// 		if (number == smallest[i])
// 			return (1);
// 	}
// 	return (0);
// }

// void sort_100(t_stack **stack_a, t_stack **stack_b)
// {
//     int i;
//     int smallest[20];
//     t_stack *current_a = *stack_a;
   
//     // Divide el stack_a en chunks de 20 y guarda el más pequeño de cada uno
//     for (i = 0; i < 5; i++)
//     {
//         get_chunk_values(*stack_a, smallest, i);
//         current_a = *stack_a;
//         // Actualiza las variables top_movements y bottom_movements para cada nodo del chunk actual
//         while (current_a != NULL)
//         {
//             if (is_in_chunk(current_a->data, smallest, i))
//                 top_and_bottom_plus_detector_smallest(&current_a);
//             current_a = current_a->next;
//         }
//     }

//     // Ordena el stack_b usando rb_or_rrb y pa hasta que esté vacío
//     while (ft_lstsize2(*stack_b) < 100)
//     {
//         get_chunk_values(*stack_b, smallest, -1);
//         current_a = *stack_a;
        
//         // Encuentra el nodo con la menor cantidad de movimientos para pasar a stack_b
//         while (current_a != NULL)
//         {
//             if (is_in_chunk(current_a->data, smallest, -1))
//             {
//                 top_and_bottom_plus_detector_smallest(&current_a);
//                 if (ft_lstsize2(*stack_b) == 0 || current_a->bottom_movements <= (*stack_b)->top_movements)
//                     pa_mov(stack_b, stack_a);
//                 else
//                     rb_or_rrb(stack_b);
//             }
//             current_a = current_a->next;
//         }
//     }

//     // Ordena los elementos restantes en el stack_b y devuelve al stack_a
//     while (!is_descending_sorted(*stack_b))
//         rb_or_rrb(stack_b);
//     while (*stack_b != NULL)
//         pa_mov(stack_a, stack_b);
// }




// void top_and_bottom_plus_detector_smallest(t_stack **stack_a)
// {
// 	t_stack *temp = *stack_a;
// 	t_stack *current_a = *stack_a;
// 	int top_movements = 0;
// 	int bottom_movements = 0;
// 	while (temp != NULL)
// 	{
// 		if (temp->data < current_a->data)
// 			top_movements++;
// 		else
// 			bottom_movements++;
// 		temp = temp->next;
// 	}
// 	current_a->top_movements = top_movements;
// 	current_a->bottom_movements = bottom_movements;
// 	current_a = current_a->next;
// }

// int find_max_number(t_stack *stack)
// {    if(!stack)
//         return 0;
//     int max_number = INT_MIN;
//     while (stack)
//     {
//         if (stack->data > max_number)
//             max_number = stack->data;
//         stack = stack->next;
//     }
//     return max_number;
// }

// int find_min_number(t_stack *stack)
// {
// 	if(!stack)
// 		return 0;
// 	int min_number = INT_MAX;
// 	while (stack)
// 	{
// 		if (stack->data < min_number)
// 			min_number = stack->data;
// 		stack = stack->next;
// 	}
// 	return min_number;
// }

// void movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *top_node, t_stack *bottom_node)
// {
    

//     if (top_node->top_movements < bottom_node->bottom_movements)
//     {
//         while (top_node != *stack_a)
//             ra_mov(stack_a);
//         if(top_node == *stack_a)
//             check_position_to_push_b(stack_a, stack_b, top_node, bottom_node);
//     }
//     else if(top_node->top_movements > bottom_node->bottom_movements)
//     {
//         while (bottom_node != *stack_a)
//         {
//             rra_mov(stack_a);
//             printf("top: %d\n", top_node->top_movements);
//             printf("bottom: %d\n", bottom_node->bottom_movements);
//         }
//         if(bottom_node == *stack_a)
//             check_position_to_push_b(stack_a, stack_b, top_node, bottom_node);
//     }
//     else if(top_node->top_movements == bottom_node->bottom_movements)
//     {
//         while (top_node != *stack_a || bottom_node != *stack_a)
//             ra_mov(stack_a);
//         if(top_node == *stack_a || bottom_node == *stack_a)
//             check_position_to_push_b(stack_a, stack_b, top_node, bottom_node);
//     }
//     top_node = NULL;
//     bottom_node = NULL;
// }


// int ft_lstsize2(t_stack *lst)
// {
// 	int i;

// 	i = 0;
// 	while (lst != NULL)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last)
// {
// 	int i;
// 	int j;
// 	int	i2;
// 	int	j2;
// 	int	pushed;
		
// 	i = 0;
// 	j = 0;
// 	i2 = 0;
// 	j2 = 0;
// 	pushed = 0;
// 	while (current_a != NULL)
// 	{
// 		if (current_a->data < (*stack_b)->data)
// 			i++;
// 		else
// 			j++;
// 		current_a = current_a->next;
// 	}
// 	while (last != NULL)
// 	{
// 		if (last->data < (*stack_b)->data)
// 			i2++;
// 		else
// 			j2++;
// 		last = last->next;
// 	}
// 	if (i < j)
// 	{
// 		while (i > 0)
// 		{
// 			ra_mov(stack_a);
// 			i--;
// 		}
// 		pb_mov(stack_a, stack_b);
// 		pushed = 1;
// 	}
// 	else if (i > j)
// 	{
// 		while (j > 0)
// 		{
// 			rra_mov(stack_a);
// 			j--;
// 		}
// 		pb_mov(stack_a, stack_b);
// 		pushed = 1;
// 	}
// 	else if (i == j)
// 	{
// 		if (i2 < j2)
// 		{
// 			while (i2 > 0)
// 			{
// 				ra_mov(stack_a);
// 				i2--;
// 			}
// 			pb_mov(stack_a, stack_b);
// 			pushed = 1;
// 		}
// 		else if (i2 > j2)
// 		{
// 			while (j2 > 0)
// 			{
// 				rra_mov(stack_a);
// 				j2--;
// 			}
// 			pb_mov(stack_a, stack_b);
// 			pushed = 1;
// 		}
// 	}
// 	if (pushed == 0)
// 	{
// 		pb_mov(stack_a, stack_b);
// 		pushed = 1;
// 	}
// }

