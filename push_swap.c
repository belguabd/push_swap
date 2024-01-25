/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/25 16:55:32 by belguabd         ###   ########.fr       */
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

int find_min_index(t_nbrs *stacka)
{
    int index;
    index = stacka->index;
    stacka = stacka->next;
    while (stacka)
    {
        if (stacka->index < index)
            index = stacka->index;
        stacka = stacka->next;
    }
    return (index);
}
void process_stack_four(t_nbrs **stacka, t_nbrs **stackb)
{
    int count;
    t_nbrs *temp;
    int index;
    count = 0;
    temp = *stacka;
    index = find_min_index(*stacka);
    while (temp && temp->index != index && ++count)
        temp = temp->next;
    if (count == 1)
        sa(stacka);
    else if (count == 2)
    {
        ra(stacka);
        ra(stacka);
    }
    else if (count == 3)
        rra(stacka);
    pb(stacka, stackb);
}
void process_stack_five(t_nbrs **stacka, t_nbrs **stackb)
{
    int count;
    t_nbrs *temp;

    count = 0;
    temp = *stacka;
    while (temp && temp->index != 0 && ++count)
        temp = temp->next;
    if (count == 1)
        sa(stacka);
    else if (count == 2)
    {
        ra(stacka);
        ra(stacka);
    }
    else if (count == 3)
    {
        rra(stacka);
        rra(stacka);
    }
    else if (count == 4)
        rra(stacka);

    pb(stacka, stackb);
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
        if (ft_lstsize(stacka) == 4)
        {
            process_stack_four(&stacka, &stackb);
            ft_sort_three(&stacka);
            pa(&stacka, &stackb);
        }
        if (ft_lstsize(stacka) == 5)
        {
            process_stack_five(&stacka, &stackb);
            process_stack_four(&stacka,&stackb);
            ft_sort_three(&stacka);
            pa(&stacka, &stackb);
            pa(&stacka, &stackb);
            
        }
      
        show_linked(stacka);
        show_linked(stackb);
    }
    return 0;
}
