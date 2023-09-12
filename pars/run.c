/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:38:47 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/12 17:13:26 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *return_without_quote(char *str,char del)
{
	int	i;
	int j;
	int	q;
	char	*res;

	i = 0;
	q = 0;
	while(str[i])
	{
		if (str[i] == del)
			q++;
		i++;
	}
	res = malloc(ft_strlen(str) - q);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != del)
			res[j++] = str[i];
		i++;
	}
	return (res);
}

int    count_var_size(char  *str)
{
    int i;

    i = 0;
    while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i])))
        i++;
    return (i);
}

//char    *get_env_value(t_mshell *sh, int i)
//{
//    char    *value;
//    char    *tmp;

//    if (sh->my_env[i])
//        value = ft_strdup(ft_strchr(sh->my_env[i], '=') + 1);
//    else
//        value = ft_strdup("");
//    tmp = ft_strdup(value);
//	free(tmp);
//    return (value);
//}

char    *var_expand(t_com *sh,t_val *env)
{
    int     len;
    int     i;
    char    *res;

    len = ft_strlen(sh->var);
    i = 0;
    while (env)
    {
        if (ft_strcmp(sh->var,env->name) == 0)
            break ;
        else
            env = env -> next;
    }
	if(env->value != NULL)
    	res = ft_strdup(env->value);
	else
		res = ft_strdup("");
    return (res);
}

void    routine(char *str, int i, t_com *msh, int var_size, t_val *env)
{
    if (str[i] == '?')
    {
        var_size = 1;
        msh->var = ft_itoa(msh->exit_status);
    }
    else
    {
        msh->var = ft_substr(str, i, var_size);
        msh->var = var_expand(msh,env);
    }
}

int check_q(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

char    *expd(char *str, t_com *sh, t_val *env)
{
    int     i;
	int     size;
	char    *tmp1;
	int     var_size;
	char    *tmp2;

	sh->var = ft_strdup("");
    i = 0;
	//tmp1 = ft_strdup("");
	//tmp2 = ft_strdup("");
	//printf("2");
	//exit(0);
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
            routine(str, i, sh, var_size,env);
            tmp2 = str + (i + var_size);
            str = ft_strjoin(ft_strjoin(tmp1, sh->var), tmp2);
            i = 0;
        }
        i++;
        // free(sh->var);
    }
    return (str);
}

char	*expansion(t_com *msh, t_val *env,char	*line)
{
	int i;
	char *res;
	char *hold;
	char *command;
    res = ft_strdup("");
    hold = ft_strdup("");
    command = malloc(ft_strlen(line));
    msh->sq = 0;
    msh->dq = 0;
	i = 0;
    while (msh->sp[i])
    {
        command = expd(msh->sp[i], msh, env);
        res = ft_strjoin(command, " ");
        hold = ft_strjoin(hold, res);
        free(res);
        i++;
    }
    return (hold);
}

int check_quote(char *line)
{
	int		i;
	char	flag;

	i = 0;
	flag = 0;
	while (line[i])
	{
		if ((line[i] == '"' || line[i] == '\'') && flag == 0)
		{
			flag = line[i];
			i++;
		}
		else if (line[i] == flag && flag)
			flag = 0;
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int ft_strcmp(char *s1,char *s2)
{
	int	i;
	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	first_world(char *line, char *com)
{
	int i =0;
	while (com[i])
	{
		if(com[i] != line[i])
			return 0;
		i++;
	}
	return 1;
}

t_com	*ft_comnew(char	*line)
{
	t_com	*com;

	com = (t_com *)malloc(sizeof(t_com));
	if (!com)
		return (0);
	com -> word = line;
	com -> next = NULL;
	return (com);
}

t_com	*ft_comlast(t_com *com)
{
	if (com == NULL)
		return (NULL);
	while (com -> next != NULL)
		com = com -> next;
	return (com);
}

void	ft_comadd_back(t_com **com, t_com *new)
{
	t_com	*end;

	if (com == NULL || new == NULL)
		return ;
	if (*com == NULL)
	{
		*com = new;
		return ;
	}
	end = ft_comlast(*com);
	end -> next = new;
	new -> next = NULL;
}

int	words_count(char *str)
{
	int i = 0;
	int wd = 0;
	while (str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\r' || str[i] == '\t'))
			i++;
		if(str[i] && (str[i] != ' ' && str[i] != '\r' && str[i] != '\t'))
			wd++;
		while(str[i] && (str[i] != ' ' && str[i] != '\r' && str[i] != '\t'))
			i++;
	}
	return wd;
}


char	*ft_strjoin_env(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	if (s1 == NULL )
		return ((char *)s2);
	if (s2 == NULL )
		return ((char *)s1);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '/';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char **get_path(char *command, t_val *env)
{
	int i;
	char	*str;
	char	**slp;
	i = 0;
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
			str = ft_strdup(env->value);
		env = env -> next;
	}
	slp = ft_split(str,':');
	free(str);
	while(slp[i])
	{
		slp[i] = ft_strjoin_env(slp[i],command);
		//printf("%s\n",slp[i]);
		i++;
	}
	return (slp);
}

char **pas_env(t_val *env)
{
    char **inenv;
    t_val *current = env;
    int len_list = 0;

    while (current)
    {
        len_list++;
        current = current->next;
    }

    inenv = (char **)malloc(sizeof(char *) * (len_list + 1));

    if (!inenv)
        return NULL;

    current = env;
    int i = 0;

    while (current)
    {
        inenv[i] = ft_strdup(current->content);
        current = current->next;
        i++;
    }
    inenv[i] = NULL;
    return inenv;
}

int my_access(const char *path, int mode) {
    if (access(path, mode) == 0) {
        return 0; // Access granted
    } else {
        return -1; // Access denied or file doesn't exist
    }
}

int	search_path(t_val *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, "PATH") == 0)
			return (1);
		env = env -> next;
	}
	return (0);
}

