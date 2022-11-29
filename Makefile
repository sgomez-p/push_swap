# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:27:09 by sgomez-p          #+#    #+#              #
#    Updated: 2022/11/29 14:46:43 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
SRCS			= ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi.c movements.c push_swap.c
OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)
clean:
		rm -rf $(OBJS)
fclean: clean
		rm -rf $(NAME)
		rm -rf push_swap.a
		rm -rf push_swap
# wclean:
# 		del $(OBJS)
# wfclean: clean
# 		del $(NAME)
# 		del push_swap.a
# 		del push_swap
re: fclean all
.PHONY: all re clean fclean