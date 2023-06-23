/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:07:29 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/23 14:38:14 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_pip *p)
{
	if (ft_strcmp(p->commad,"pwd" )!= 0)
		return ;
	char cwd[1024];  // Buffer to store the current working directory

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("%s\n", cwd);
  } else {
    perror("getcwd");
  }
}