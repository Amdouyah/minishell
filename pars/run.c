/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:38:47 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/23 14:38:52 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void exit_err(char *s)
{
	printf("%s\n", s);
	exit(1);
}

void check_split(t_mshell *msh)
{
	msh->sp = ft_split(msh->line, ' ');
	// msh->comm =  msh->sp[0];
	msh->comm = ft_strjoin(msh->comm, msh->sp[0]);
	// printf("hello\n");
	if (!(check_comm(msh, "echo") || check_comm(msh, "cd") || check_comm(msh, "pwd") || check_comm(msh, "exit") || check_comm(msh, "export") || check_comm(msh, "unset") || check_comm(msh, "env")))
		exit_err("command not found");
	else	
		printf("good\n");
}

int ft_strcmp(char *s1, char *s2)
{
	printf("hello\n");

	int i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int check_comm(t_mshell *msh, char *s)
{
	if (!ft_strcmp(msh->comm , s))
		return 0;
	else
		return 1;
}

// split 
// check the first array should be a command else error


int main(void)
{
	t_mshell *msh = NULL;


	while (1)
	{
	// printf("hello\n");
	msh = malloc(sizeof(t_mshell));
	msh->line = readline("\033[31mminishell \033[0m");
	if(msh->line)
	{
		
		// printf("hello\n");
		check_split(msh);
	}
		add_history(msh->line);
		free(msh->line);
		// if (!msh->line)
		// {

		// 	printf("empty msh->line\n");
		// 	exit (1);
		// }
		// else
		// printf("%s",msh->line);
		// check_split(msh->line);
	}
}