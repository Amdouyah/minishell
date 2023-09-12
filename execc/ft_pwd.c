/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:07:29 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/09 21:59:06 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_val *env)
{
	char cwd[1024];

while(ft_strcmp(env->name,"PWD") != 0)
		env = env -> next;
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
	free(env->value);
	env->value = ft_strdup(cwd);
    printf("%s\n", env->value);
  } else {
    perror("getcwd");
  }
}