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

//# include <libft/libft.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int n;
	struct stack *next;
}stack;

typedef struct situation
{
	struct stack stack_a;
	struct stack stack_b;
	//struct stack movements;
}situation;

void	create_stack(situation *situ, int argc, char **argv)
int	write_stack_a(stack *stack);
int	write_stack_b(stack *stack);
void error_no_nbr(int argc, char **argv);
int	check_is_nbr(char **argc);
#endif