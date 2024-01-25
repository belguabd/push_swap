/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:46:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/25 10:18:49 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*swap stacka*/
void sa(t_nbrs **stacka)
{
    int nbr;
    int index;
    t_nbrs *temp;

    nbr = (*stacka)->number;
    index = (*stacka)->index;
    temp = (*stacka)->next;
    (*stacka)->number = temp->number;
    (*stacka)->index = temp->index;
    temp->number = nbr;
    temp->index = index;
    write(1, "sa\n", 3);
}

/*swap stackb*/
void sb(t_nbrs **stackb)
{
    int nbr;
    int index;
    t_nbrs *temp;

    nbr = (*stackb)->number;
    index = (*stackb)->index;
    temp = (*stackb)->next;
    (*stackb)->number = temp->number;
    (*stackb)->index = temp->index;
    temp->number = nbr;
    temp->index = index;
    write(1, "sb\n", 3);
}

/*swap a and swap b*/
void ss(t_nbrs **stacka, t_nbrs **stackb)
{
    /*satcka*/
    int nbr;
    int index;
    t_nbrs *temp;

    nbr = (*stacka)->number;
    index = (*stacka)->index;
    temp = (*stacka)->next;
    (*stacka)->number = temp->number;
    (*stacka)->index = temp->index;
    temp->number = nbr;
    temp->index = index; 

    /*satckb*/
    nbr = (*stackb)->number;
    index = (*stackb)->index;
    temp = (*stackb)->next;
    (*stackb)->number = temp->number;
    (*stackb)->index = temp->index;
    temp->number = nbr;
    temp->index = index;
    
    
    
    write(1, "ss\n", 3);
}