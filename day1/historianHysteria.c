/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historianHysteria.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedusser <jedusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:54:37 by michismuch        #+#    #+#             */
/*   Updated: 2024/12/01 20:32:11 by jedusser         ###   ########.fr       */
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
        nb2[j] = line[i];
        i++;
        j++;
    }
    nb2[j] = '\0';
}

void fill_lists(int *list1, int *list2, char *nb1, char *nb2, int i)
{
        list1[i] = atoi(nb1); 
        list2[i] = atoi(nb2);    
}



int main(void)
{
    char    *line;
    int      fd;
    
    char nb1[6];
    char nb2[6];
    
    int list1[1000];
    int list2[1000] ;

    
    fd = open("./input.txt", O_RDONLY);
    int i = 0;
    
    while ((line = get_next_line(fd)) !=  NULL)
    {
        copy_nbs(line, nb1, nb2);
        fill_lists(list1, list2, nb1, nb2, i);
        free(line);
        i++;
    }


    
    int j = 0;
    while (j < i)
    {
        printf("%d\n", list1[j]);
        j++;
        /* code */
    }    

}