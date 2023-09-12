/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:46:14 by ckannane          #+#    #+#             */
/*   Updated: 2023/09/12 16:37:45 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	search_for_redirection(t_com *com)
{
	int i;
	int i_input = 0;
	int i_output = 0;
	i = 0;
	while(com->slp[i])
	{
		if(ft_strcmp(com->slp[i],">") == 0)
			i_output++;
		else if(ft_strcmp(com->slp[i],"<") == 0)
			i_input++;
		else if(ft_strcmp(com->slp[i],">>") == 0)
			i_output++;
		else if(ft_strcmp(com->slp[i],"<<") == 0)
			i_input++;
		i++;
	}
	if(i_input > 0 || i_output > 0)
		return 1;
	return(0);
}

char	*detect_file(char **spl)
{
	char *pick;
	int i = 0;
	while(spl[i])
	{
		if(ft_strcmp(spl[i],">") == 0 || ft_strcmp(spl[i],">>") == 0 \
		|| ft_strcmp(spl[i],"<") == 0 || ft_strcmp(spl[i],"<<") == 0)
		{
			i++;
			if(spl[i] == NULL)
				return NULL;
			pick = ft_strdup(spl[i]);
			return (pick);
		}
		i++;
	}
	return NULL;
}

int	looking_for_her(char	**slp)
{
	int i = 0;
	while(slp[i])
	{
		if (ft_strcmp(slp[i],"<<") == 0)
			return (1);
		i++;
	}
	return (0);
}
void sigcheck(int sig)
{
	if (sig == SIGINT)
		exit(0);
}

void apply_fd(t_com *com,t_zid *zone) {
    char *heredoc;
    int sig = 0;
	int i = 0;
	int	herdo_flag = looking_for_her(com->slp);
    //search_for_redirection(com);

    	//if (num != 0) {
        //	file = detect_file(com->all_Line);
        //if (num == 1 || num == 3)
		//{
		while (com->slp[i])
		{
			if (ft_strcmp(com->slp[i],"<<") == 0 && herdo_flag == 1)
			{
					com->input = open("/tmp/s7i7.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
            	while (1)
				{
            	    signal(SIGINT, sigcheck);
            	    signal(SIGQUIT, SIG_IGN);
            	    heredoc = readline("\033[0;32mheredoc\033[0m> ");
            	    if (heredoc == NULL)
					{
            	        printf("File closed. Exiting...\n");
            	        sig = 1;
            	    }
            	    if (sig)
            	        break;
            	    if (*heredoc)
            	        ft_putendl_fd(heredoc,com->input );
            	    if (ft_strcmp(heredoc, com->slp[i + 1]) == 0) {
            	        break;
            	    }
        	    }
            	close(com->input);
            	com->herdo = open("/tmp/s7i7.txt", O_RDONLY);
            	unlink("/tmp/s7i7.txt");
            	if (com->herdo == -1)
				{
            	    perror("Failed to open heredoc file");
            	    exit(1);
            	}
            	if (dup2(com->herdo, STDIN_FILENO) == -1)
				{
            	    perror("Duplication of file descriptor failed");
            	    exit(1);
            	}
            	close(com->herdo);
				herdo_flag = 0;
				if (vip_command_check(com) == 1)
					exe_builtins(com,zone);
				else
        			execute_command(com->commad,com->after_red,zone->env);
			}
            else if (ft_strcmp(com->slp[i],">") == 0 && herdo_flag == 0)
			{
                com->output = open(com->slp[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
        	    if (dup2(com->output, STDOUT_FILENO) == -1) {
            	    perror("Duplication of file descriptor failed");
            	    exit(1);
            	}
				if (vip_command_check(com) == 1)
					exe_builtins(com,zone);
				else
        			execute_command(com->commad,com->after_red,zone->env);
				close(com->output);
			}
            else if (ft_strcmp(com->slp[i],">>") == 0 && herdo_flag == 0)
			{
                com->output = open(com->slp[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
				if (dup2(com->output, STDOUT_FILENO) == -1) {
            	    perror("Duplication of file descriptor failed");
            	    exit(1);
            	}
				close(com->output);
				if (vip_command_check(com) == 1)
					exe_builtins(com,zone);
				else
        			execute_command(com->commad,com->after_red,zone->env);
        	}
            else if (ft_strcmp(com->slp[i],"<") == 0 && herdo_flag == 0)
			{
                com->input = open(com->slp[i + 1], O_RDONLY);
				if (dup2(com->input, STDIN_FILENO) == -1) {
                    	perror("Duplication of file descriptor failed");
                    exit(1);
                }
				close(com->input);
				if (vip_command_check(com) == 1)
					exe_builtins(com,zone);
				else
        			execute_command(com->commad,com->after_red,zone->env);
			}
			i++;
		}
}