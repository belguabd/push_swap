/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:44:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/23 13:48:37 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
#define RULES_H
#include <stdlib.h>
typedef struct Numbers
{
    int number;
    int index;
    struct Numbers *next;
} t_nbrs;

void sa(t_nbrs *head);
void sb(t_nbrs *head);
void ss(t_nbrs *stacka, t_nbrs *stackb);
void ra(t_nbrs *head);
void rr(t_nbrs *stacka, t_nbrs *stackb);
void rra(t_nbrs **stacka);
void rrr(t_nbrs **stacka, t_nbrs **stackb);
void rrb(t_nbrs **stackb);
void ft_remove(t_nbrs **stacka);
void pa(t_nbrs **stacka, t_nbrs **stackb);
void pb(t_nbrs **stacka, t_nbrs **stackb);

#endif