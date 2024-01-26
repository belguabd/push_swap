/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:12:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/26 08:41:33 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*rotate stacka*/
void ra(t_nbrs **stacka)
{
    if (*stacka == NULL || (*stacka)->next == NULL)
        return;

    t_nbrs *temp = *stacka;
    *stacka = (*stacka)->next;

    t_nbrs *last = *stacka;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
    write(1, "ra\n", 3);
    
}

/*rotaet stackb*/
void rb(t_nbrs **stackb)
{
    if (*stackb == NULL || (*stackb)->next == NULL)
        return;

    t_nbrs *temp = *stackb;
    *stackb = (*stackb)->next;

    t_nbrs *last = *stackb;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
    write(1, "rb\n", 4);
}

/*rotate stacka and stackb*/

void rr(t_nbrs **stacka, t_nbrs **stackb)
{
    /*stacka*/

    t_nbrs *temp = *stacka;
    *stacka = (*stacka)->next;

    t_nbrs *last = *stacka;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;

    /*stackb*/

    temp = *stackb;
    *stackb = (*stackb)->next;

    last = *stackb;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
    write(1, "rr\n", 4);
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
    last->next = *stacka;
    second_node->next = NULL;
    *stacka = last;
    write(1, "rra\n", 4);
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
    last->next = *stackb;
    second_node->next = NULL;
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
    last->next = *stacka;
    second_node->next = NULL;
    *stacka = last;

    /*reverse rotate stackb*/

    last = *stackb;
    second_node = NULL;
    while (last->next)
    {
        second_node = last;
        last = last->next;
    }
    last->next = *stackb;
    second_node->next = NULL;
    *stackb = last;
}