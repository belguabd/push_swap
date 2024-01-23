/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:29:16 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/23 13:47:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"
#include <stdio.h>

/* Moves the top element from stack B to stack A.*/
void pa(t_nbrs **stacka, t_nbrs **stackb)
{
    t_nbrs *top_b = *stackb;
    *stackb = top_b->next;
    top_b->next = *stacka;
    *stacka = top_b;
}
/* Moves the top element from stack A to stack B.*/
void pb(t_nbrs **stacka, t_nbrs **stackb)
{
    t_nbrs *top_a = *stacka;
    *stacka = top_a->next;
    top_a->next = *stackb;
    *stackb = top_a;
}
