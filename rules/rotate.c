/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:12:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/31 10:23:24 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*rotate stacka*/
void ra(t_nbrs **stacka)
{
    if (!stacka || *stacka == NULL || (*stacka)->next == NULL)
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
    // if (*stackb == NULL || (*stackb)->next == NULL)
    //     return;

    if (!stackb)
        return;
    if (!*stackb)
        return;
    if ((*stackb)->next == NULL)
        return;
    t_nbrs *temp = *stackb;
    *stackb = (*stackb)->next;

    t_nbrs *last = *stackb;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
    temp->next = NULL;
    write(1, "rb\n", 3);
}

/*rotate stacka and stackb*/

void rr(t_nbrs **stacka, t_nbrs **stackb)
{
    /*stacka*/

    // if (!stacka || !*stacka || !stackb || !*stackb || !(*stackb)->next)
    //     return;
    t_nbrs *temp;
    t_nbrs *last;
    if (stacka && *stacka && (*stacka)->next)
    {
        temp = *stacka;
        *stacka = (*stacka)->next;

        last = *stacka;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
        temp->next = NULL;
    }

    if (stackb && *stackb && (*stackb)->next)
    {
        temp = *stackb;
        *stackb = (*stackb)->next;

        last = *stackb;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
        temp->next = NULL;
    }
    write(1, "rr\n", 3);
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

    if (!stackb)
        return;
    if (!*stackb)
        return;
    if ((*stackb)->next == NULL)
        return;

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
    write(1, "rrb\n", 4);
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
    write(1, "rrr\n", 4);
}