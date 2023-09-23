# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 21:18:58 by ckannane          #+#    #+#              #
#    Updated: 2023/09/23 12:52:56 by amdouyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	pars/run.c pars/tools.c pars/tool_par.c \
		pars/tool2.c pars/tool3.c pars/tool4.c pars/tool5.c pars/parsing_com.c pars/expd.c\
		execc/ft_echo.c \
		execc/ft_pwd.c execc/ft_cd.c execc/ft_export.c \
		execc/env.c execc/unset.c execc/red_tool.c \
		execc/rederection.c  execc/execve.c\
		execc/execution.c pars/handl_quote.c pars/set_com.c free.c execc/heredoc.c

OBJ = $(SRC:.c=.o)

NAME = minishell

LIBFT = Libft/libft.a

LDFLAGS = "-L/Users/amdouyah/.brew/opt/readline/lib"

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT) :
	make -C ./Libft

clean:
	@rm -rf $(OBJ)
	@make clean -C ./Libft

fclean: clean
	@make fclean -C ./Libft
	@rm -rf $(NAME)

re: fclean all