# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:27:09 by sgomez-p          #+#    #+#              #
#    Updated: 2022/11/21 13:36:30 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

LIBFT			= libft.a

LIBFT_DIR		= ./Libft/

SRCS			= push_swap.c \
				

OBJS			= $(SRCS:.c=.o)

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

all: make-libft $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

make-libft:
		make -C $(LIBFT_DIR)

clean:
		rm -rf $(OBJS)
		$(MAKE) clean -C ./Libft

fclean: clean
		$(MAKE) fclean -C ./Libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean