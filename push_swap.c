/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/28 14:37:26 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show_linked_stacka(t_nbrs *head)
{
    printf("+--------+-------+---------+\n");
    printf("|         Stack A          |\n");
    printf("+--------+-------+---------+\n");
    printf("| Number | Index | Position|\n");
    printf("+--------+-------+---------+\n");

    while (head)
    {
        printf("| %-6d | %-5d | %-7d |\n", head->number, head->index, head->position);
        head = head->next;
    }

    printf("+--------+-------+---------+\n");
}
void show_linked_stackb(t_nbrs *head)
{
    printf("+--------+-------+---------+\n");
    printf("|         Stack B          |\n");
    printf("+--------+-------+---------+\n");
    printf("| Number | Index | Position|\n");
    printf("+--------+-------+---------+\n");

    while (head)
    {
        printf("| %-6d | %-5d | %-7d |\n", head->number, head->index, head->position);
        head = head->next;
    }

    printf("+--------+-------+---------+\n");
}
bool check_sorted(t_nbrs *head)
{

    while (head->next)
    {
        if (head->number > head->next->number)
            return (false);
        head = head->next;
    }
    return (true);
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
int main(int ac, char *av[])
{

    if (ac != 1)
    {
        int i = 1;
        char **res;

        t_nbrs *stacka;
        t_nbrs *stackb;
        stackb = NULL;
        t_nbrs *temp;

        int j;
        while (av[i])
        {
            if (av[i][0] == '\0')
                exit(write(2, "Error", 5));
            res = ft_split(av[i], ' ');
            if (!res[0])
                exit(write(2, "Error", 5));
            j = 0;
            while (res[j])
            {
                temp = ft_addnew_nbr(parsing(res[j]));
                ft_lstadd_end(&stacka, temp);
                j++;
            }
            i++;
        }
        if (check_sorted(stacka))
            exit(write(2, "list is sorted\n", strlen("list is sorted\n")));

        sort_list(stacka);
        sort_normal(&stacka, &stackb);
        if (ft_lstsize(stacka) > 5)
        {
            sort_big(&stacka, &stackb);
        }
    }
    return 0;
}
