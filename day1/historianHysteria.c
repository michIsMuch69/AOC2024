/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historianHysteria.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michismuch <michismuch@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:54:37 by michismuch        #+#    #+#             */
/*   Updated: 2024/12/01 18:22:18 by michismuch       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include "./get_next_line/get_next_line.h"

void copy_nbs(char *line, char *nb1, char *nb2)
{
    int i = 0;
    while(line[i] && line[i] != 32)
    {
        nb1[i] = line[i];
        i++;   
    }
    nb1[i] = '\0';
    while (line[i] == 32)
        i++;
    int j = 0;
    while(line[i] != '\0')
    {
        nb2[j] == line[i];
        j++;
        i++;
    }
    nb2[j] = '\0';
}

int main(void)
{
    char    *line;
    int      fd;
    char nb1[6];
    char nb2[6];
    
    fd = open("./input.txt", O_RDONLY);
    line = get_next_line(fd);
    
    copy_nbs(line, nb1, nb2);
    
    printf("nb1 = %s\n", nb1);
    printf("nb2 = %s\n", nb2);
    
    
    
    
    
}