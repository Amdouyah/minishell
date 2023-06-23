/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:04:54 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/22 17:44:07 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Libft/libft.h"

typedef struct s_pip
{
	char	*word;
	char	*commad;
	char	**arg;
	struct s_pip	*next;
	char	*env;
	pid_t pid;
}t_pip;

char	**split_arg(char *str);
int ft_strcmp(char *s1,char *s2);
void ft_echo(t_pip *p);
int ft_strcmp(char *s1,char *s2);
void	ft_pwd(t_pip *p);
void	ft_cd(t_pip *p);
#endif