void execute_command(char *command, char **arguments, t_val *env) {
    char **path;
    int i = 0;
	char **env_set;
	env_set = pas_env(env);
    pid_t pid = fork();
    if (pid == 0) {
		if (my_access(command, X_OK) == 0) {
        		execve(command, arguments, env_set);
        		perror("execve");
        		exit(126);
			}
		if(search_path(env) == 1)
    		path = get_path(command, env);
		else
			ft_putendl_fd("command not found:", 1), exit(127);
		while (path[i])
		{
    		if (my_access(path[i], X_OK) == 0) {
        		execve(path[i], arguments, env_set);
        		perror("execve");
        		exit(126);
			}
			i++;
		}
		ft_putendl_fd("command not found", 1), exit(127);
    } else if (pid > 0)
        wait(NULL);
	else
        perror("fork");
}

char	*set_command(char **slp)
{
	int i = 0;
	while (slp[i])
	{
		if((ft_strcmp(slp[i],">") == 0 || ft_strcmp(slp[i],">>") == 0 \
		|| ft_strcmp(slp[i],"<") == 0 || ft_strcmp(slp[i],"<<") == 0 ) && slp[i + 2] != NULL)
			return(ft_strdup(slp[i + 2]));
		i++;
	}
	return(ft_strdup(slp[0]));
}

void read_com(t_com *com,t_val __unused *env,char __unused *line) {
    int i = 0;
	char *tmp;
    com->sp = ft_split(com->word, ' ');
	tmp = expansion(com,env,line);
	tmp = return_without_quote(tmp,'\"');
	com->slp = ft_split(tmp, ' ');
	com->red = malloc(sizeof(t_red));
    com->commad = set_command(com->slp);
    int num_args = 0;
	if((ft_strcmp(com->slp[0],"<<") == 0) || (ft_strcmp(com->slp[0],"<") == 0))
			i = i + 2;
    while (com->slp[i]) {
		if((ft_strcmp(com->slp[i],">") == 0 || ft_strcmp(com->slp[i],">>") == 0 \
		|| ft_strcmp(com->slp[i],"<") == 0 || ft_strcmp(com->slp[i],"<<") == 0 ))
			break ;
        num_args++;
        i++;
    }
	if (num_args == 0)
		return;
	com->after_red = (char **)malloc((num_args + 1) * sizeof(char *));
	if(!com->after_red)
		com->after_red = NULL;
    com->arg = (char **)malloc((num_args) * sizeof(char *));
	if(!com->arg)
		com->arg = NULL;
    if (com->arg == NULL)
	{
        perror("Memory allocation error");
        return;
    }
    i = 1;
    int j = 0;
    while (j < num_args - 1)
        com->arg[j++] = ft_strdup(com->slp[i++]);
    com->arg[j] = NULL;
	j = 0;
	while (j < num_args)
	{
        com->after_red[j] = ft_strdup(com->slp[j]);
		j++;
	}
    com->after_red[j] = NULL;
}

