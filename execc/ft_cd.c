/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckannane <ckannane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:30:39 by ckannane          #+#    #+#             */
/*   Updated: 2023/06/23 14:43:49 by ckannane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void execute_cd(char *directory) {
    if (chdir(directory) != 0) {
        perror("chdir() error");
    }
}

void execute_command(char *command) {
    // Separate the command into tokens
    char *token;
    token = strtok(command, " ");

    // Handle the "cd" command
    if (strcmp(token, "cd") == 0) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            execute_cd(token);
        } else {
            fprintf(stderr, "cd: missing directory\n");
        }
    } else {
        // Execute other commands using system()
        system(command);
    }
}
