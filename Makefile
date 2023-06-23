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

CC = gcc -lreadline

CFLAGS = -Wall -Wextra -Werror

SRC = run.c Libft/libft.a tools.c ft_echo.c ft_pwd.c ft_cd.c

OBJ = $(SRC:.C=.O)

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all