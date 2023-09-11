# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 16:14:11 by amdouyah          #+#    #+#              #
#    Updated: 2023/09/11 15:45:02 by amdouyah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC = ./ft_atoi.c \
	  ./ft_bzero.c \
	  ./ft_calloc.c\
	  ./ft_isalnum.c \
	  ./ft_isalpha.c \
	  ./ft_isascii.c \
	  ./ft_isdigit.c \
	  ./ft_isprint.c \
	  ./ft_itoa.c \
	  ./ft_memchr.c\
	  ./ft_memcmp.c\
	  ./ft_memcpy.c\
	  ./ft_memmove.c\
	  ./ft_memset.c\
	  ./ft_putchar_fd.c\
	  ./ft_putnbr_fd.c\
	  ./ft_putstr_fd.c\
	  ./ft_putendl_fd.c\
	  ./ft_split.c\
	  ./ft_strchr.c\
	  ./ft_strdup.c\
	  ./ft_striteri.c\
	  ./ft_strjoin.c\
	  ./ft_strlcat.c\
	  ./ft_strlcpy.c\
	  ./ft_strlen.c\
	  ./ft_strmapi.c\
	  ./ft_strcmp.c\
	  ./ft_strncmp.c\
	  ./ft_strnstr.c\
	  ./ft_strrchr.c\
	  ./ft_strtrim.c\
	  ./ft_substr.c\
	  ./ft_tolower.c\
	  ./ft_toupper.c\
	  
OBJ = $(SRC:.c=.o)
%.o : %.c #stem
		$(CC) $(FLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJ)
		ar -rcs $@ $^
		
clean :
	rm -rf *.o
fclean :	clean
	rm -rf libft.a
re : all fclean