void	exe_builtins(t_com *com , t_zid *zone)
{
	if (strcmp(com->commad, "cd") == 0) {
        ft_cd(com,zone);
    } else if (strcmp(com->commad, "pwd") == 0) {
        ft_pwd(zone->env);
    }
		else if (strcmp(com->commad, "echo" ) == 0 && com->arg != NULL) {
        ft_echo(com);
	}
	else if (strcmp(com->commad, "export") == 0) {
        ft_export(com,zone);
	}
	else if (strcmp(com->commad, "unset") == 0) {
            ft_unset(com,zone);
		}
		else if (strcmp(com->commad, "exit") == 0) {
           printf("Exiting the minishell.\n");
       		exit(0);
		}
		else if (strcmp(com->commad, "env") == 0)
		{
			while(zone->env)
			{
       		printf("%s=%s\n",zone->env->name,zone->env->value);
			zone->env = zone->env->next;
			}
		}
}

int		vip_command_check(t_com *com)
{
	if (strcmp(com->commad, "cd") == 0 || strcmp(com->commad, "pwd") == 0 \
	|| strcmp(com->commad, "echo" ) == 0 || strcmp(com->commad, "export") == 0 \
	|| strcmp(com->commad, "unset") == 0 || strcmp(com->commad, "env") == 0 \
	|| strcmp(com->commad, "exit") == 0)
		return(1);
	else
		return(0);
}

int	how_much_com(t_com *com)
{
	int i = 0;
	while(com)
	{
		if(*com->commad)
			i++;
		com = com->next;
	}
	return (i);
}

void	turn_on(t_com *com, t_zid *zone)
{
	if(search_for_redirection(com) != 0)
	{
		apply_fd(com,zone);
		return ;
	}
	if (vip_command_check(com) == 1)
		exe_builtins(com,zone);
	else
        execute_command(com->commad,com->after_red,zone->env);
}

void intial_com(t_com *com, t_val *env, char *line)
{
	while(com)
	{
		read_com(com,env,line);
		com = com->next;
	}
}

void	exe_with_fork(t_com *com,t_zid	*zone)
{
	pid_t child_pid;
    int status;
	int fid[2];
	int prev_fid = -1;
	while(com)
	{
		if (pipe(fid) == -1) {
    	    perror("come");
    	    exit(EXIT_FAILURE);
    	}
		child_pid = fork();
    	if (child_pid == 0) {
			if (prev_fid != -1) {
                    dup2(prev_fid, STDIN_FILENO);
                    close(prev_fid);
                }
			if (com->next != NULL) {
                    dup2(fid[1], STDOUT_FILENO);
                }
			turn_on(com,zone);
            close(fid[0]);
			exit(0);
		}
		else
		{
			if (prev_fid != -1) {
                    close(prev_fid);
                }
			prev_fid = fid[0];
			close(fid[1]);
    		waitpid(child_pid, &status, 0);
		}
        	com = com->next;
	}
	if (prev_fid != -1) {
            close(prev_fid);
        }
}

void	track_com(char *line, t_com *com,t_zid *zone)
{
	char **all;
	int i;
	t_com *index;
	if (check_quote(line))
		ft_putstr_fd("Syntax error\n", 2);
	i = 0;
	all = ft_split(line,'|');
	while(all[i])
	{
		index = ft_comnew(all[i]);
		ft_comadd_back(&com,index);
		i++;
	}
	i = 0;
	intial_com(com,zone->env,line);
	if(how_much_com(com) > 1 || search_for_redirection(com) != 0)
		exe_with_fork(com,zone);
	else
		turn_on(com,zone);
}

int ctrlDPressed = 0;


void sigintHandler(int signum) {
    if (signum == SIGINT) {
        printf("\n");
		rl_on_new_line();
    	rl_redisplay();
        return;
    }
}


int main(int ac, char **av, char **env)
{
    char* line;
	t_com *com;
	(void)ac;
	(void)av;
	t_zid *zone;
	t_zid *current = NULL;
	current = malloc(sizeof(t_zid));
	zone = malloc(sizeof(t_zid));
	com = NULL;
	//(void)env;
	zone->env = int_env(env);
	zone->exp = int_env(env);
    signal(SIGQUIT, SIG_IGN);
    while (1) {
		*current = *zone;
 		signal(SIGINT, sigintHandler);
        line = readline("[minishell] $> ");

        if (line == NULL) {
            printf("Exiting The MINISHELL...\n");
			break;
		}

        if (*line) {
            track_com(line,com,current);
            add_history(line);
        }

        free(line);
    }
    return 0;
}