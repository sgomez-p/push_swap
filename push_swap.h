/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/12/16 11:44:08 by sgomez-p         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdbool.h>

typedef struct stack //definimos lo q tiene cada stack individual
{
	int 			n;
	struct stack 	*next;
}stack;

typedef struct stacks /*con esto accedemos a los stacks */
{
	int top;
	int size;
	stack *stack_a;
	stack *stack_b;
	//struct stack movements;
}stacks;

typedef struct data //definimos lo q tiene cada stack individual
{
	int size[1000];
	int	count;
}data;

void	create_stack(stacks *situ, int argc, char **argv);
void	write_stack_a(struct stack **stack_a);
void	write_stack_b(struct stack **stack_b); //hay q cambiarlo a stacks para ver

int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_validation(int argc, char **argv);
void	ft_error(void);
void	ft_nbr(const char *str);
void	ft_valid_str(const char *str);
int		ft_only_spaces(const char *str);
//void	ft_check_duplicate(data *new, stacks *stacks);
#endif