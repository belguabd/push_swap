/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:33:32 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/26 09:48:49 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_lstsize(t_nbrs *head)
{
    int count;
    count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return (count);
}