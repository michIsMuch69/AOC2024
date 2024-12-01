/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historianHysteria.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jean-micheldusserre <jean-micheldusserr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:55:36 by jean-michel       #+#    #+#             */
/*   Updated: 2024/12/01 16:56:35 by jean-michel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <readline/readline.h>
#include "./get_next_line/get_next_line.h"

void copy_nbs(char *nb1, char *nb2, char *line)
{
    strncpy(nb1, line, 5);
    strlcpy(nb2, line + 8, 6);
}
void copy_to_lists(int *list1, int *list2, char *nb1, char *nb2, int i)
{
    list1[i] = atoi(nb1);
    list2[i] = atoi(nb2);
}

int main(void)
{
    int fd;
    char *line;
    char nb1[6];
    char nb2[6];
    int list1[998];
    int list2[998];

    
    fd = open("input.txt", O_RDONLY);
    line = get_next_line(fd);
    
    
    int i = 0;
    copy_nbs(nb1, nb2, line);
    copy_to_lists(list1, list2, nb1, nb2, i);
    while(line)
    {
        i++;
        copy_nbs(nb1, nb2, line);
        copy_to_lists(list1, list2, nb1, nb2, i);
        free(line);
        line = get_next_line(fd);
    }
    printf("nb1 = %s\n", nb1);
    printf("nb2 = %s\n", nb2);
    printf("list1[0] = %d\n", list1[i]);
    printf("list1[0] = %d\n", list2[i]);
    
    // int j = 0;
    // printf("List 1 ! : \n");
    // while (list1[j])
    // {
    //     printf("list1[j] = %d\n", list1[j]);
    //     j++;
    // }
    
    // j = 0;
    // printf("List 2 ! : \n");
    // while (list2[j])
    // {
    //     printf("list2[j] = %d\n", list2[j]);
    //     j++;
    // }
    
}
