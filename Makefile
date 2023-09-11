# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 21:18:58 by ckannane          #+#    #+#              #
#    Updated: 2023/09/08 20:36:40 by amdouyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

LIBFT = libft

SRC = pars/run.c pars/expand.c

OBJ = $(SRC:.C=.O)

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJ)
		make -C $(LIBFT)
		$(CC) $(CFLAGS) libft/libft.a $(OBJ) -o $(NAME) -lreadline

clean:
	# @rm -rf libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft/libft.a

re: fclean all