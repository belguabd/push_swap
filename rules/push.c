/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:29:16 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/22 17:23:09 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include <stdio.h>
static void ft_remove_node(t_nbrs **stacka)
{

    t_nbrs *temp;
    temp = (*stacka)->next;
    *stacka = temp;
}
void pa(t_nbrs **stacka, t_nbrs **stackb)
{
    t_nbrs *new = *stackb;
    new->next = NULL; 
    new->next = *stackb;
    
    printf("{%d}\n", new->number);
    // new->next = *stacka;
    // *stacka = new;
    (void)stacka;
    ft_remove_node(stackb);
}
