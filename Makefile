# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:27:09 by sgomez-p          #+#    #+#              #
#    Updated: 2023/01/11 15:00:59 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
SRCS			= ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi.c push_swap.c validate.c \
				movements.c order.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Wincompatible-pointer-types -fsanitize=address -g
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