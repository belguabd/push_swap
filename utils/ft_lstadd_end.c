/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:44:47 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/31 14:48:44 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool check_repeat(t_nbrs **lst, t_nbrs *new)
{
    t_nbrs *current;
    current = *lst;
    while (current)
    {
        if (current->number == new->number)
            return (true);
        current = current->next;
    }
    return (false);
}

void ft_lstadd_end(t_nbrs **lst, t_nbrs *new)
{
    if (check_repeat(lst, new))
        exit(write(2, "Error\n", 6));
    t_nbrs *current;

    if (!*lst)
    {
        *lst = new;
        return;
    }
    current = *lst;
    while (current->next)
        current = current->next;
    current->next = new;
}