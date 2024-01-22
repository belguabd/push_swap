/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:46:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/22 04:20:31 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

/*swap stacka*/
void sa(t_nbrs *head)
{
    int nbr;
    t_nbrs *temp;
    temp = head->next;
    nbr = head->number;
    head->number = temp->number;
    temp->number = nbr;
}

/*swap stackb*/
void sb(t_nbrs *head)
{
    int nbr;
    t_nbrs *temp;
    temp = head->next;
    nbr = head->number;
    head->number = temp->number;
    temp->number = nbr;
}

/*swap a and swap b*/
void ss(t_nbrs *stacka, t_nbrs *stackb)
{
    /*satcka*/
    int nbr;
    t_nbrs *temp;
    temp = stacka->next;
    nbr = stacka->number;
    stacka->number = temp->number;
    temp->number = nbr;

    /*satckb*/
    temp = stackb->next;
    nbr = stackb->number;
    stackb->number = temp->number;
    temp->number = nbr;
}