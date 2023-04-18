/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:47:13 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/04/18 18:52:47 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb_or_rrb (t_stack **stack_b)
{
	int i = 0;
	int j = 0;
	t_stack *temp = *stack_b;
	while (temp != NULL)
	{
		if (temp->data < (*stack_b)->data)
			i++;
		else
			j++;
		temp = temp->next;
	}
	if (i < j)
	{
		while (i > 0)
		{
			rb_mov(stack_b);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			rrb_mov(stack_b);
			j--;
		}
	}
}

int *save_20_smallest_chunk(t_stack *stack_a)
{
    int *smallest = malloc(sizeof(int) * 20);
    int i = 0, j = 0;
    t_stack *temp = stack_a;

    // Guardamos los primeros 20 elementos en el arra_movy smallest
    while (i < 20 && temp != NULL)
    {
        smallest[i] = temp->data;
        temp = temp->next;
        i++;
    }

    // Ordenamos el arra_movy smallest con el algoritmo de burbuja
    i = 0;
    while (i < 19)
    {
        j = 0;
        while (j < 19 - i)
        {
            if (smallest[j] < smallest[j + 1])
            {
                int tmp = smallest[j];
                smallest[j] = smallest[j + 1];
                smallest[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }

    // Recorremos el resto del stack y actualizamos el arra_movy smallest si encontramos un elemento menor
    temp = stack_a;
    while (temp != NULL)
    {
        i = 19;
        while (i >= 0)
        {
            if (temp->data < smallest[i])
            {
                // Desplazamos los elementos mayores hacia la derecha para hacer espacio para el nuevo elemento
                j = 0;
                while (j < i)
                {
                    smallest[j] = smallest[j + 1];
                    j++;
                }

                // Insertamos el nuevo elemento en la posición correcta
                smallest[i] = temp->data;
                break;
            }
            i--;
        }
        temp = temp->next;
    }

    return smallest;
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void sort_100(t_stack **stack_a, t_stack **stack_b)
{
    int	*smallest = save_20_smallest_chunk(*stack_a);
    printf("Esto es smallest: ");
    for (int i = 0; i < 20; i++)
        printf("%d ", smallest[i]);
    printf("\n");
    t_stack *current_a = *stack_a;
    t_stack *current_a_last = get_last_node(*stack_a);

    int i = 0;
    while (i < 6) // 
    {
        top_and_bottom_plus_detector_smallest(stack_a, stack_b, current_a, current_a_last, smallest);
        printf("esta es la i jeje: %d\n", i);
        i++;
    }
}


void top_and_bottom_plus_detector_smallest(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	t_stack *temp = *stack_a;
	int top_movements = 0;
	int bottom_movements = 0;
	while (temp != NULL)
	{
		if (temp->data == smallest[0])
		{
			current_a = temp;
			break;
		}
		temp = temp->next;
	}
	while (current_a != *stack_a)
	{
		ra_mov(stack_a);
		top_movements++;
	}
	while (current_a != last)
	{
		rra_mov(stack_a);
		bottom_movements++;
	}
	current_a->top_movements = top_movements;
	current_a->bottom_movements = bottom_movements;
	movements_checker_to_push_b(stack_a, stack_b, current_a, last, smallest);
}

int find_max_number(t_stack *stack)
{    if(!stack)
        return 0;
    int max_number = INT_MIN;
    while (stack)
    {
        if (stack->data > max_number)
            max_number = stack->data;
        stack = stack->next;
    }
    return max_number;
}

int fin_min_number(t_stack *stack)
{
	if(!stack)
		return 0;
	int min_number = INT_MAX;
	while (stack)
	{
		if (stack->data < min_number)
			min_number = stack->data;
		stack = stack->next;
	}
	return min_number;
}

void movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *top_node, t_stack *bottom_node, int *smallest)
{
    

    if (top_node->top_movements < bottom_node->bottom_movements)
    {
        while (top_node != *stack_a)
            ra_mov(stack_a);
        if(top_node == *stack_a)
            check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
    }
    else if(top_node->top_movements > bottom_node->bottom_movements)
    {
        while (bottom_node != *stack_a)
        {
            rra_mov(stack_a);
            printf("top: %d\n", top_node->top_movements);
            printf("bottom: %d\n", bottom_node->bottom_movements);
        }
        if(bottom_node == *stack_a)
            check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
    }
    else if(top_node->top_movements == bottom_node->bottom_movements)
    {
        while (top_node != *stack_a || bottom_node != *stack_a)
            ra_mov(stack_a);
        if(top_node == *stack_a || bottom_node == *stack_a)
            check_position_to_push_b(stack_a, stack_b, top_node, bottom_node, smallest);
    }
    top_node = NULL;
    bottom_node = NULL;
}


int ft_lstsize2(t_stack *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last, int *smallest)
{
	int i;
	int j;
	int	i2;
	int	j2;
	int	pushed;
		
	i = 0;
	j = 1;
	i2 = 0;
	j2 = 1;
	pushed = 0;
	int	movements = 0;
	int	h = 0;
	int	movements2 = 0;
	int	h2 = 0;
	t_stack *temp_b = *stack_b;
	int *smallest_pushed = malloc(sizeof(int) * 20);
	while(temp_b != NULL)
	{
		smallest_pushed[pushed] = temp_b->data;
		temp_b = temp_b->next;
		pushed++;
	}
	if (current_a == *stack_a)
	{
		if(*stack_b == NULL)
			pb_mov(stack_a, stack_b);
		else if(current_a->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
		{
			pb_mov(stack_a, stack_b);
			rb_mov(stack_b);
		}
		else if(current_a->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			pb_mov(stack_a, stack_b);
		else if(current_a->data > (*stack_b)->data && current_a->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b))
			pb_mov(stack_a, stack_b); 
		else if(current_a->data < get_last_node(*stack_b)->data && current_a->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
		{
			pb_mov(stack_a, stack_b);
			rb_mov(stack_b);
		}
		else
		{
			while(smallest_pushed[i])
			{
				while(smallest_pushed[j])
				{
					if(!(current_a->data < smallest_pushed[i] && current_a->data > smallest_pushed[j]))
						movements++;
					while (h < movements + 1)
					{
						rb_or_rrb(stack_b);
						h++;
					}
					if (current_a->data < get_last_node(*stack_b)->data && current_a->data > (*stack_b)->data)
						pb_mov(stack_a, stack_b);
					j++;
				}
				i++;
			}
		}
	}
		if(last == *stack_a)
		{
			if(*stack_b == NULL)
				pb_mov(stack_a, stack_b);
			else if(last->data < (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
			{
				pb_mov(stack_a, stack_b);
				rb_mov(stack_b);
			}
			else if(last->data > (*stack_b)->data && ft_lstsize2(*stack_b) == 1)
				pb_mov(stack_a, stack_b);
			else if(last->data > (*stack_b)->data && last->data >= find_max_number(*stack_b) && (*stack_b)->data == find_max_number(*stack_b)) 
		   		pb_mov(stack_a, stack_b); 
			else if(last->data < get_last_node(*stack_b)->data && last->data <= find_min_number(*stack_b) && get_last_node(*stack_b)->data == find_min_number(*stack_b))
			{
				pb_mov(stack_a, stack_b);
				rb_mov(stack_b);
			}
			else
			{
				while(smallest_pushed[i2])
				{
					while(smallest_pushed[j2])
					{
						if(!(last->data < smallest_pushed[i2] && last->data > smallest_pushed[j2]))
							movements2++;
						while (h2 < movements2 + 1)
						{
							rb_or_rrb(stack_b);
							h2++;
						}
						if (last->data < get_last_node(*stack_b)->data &&  last->data > (*stack_b)->data)
							pb_mov(stack_a, stack_b);
						j2++;
					}
					i2++;
				}
			}

		}
	free(smallest_pushed);
		//Tal vez debo utilizar el mismo contador para last y para current_a ya que lo que quiero es que sume 1 cada vez que se haya utilizado un smallest?

}

