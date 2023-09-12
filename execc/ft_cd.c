/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:30:39 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/12 10:23:27 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_cd(t_com *com,t_zid *zone)
{
	char cwd[1024];
	t_val *current;
	t_zid	*old_path;
	current = malloc(sizeof(t_val));
	*current = *zone->env;
	old_path = malloc(sizeof(t_zid));
	*old_path = *zone;
	int found = 0;

	while(ft_strcmp(zone->env->name,"PWD") != 0)
		zone->env = zone->env -> next;
	while(ft_strcmp(zone->exp->name,"PWD") != 0)
		zone->exp = zone->exp -> next;

	while(ft_strcmp(old_path->env->name,"OLDPWD") != 0)
		old_path->env = old_path->env -> next;
	while(ft_strcmp(old_path->exp->name,"OLDPWD") != 0)
		old_path->exp = old_path->exp -> next;

	if(com->arg[0] == NULL)
	{
		while(ft_strcmp(current->name,"HOME") != 0)
		{
			if (ft_strcmp(current->name,"HOME") == 0)
				found = 1;
			current = current -> next;
		}
		if(found == 0)
		{
			perror("cd");
        	return -1;
		}
		if (chdir(current->value) == -1) {
        perror("cd");
        return -1;
    }

	}
    else if (chdir(com->arg[0])== -1){
        perror("cd");
        return -1;
    }

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
	free(old_path->env->value);
	old_path->env->value = ft_strdup(zone->env->value);
	free(zone->env->value);
	zone->env->value = ft_strdup(cwd);
	free(old_path->exp->value);
	old_path->exp->value = ft_strdup(zone->exp->value);
	free(zone->exp->value);
	zone->exp->value = ft_strdup(cwd);
  } else {
    perror("getcwd");
  }
    return 0;
}