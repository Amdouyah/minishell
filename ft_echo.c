/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:26:50 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/23 14:38:35 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(t_pip *p)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int fl = 0;

	if (ft_strcmp(p->commad,"echo" )!= 0)
		return ;
	if (p->arg == NULL)
		return ;
	if (ft_strcmp(p->arg[i],"-n" ) == 0)
	{
		fl = 1;
		i++;
	}
	while (p->arg[i])
	{
		j = 0;
		if(x == 1)
		{
			x = 0;
			write(1," ",1);
		}
		while (p->arg[i][j])
		{
			x = 1;
			if(p->arg[i][j] == '\"' || p->arg[i][j] == '\'')
				j++;
			else
				write(1,&p->arg[i][j++],1);
		}
		i++;
	}
	if(fl == 1)
		write(1,"$",1);
	//write(1,"\n",1);
}