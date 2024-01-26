/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnew_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:51:17 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/26 08:42:06 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_nbrs *ft_addnew_nbr(int number)
{
    t_nbrs *p;
    p = (t_nbrs *)malloc(sizeof(t_nbrs));
    if (!p)
        return (NULL);
    p->number = number;
    p->index = 0;
    p->next = NULL;
    return (p);
}