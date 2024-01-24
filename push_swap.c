/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/24 18:03:46 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void show_linked(t_nbrs *head)
{
    printf("+--------+-------+\n");
    printf("| Number | Index |\n");
    printf("+--------+-------+\n");

    while (head)
    {
        printf("| %-6d | %-5d |\n", head->number, head->index);
        head = head->next;
    }

    printf("+--------+-------+\n");
}
void ft_sort_two(t_nbrs *stacka)
{
    sa(&stacka);
}
void ft_sort_three(t_nbrs **stacka)
{
    int a = (*stacka)->number;
    int b = (*stacka)->next->number;
    int c = (*stacka)->next->next->number;
    if (a > b && b > c && a > c)
    {
        sa(stacka);
        rra(stacka);
    }
    else if (a > b && a > c)
        ra(stacka);
    else if (a > b && a < c)
        sa(stacka);
    else if (a < b && a < c)
    {
        sa(stacka);
        ra(stacka);
    }
    else if (a < b && a > c)
        rra(stacka);
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

int ft_lstsize(t_nbrs *head)
{
    int count;
    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
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
        write(2, "Error", 5);
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
        if (ft_lstsize(stacka) == 2)
            ft_sort_two(stacka);
        show_linked(stacka);
        if (ft_lstsize(stacka) == 3)
            ft_sort_three(&stacka);
        // if (ft_lstsize(stacka) == 4)
        // {
        //     pb(&stacka, &stackb);
        //     // t_nbrs *temp;
        //     // temp = stacka;
        //     // while (temp)
        //     // {
        //     //     if (temp->number == 0)
        //     //         pb(&temp, &stackb);
        //     //     temp = temp->next;
        //     // }
        // }
        // sa(&stacka);
        show_linked(stacka);
        // show_linked(stackb);
    }
    return 0;
}
