/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:33:12 by sgomez-p          #+#    #+#             */
/*   Updated: 2022/11/29 14:42:59 by sgomez-p         ###   ########.fr       */
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

typedef struct stack
{
	int 			n;
	struct stack 	*next;
}stack;

typedef struct situation
{
	struct stack *stack_a;
	struct stack *stack_b;
	//struct stack movements;
}situation;

void	create_stack(situation *situ, int argc, char **argv);
void	write_stack_a(struct stack *stack_a);
void	write_stack_b(struct stack *stack_b);
//void 	error_no_nbr(int argc, char **argv);
//int		check_is_nbr(char **argc);
int    	ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
#endif