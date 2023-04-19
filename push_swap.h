/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/04/19 15:07:19 by sgomez-p         ###   ########.fr       */
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
	int size;
	int 	data;
	struct t_stack *next;
	int top_movements;
	int bottom_movements;
	int prev;
}					t_stack;

typedef struct t_stacks // con esto accedemos a los stacks
{
	int size;
	t_stack *stack_a;
	t_stack *stack_b;
}					t_stacks;


/*void				create_stack(t_stacks *situ, int argc, char **argv);
void				write_stack_a(t_stack *stack_a);
void				write_stack_b(t_stack *stack_b);
int					ft_atoi(const char *str); */
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
//void				print_stack_a(t_stack *stack_a);
void				order4(t_stack **stack_a, t_stack **stack_b);
void				order5(t_stack **stack_a, t_stack **stack_b);
void				order3(t_stack **stack_a);
//void				print_stacks(t_stack *stack_a, t_stack *stack_b);
int					get_next_move(t_stack *stack, int nbr, int len);
int					isordered(t_stack *stack);
int					ft_atoi(const char *str);
int 				ft_isdigit(int c);
int 				ft_isspace(char c);
int 				valid_range_int(const char *str_nbr);
int 				check_nbr(char *const_str_nbr);
int					exists(int nbr, t_stack *stack);
void				bubble(t_stack **stack_a, t_stack **stack_b);
void sort_100(t_stack **stack_a, t_stack **stack_b);
void top_and_bottom_plus_detector_smallest(t_stack **stack_a);
void    check_position_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *current_a, t_stack *last);
void movements_checker_to_push_b(t_stack **stack_a, t_stack **stack_b, t_stack *top_node, t_stack *bottom_node);
int find_min_number(t_stack *stack);
int find_max_number(t_stack *stack);
int ft_lstsize2(t_stack *lst);
#endif