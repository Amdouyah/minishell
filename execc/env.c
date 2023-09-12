/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:03:00 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/01 17:19:20 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_val	*ft_vallast(t_val *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

char *save_after_equal(char *input)
{
	int i =0;
	int j=0;
	char *saved;
	int lenght = ft_strlen(input);
	while(input[i] && input[i] != '=')
		i++;
	if(input[i+1] == '\0')
		return NULL;
	j =  lenght - i++;
	saved = malloc(sizeof(char)*j+1);
	j = 0;
	while(i < lenght)
	{
		saved[j++] = input[i++];
	}
	saved[j] = '\0';
	return(saved);
}

char *save_before_equal(char *input)
{
	int i =0;
	int j=0;
	char *saved;
	while(input[i] && input[i] != '=')
		i++;
	saved = malloc(sizeof(char)*i+1);
	while(j < i)
	{
		saved[j] = input[j];
		j++;
	}
	saved[j] = '\0';
	return(saved);
}


t_val	*ft_val_re_new(char*content)
{
	t_val	*node;

	node = (t_val *)malloc(sizeof(t_val));
	if (!node)
		return (0);
	node -> content = content;
	node->name = save_before_equal (node -> content);
	node->value = save_after_equal (node -> content);
	node -> next = NULL;
	return (node);
}

void	ft_valadd_back(t_val **val, t_val *new)
{
	t_val	*end;

	if (val == NULL || new == NULL)
		return ;
	if (*val == NULL)
	{
		*val = new;
		return ;
	}
	end = ft_vallast(*val);
	end -> next = new;
	new -> next = NULL;
}

t_val	*int_env(char **env)
{
	t_val *zone = NULL;
	t_val *index;
	int i = 0;
	while(env[i])
	{
		index = ft_val_re_new(env[i++]);
		ft_valadd_back(&zone,index);
	}
	return (zone);
}