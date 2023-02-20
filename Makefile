# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:27:09 by sgomez-p          #+#    #+#              #
#    Updated: 2023/02/20 12:23:06 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
SRCS			= ft_putchar.c ft_putnbr.c ft_putstr.c ft_atoi.c push_swap.c validate.c \
				movements.c order.c chunk.c

OBJS			= $(SRCS:.c=.o)
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -Wincompatible-pointer-types 
all: $(NAME)
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)
git: fclean
	@echo "\t${BIPurple}>>Push To Git<<${NoColor}"
	@git add . ;
	@read -p "Name the commit: " commit ;\
	git commit -m "$$commit" ;\
	git push origin master ;

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
#-fsanitize=address -g
re: fclean all
help:
	@echo "\t${BIPurple}git:${NoColor} Push to git."
.PHONY: all re clean fclean