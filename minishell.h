/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:04:54 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/08 20:40:53 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
// #include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct s_pip
{
	char	*word;
	char	*commad;
	char	**arg;
	struct s_pip	*next;
	char	*env;
	// pid_t	 pid;
}t_pip;

typedef struct s_mshell
{
	int	exit_status;
	char *line;
	char *comm;
	char **arg;
	char **sp;
	int s_quot;
	int d_quot;
	int	arg_num;
	char **my_env;
	char *var;
	int sq;
    int dq;

}t_mshell;


// char	**split_arg(char *str);
int	ft_cher(t_mshell *msh, char c, int a);
// void	check_quote(t_mshell *msh);
int check_quote(t_mshell *msh);
void check_split(t_mshell *msh);
void exit_err(char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
int ft_strcmp(char *s1, char *s2);
int check_comm(t_mshell *msh, char *s);
char	*expansion(t_mshell *msh);
// size_t	ft_strlen(const	char *s);

// int ft_strcmp(char *s1,char *s2);
// void ft_echo(t_pip *p);
// int ft_strcmp(char *s1,char *s2);
// void	ft_pwd(t_pip *p);
// void	ft_cd(t_pip *p);

#endif