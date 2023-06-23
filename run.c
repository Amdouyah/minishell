#include "minishell.h"

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

t_pip	*ft_comnew(char	*com)
{
	t_pip	*pip;

	pip = (t_pip *)malloc(sizeof(t_pip));
	if (!pip)
		return (0);
	pip -> word = com;
	pip -> next = NULL;
	return (pip);
}

t_pip	*ft_comlast(t_pip *com)
{
	if (com == NULL)
		return (NULL);
	while (com -> next != NULL)
		com = com -> next;
	return (com);
}

void	ft_comadd_back(t_pip **com, t_pip *new)
{
	t_pip	*end;

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
char	*first_arg(t_pip *com)
{
	int i =0;
	int j = 0;
	char *command;

	while(com->word[i] && com->word[i] == ' ')
		i++;

	while(com->word[i] && com->word[i] != ' ')
	{
		j++;
		i++;
	}
	command = malloc(sizeof(char)*j+1);
	i = 0;
	while(com->word[i] && com->word[i] == ' ')
		i++;
	j= 0;
	while(com->word[i] && com->word[i] != ' ')
		command[j++] = com->word[i++];
	command[j] = '\0';
	return (command);
}
char	**find_arg(t_pip *com)
{
	int i = 0;
	int j = 0;
	int	n = 0;
	char	*re_line;
	char	**arg;

	while(com->word[i] == com->commad[i] || com->word[i] == ' ')
		i++;
	while (com->word[i])
	{
		i++;
		n++;
	}
	re_line = malloc(sizeof(char) * n + 1);
	j = 0;
	i = i - n;
	while(com->word[i])
		re_line[j++] = com->word[i++];
	arg = split_arg(re_line);
	return (arg);
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
void	read_com(t_pip *com,char **env)
{
	//int i = 0;
	com->commad = first_arg(com);
	com->env = env[2];
	//while(env[i])
	//	printf("%s\n",env[i++]);
	//printf("commadn = %s$\n",com->commad);
	//i = 0;
	if (words_count(com->word) > 1)
	{
		com->arg = find_arg(com);
		//while(com->arg[i])
		//	printf("arg = %s$\n",com->arg[i++]);
	}
}

void	track_com(char *line, t_pip *com,char **env)
{
	char **all;
	int i;
	t_pip *pip;
	i = 0;
	all = ft_split(line,'|');
	while(all[i])
	{
		pip = ft_comnew(all[i]);
		ft_comadd_back(&com,pip);
		i++;
	}
	i = 0;
	while(com)
	{
		read_com(com,env);
		//printf("%s\n",com->word);
		ft_echo(com);
		//ft_pwd(com);
		//ft_cd(com);
		com = com->next;
	}
}

int main(int ac, char **av, char **env)
{
    char* line;
	t_pip *com;
	(void)ac;
	(void)av;
	int i ;
	com = NULL;
    while (1)
	{
        line = readline("\033[31mminishell \033[0m");
		i = 0;
		if (*line)
		{
			track_com(line,com,env);
			//while(command[i])
			//	printf("You entered: %s\n", command[i++]);
			add_history(line);
			free(line);
			free(com);
    	}
    }
    return 0;
}