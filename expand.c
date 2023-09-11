/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:51:26 by amdouyah          #+#    #+#             */
/*   Updated: 2023/09/11 12:27:27 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char    *get_env_value(t_mshell *sh, int i)
{
    char    *value;
    char    *tmp;

    if (sh->my_env[i])
        value = ft_strdup(ft_strchr(sh->my_env[i], '=') + 1);
    else
        value = ft_strdup("");
    tmp = ft_strdup(value);
	free(tmp);
    return (value);
}

char    *var_expand(t_mshell *sh)
{
    int     len;
    int     i;
    char    *res;

    len = ft_strlen(sh->var);
    i = 0;
    while (sh->my_env[i])
    {
        if (!ft_strncmp(sh->my_env[i], sh->var, len) && sh->my_env[i][len] == '=')
            break ;
        else
            i++;
    }
    res = get_env_value(sh, i);
    return (res);
}
void    routine(char *str, int i, t_mshell *msh, int var_size)
{
    if (str[i] == '?')
    {
        var_size = 1;
        msh->var = ft_itoa(msh->exit_status);
    }
    else
    {
        msh->var = ft_substr(str, i, var_size);
        msh->var = var_expand(msh);
    }
}
int    count_var_size(char  *str)
{
    int i;

    i = 0;
    while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i])))
        i++;
    return (i);
}
char    *expd(char *str, t_mshell *sh)
{
    int     i; 
	int     size;
	char    *tmp1;
	int     var_size;
	char    *tmp2;
    
	sh->var  = ft_strdup("");
    i = 0;
    while (str[i])
    {
		if (str[i] == '\'')
        	sh->sq++;
    	if (str[i] == '"' && sh->sq == 0)
        	sh->dq++;
        if (str[i] == '$' && str[i + 1] != '\0' && sh->sq % 2 == 0)
        {
           	size = i;
            i++;
            tmp1 = ft_substr(str, 0, size);
            var_size = count_var_size(str + i);
            routine(str, i, sh, var_size);
            tmp2 = str + (i + var_size);
            str = ft_strjoin(ft_strjoin(tmp1, sh->var), tmp2);
            i = 0;
        }
        i++;
        // free(sh->var);
    }
    return (str);
} 
char	*expansion(t_mshell *msh)
{
	int i;
	char *res;
	char *hold;
	char *command;

    res = ft_strdup("");
    hold = ft_strdup("");
    command = malloc(ft_strlen(msh->line));
    msh->sq = 0;
    msh->dq = 0;
	i = 0;
    while (msh->sp[i])
    {
        command = expd(msh->sp[i], msh);
        res = ft_strjoin(command, " ");
        hold = ft_strjoin(hold, res);
        free(res);
        i++;
    }
    return (hold);
}
