/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:24:28 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/26 08:30:49 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



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

void sort_normal(t_nbrs **stacka, t_nbrs **stackb)
{
    if (ft_lstsize((*stacka)) == 2)
        ft_sort_two((*stacka));
    if (ft_lstsize((*stacka)) == 3)
        ft_sort_three(&(*stacka));
    if (ft_lstsize((*stacka)) == 4)
    {
        process_stack_four(stacka, stackb);
        ft_sort_three(stacka);
        pa(stacka, stackb);
    }
    if (ft_lstsize((*stacka)) == 5)
    {
        process_stack_five(stacka, stackb);
        process_stack_four(stacka, stackb);
        ft_sort_three(stacka);
        pa(stacka, stackb);
        pa(stacka, stackb);
    }
}