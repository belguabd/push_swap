/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/21 21:23:03 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
void show_linked(t_nbrs *head)
{
    while (head)
    {
        printf("%d =>", head->number);
        printf("   {%d}\n", head->index);

        head = head->next;
    }
}

void sort_list(t_nbrs *head)
{
    t_nbrs *temp;
    t_nbrs *temp2;
    temp = head;
    while (temp->next)
    {
        temp2 = temp->next;
        while (temp2)
        {
            if (temp->number > temp2->number)
                temp->index++;
            else
                temp2->index++;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

t_nbrs *ft_addnew_nbr(int number)
{
    t_nbrs *p;
    p = (t_nbrs *)malloc(sizeof(t_nbrs));
    if (!p)
        return (NULL);
    p->number = number;
    p->index = 0;
    p->next = NULL;
    return (p);
}
bool check_repeat(t_nbrs **lst, t_nbrs *new)
{
    t_nbrs *current;

    current = *lst;
    while (current)
    {
        if (current->number == new->number)
            return (true);
        current = current->next;
    }
    return (false);
}
void ft_lstadd_end(t_nbrs **lst, t_nbrs *new)
{
    if (check_repeat(lst, new))
    {
        write(1, "Error", 5);
        exit(1);
    }
    t_nbrs *current;

    if (!*lst)
    {
        *lst = new;
        return;
    }
    current = *lst;
    while (current->next)
        current = current->next;
    current->next = new;
}
void ft_lstadd_front(t_nbrs **head, t_nbrs *new)
{
    if (!head || !new)
        return;
    new->next = *head;
    *head = new;
}

int main(int ac, char *av[])
{

    if (ac != 1)
    {
        int i = 1;
        char **res;
        t_nbrs *stacka;
        t_nbrs *temp;
        int j;
        while (av[i])
        {
            if (av[i][0] == '\0')
            {
                write(1, "Error", 5);
                exit(1);
            }
            res = ft_split(av[i], ' ');
            j = 0;
            while (res[j])
            {
                temp = ft_addnew_nbr(ft_atoi(res[j]));
                ft_lstadd_end(&stacka, temp);
                j++;
            }
            i++;
        }
        sort_list(stacka);
        show_linked(stacka);
    }
    return 0;
}
