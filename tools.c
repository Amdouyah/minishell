/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:47:43 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/23 14:39:32 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_arg(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int	wd = 0;
	int n = 0;
	char **arg;

	while (str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
			i++;
		if(str[i] == '\"')
		{
			i++;
			while(str[i] && str[i] != '\"')
			{
				i++;
			}
			if(str[i] == '\"')
				wd++;
			else
			{
				printf("error arg not complete");
				return NULL;
			}
		}
		else
		{
			while(str[i] && (str[i] != ' ' && str[i] != '\r' && str[i] != '\t'))
				i++;
			wd++;
		}
	}
	printf("words nbr = %d\n",wd);
	arg = (char **)malloc(sizeof(char*) * (wd + 1));
	i = 0;
	while(j < wd)
	{
		k = 0;
		n = 0;
		while(str[i] && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
			i++;
		if(str[i] == '\"')
		{
			i++;
			while(str[i] && str[i] != '\"')
			{
				k++;
				i++;
			}
		}
		else
			while(str[i] && (str[i] != ' ' && str[i] != '\r' && str[i] != '\t'))
			{
				k++;
				i++;
			}
		arg[j] = malloc(sizeof(char) * (k + 1));
		i = i - k;
		while(str[i] && n < k)
			arg[j][n++] = str[i++];
		arg[j][n] = '\0';
		j++;
	}
	arg[j] = NULL;
	return (arg);
}