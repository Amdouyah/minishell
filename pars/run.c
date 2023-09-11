/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:38:47 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/11 12:04:08 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void exit_err(char *s)
{
	printf("%s\n", s);
	// exit(1);
}

char *return_without_quote(char *str)
{
	int	i;
	int j;
	int	q;
	char	*res;
	
	i = 0;
	q = 0;
	while(str[i])
	{
		if (str[i] == '\'')
			q++;
		i++;
	}
	res = malloc(ft_strlen(str) - q);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'')
			res[j++] = str[i];
		i++;
	}
	return (res);
}

int check_quote(t_mshell *msh)
{
	int		i;
	char	flag;
	
	i = 0;
	flag = 0;
	while (msh->line[i])
	{
		if ((msh->line[i] == '"' || msh->line[i] == '\'') && flag == 0)
		{
			flag = msh->line[i];
			i++;
		}
		else if (msh->line[i] == flag && flag)
			flag = 0;
		i++;
	}
	if (flag)
		return (1);
	return (0); 
}

void check_split(t_mshell *msh)
{
	if (check_quote(msh))
		ft_putstr_fd("Syntax error\n", 2);
	msh->sp = ft_split(msh->line, ' ');
	char *expand;
	expand = expansion(msh);	
	puts(expand);
	// int i = 0;
	// exit('h');
	
	// msh->comm = ft_strdup(msh->sp[0]);
	// msh->comm = remove_q(msh->comm);
	// puts(msh->comm);
	// msh->comm = ft_strjoin(msh->comm, msh->sp[0]);
	// if (!(check_comm(msh, "echo") || check_comm(msh, "cd") || check_comm(msh, "pwd") || check_comm(msh, "exit") || check_comm(msh, "export") || check_comm(msh, "unset") || check_comm(msh, "env")))
	// 	exit_err("command not found");
}

int check_comm(t_mshell *msh, char *s)
{
	if (!ft_strcmp(msh->comm , s))
		return 0;
	else
		return 1;
}

char	**ft_strdup_env(char **env)
{
	int		i;
	int		j;
	char	**res;

	res = NULL;
	j = 0;
	i = 0;
	while (env[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		res[j] = ft_strdup(env[j]);
		j++;
	}
	res[i] = NULL;
	return (res);
}

int	main(int __unused ac, char __unused **av, char **env)
{
	t_mshell	*msh;

	msh = malloc(sizeof(t_mshell));
	msh->my_env = ft_strdup_env(env);
	while (1)
	{
		msh->line = readline("minishell-> ");
		if(!msh->line)	
		{
			free(msh);
			exit (1);
		}
		add_history(msh->line);
		check_split(msh);
		// free(msh->line);
	}
}
