/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/26 12:58:18 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

typedef struct t_stack //definimos lo q tiene cada stack individual
{
	int				n;
	int				pos;
	int				site;
	int				order;
	struct t_stack	*next;
}					t_stack;

typedef struct t_stacks //con esto accedemos a los stacks
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_stacks;

// chunkeada
typedef struct t_chunk_size
{
	int	min;
	int	mid;
	int	max;
	int	size;
}			t_chunk_sizes;

typedef struct t_chunk_item
{
	int	nbr;
	int	pos;
}				t_chunk_item;
typedef struct t_stack_chunk_stats
{
	int	min;
	int	max;
	int	first;
	int	second;
	int	last;
}t_stack_stats;
typedef struct t_chunk
{
	t_chunk_item	item;
	t_chunk_sizes	sizes;
}t_chunk;

void	create_stack(t_stacks *situ, int argc, char **argv);
void	write_stack_a(t_stack *stack_a);
void	write_stack_b(t_stack *stack_b);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_validation(int argc, char **argv);
void	ft_error(void);
void	ft_nbr(const char *str);
void	ft_valid_str(const char *str);
int		ft_only_spaces(const char *str);
int		check_dup(int n, t_stack *stack);
int 	get_lenstack(t_stack *stack);
long	biggest_finder(t_stack *stack);
long	small_finder(t_stack *stack);
void	ra_mov(t_stack **stack_a);
void	rb_mov(t_stack **stack_b);
void	rr_mov(t_stack **stack_a, t_stack **stack_b) ;
void	rra_mov(t_stack **stack_a);
void	rrb_mov(t_stack **stack_b);
void	rrr_mov(t_stack **stack_a, t_stack **stack_b) ;
void	pa_mov(t_stack **stack_a, t_stack **stack_b);
void	pb_mov(t_stack **stack_a, t_stack **stack_b);
void	sa_mov(t_stack **stack_a);
void	sb_mov(t_stack **stack_b);
void	ss_mov(t_stack **stack_a, t_stack **stack_b) ;
int		check_empty(t_stack *s);
void 	setup_pos(t_stack *s);
void 	site_pos(t_stack *s);
void 	find_smallest_numbers(t_stack **stack_a, int *pos1, int *pos2);
void 	print_stack_a(t_stack *stack_a);
void 	order4(t_stack **stack_a);
void 	order5(t_stack **stack_a, t_stack **stack_b);
void 	order3(t_stack **stack_a);
void	reverseorder3(t_stack **stack_a);
void 	print_stacks(t_stack *stack_a, t_stack *stack_b);
void 	quicksort(t_stack **stack_a, t_stack **stack_b, int low, int high);
int partition(t_stack **stack_a, t_stack **stack_b, int low, int high);
int find_pivot(t_stack **stack_a, int low, int high);
void add_elem(t_stack **stack, int elem);
void divide_b(t_stack **stack_b, t_stack **stack_a);
void order500(t_stack **stack_a, t_stack **stack_b, int size);
//void	ft_check_duplicate(data *new, stacks *stacks);
#endif