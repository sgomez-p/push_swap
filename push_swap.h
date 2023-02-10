/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/02/10 09:45:07 by sgomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


typedef struct t_stack // definimos lo q tiene cada stack individual
{
	int pos;
	int site;
	int nbr;
	int				order;
	struct t_stack *next;
}					t_stack;


typedef struct t_stacks // con esto accedemos a los stacks
{
	int size;
	t_stack *stack_a;
	t_stack *stack_b;
}					t_stacks; 

typedef struct t_chunk_size
{
	int	min;
	int	mid;
	int	max;
	int	size;
}t_chunk_sizes;

typedef struct t_chunk_item
{
	int	nbr;
	int	pos;
}t_chunk_item;
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

void				create_stack(t_stacks *situ, int argc, char **argv);
void				write_stack_a(t_stack *stack_a);
void				write_stack_b(t_stack *stack_b);
int					ft_atoi(const char *str);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_validation(int argc, char **argv);
void				ft_error(void);
void				is_nbr(const char *str);
void				ft_valid_str(const char *str);
int					ft_only_spaces(const char *str);
int					check_dup(int n, t_stack *stack);
int					get_lenstack(t_stack *stack);
void				ra_mov(t_stack **stack_a);
void				rb_mov(t_stack **stack_b);
void				rr_mov(t_stack **stack_a, t_stack **stack_b);
void				rra_mov(t_stack **stack_a);
void				rrb_mov(t_stack **stack_b);
void				rrr_mov(t_stack **stack_a, t_stack **stack_b);
void				pa_mov(t_stack **stack_a, t_stack **stack_b);
void				pb_mov(t_stack **stack_a, t_stack **stack_b);
void				sa_mov(t_stack **stack_a);
void				sb_mov(t_stack **stack_b);
void				ss_mov(t_stack **stack_a, t_stack **stack_b);
int					check_empty(t_stack *s);
void				setup_pos(t_stack *s);
void				print_stack_a(t_stack *stack_a);
void				order4(t_stack **stack_a, t_stack **stack_b);
void				order5(t_stack **stack_a, t_stack **stack_b);
void				order3(t_stack **stack_a);
void				reverseorder3(t_stack **stack_a);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);
int					get_next_move(t_stack *stack, int nbr, int len);
int					isordered(t_stack *stack);
void			order_with_chunks(t_stack **a, t_stack **b, int tot_chunks);
void			push_src_to_dts(t_stack **src, t_stack **dts);
t_chunk_item	get_chunk_next_item(t_stack *stack, int max, int stack_len);
void			prepare_pushb(t_stack **a, t_stack **b, t_chunk *chunk);
#endif