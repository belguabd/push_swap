/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:36:31 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/28 14:37:14 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_pos(t_nbrs **stackb, int size)
{
    t_nbrs *temp;
    int index = 0;
    temp = *stackb;
    while (temp)
    {
        if (temp->index == size - 1)
            return (index);
        index++;
        temp = temp->next;
    }
    return (index);
}

void ft_puch_stacka(t_nbrs **stacka ,t_nbrs **stackb)
{
    while (*stackb)
    {
        int index = get_pos(stackb, ft_lstsize(*stackb));
        if (index <= ft_lstsize(*stackb) / 2)
        {
            while (index--)
                rb(stackb);
        }
        else
        {
            index = ft_lstsize(*stackb) - index;
            while (index--)
                rrb(stackb);
        }
        pa(stacka, stackb);
    }
}

void sort_big(t_nbrs **stacka, t_nbrs **stackb)
{
    int size_b = ft_lstsize(*stacka);
    int chunk = size_b / 5;
    int change_chunk = chunk;

    while (*stacka)
    {
        if ((*stacka)->index < change_chunk)
        {
            if ((*stacka)->index >= (change_chunk - (chunk / 2)))
            {
                pb(stacka, stackb);
                rb(stackb);
            }
            else
                pb(stacka, stackb);
        }
        else
            ra(stacka);
        if (ft_lstsize(*stackb) == change_chunk)
            change_chunk += chunk;
    }
    ft_puch_stacka(stacka, stackb);
}