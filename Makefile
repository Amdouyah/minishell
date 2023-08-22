# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 21:18:58 by ckannane          #+#    #+#              #
#    Updated: 2023/06/23 14:39:03 by ckannane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror


SRC = pars/run.c pars/ft_split.c

OBJ = $(SRC:.C=.O)

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all