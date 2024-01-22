/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:12:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/22 14:04:43 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include <stdio.h>

/*rotate stacka*/

void ra(t_nbrs *stacka)
{
    int temp = stacka->number;

    while (stacka->next)
    {
        stacka->number = stacka->next->number;
        stacka = stacka->next;
    }
    stacka->number = temp;
}

/*rotaet stackb*/
void rb(t_nbrs *stackb)
{
    int temp = stackb->number;

    while (stackb->next)
    {
        stackb->number = stackb->next->number;
        stackb = stackb->next;
    }
    stackb->number = temp;
}

/*rotate stacka and stackb*/

void rr(t_nbrs *stacka, t_nbrs *stackb)
{
    /*stacka*/
    int temp = stacka->number;

    while (stacka->next)
    {
        stacka->number = stacka->next->number;
        stacka = stacka->next;
    }
    stacka->number = temp;

    /*stackb*/

    temp = stackb->number;

    while (stackb->next)
    {
        stackb->number = stackb->next->number;
        stackb = stackb->next;
    }
    stackb->number = temp;
}

/*reverse rotate stacka */

void rra(t_nbrs **stacka)
{
    t_nbrs *last = *stacka;
    t_nbrs *second_node = NULL;
    while (last->next)
    {
        second_node = last;
        last = last->next;
    }
    second_node->next = NULL;
    last->next = *stacka;
    *stacka = last;
}

/*reverse rotate stackb*/
void rrb(t_nbrs **stackb)
{
    t_nbrs *last = *stackb;
    t_nbrs *second_node = NULL;
    while (last->next)
    {
        second_node = last;
        last = last->next;
    }
    second_node->next = NULL;
    last->next = *stackb;
    *stackb = last;
}

/*reverse rotate stacka and stackb*/
void rrr(t_nbrs **stacka, t_nbrs **stackb)
{
    /*reverse rotate stacka*/
    t_nbrs *last = *stacka;
    t_nbrs *second_node = NULL;
    while (last->next)
    {
        second_node = last;
        last = last->next;
    }
    second_node->next = NULL;
    last->next = *stacka;
    *stacka = last;

    /*reverse rotate stackb*/
    
    last = *stackb;
    second_node = NULL;
    while (last->next)
    {
        second_node = last;
        last = last->next;
    }
    second_node->next = NULL;
    last->next = *stackb;
    *stackb = last;
}