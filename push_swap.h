/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2023/01/23 09:50:57 by sgomez-p         ###   ########.fr       */
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
	struct t_stack	*next;
}					t_stack;

typedef struct t_stacks //con esto accedemos a los stacks
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;
}			t_stacks;

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
void order5(t_stack **stack_a, t_stack **stack_b);
void 	order3(t_stack **stack_a);
int 	get_lenstack(t_stack *stack);
long	biggest_finder(t_stack *stack);
long	small_finder(t_stack *stack);
void	ra_mov(t_stack **stack_a);
void	rb_mov(t_stack **stack_b);
void	rr_mov(t_stacks *s);
void	rra_mov(t_stack **stack_a);
void	rrb_mov(t_stack **stack_b);
void	rrr_mov(t_stacks *s);
void	pa_mov(t_stack **stack_a, t_stack **stack_b);
void	pb_mov(t_stack **stack_a, t_stack **stack_b);
void	sa_mov(t_stack **stack_a);
void	sb_mov(t_stack **stack_b);
void	ss_mov(t_stacks *s);
int		check_empty(t_stack *s);
void 	setup_pos(t_stack *s);
void 	site_pos(t_stack *s);
void 	find_smallest_numbers(t_stack **stack_a, int *pos1, int *pos2);
void 	print_stack_a(t_stack *stack_a);
void order4(t_stack **stack_a, t_stack **stack_b);
void print_stacks(t_stack *stack_a, t_stack *stack_b);

//void	ft_check_duplicate(data *new, stacks *stacks);
#endif