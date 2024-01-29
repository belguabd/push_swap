/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:14:15 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/29 11:14:33 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void show_linked_stacka(t_nbrs *head)
{
    printf("+--------+-------+---------+\n");
    printf("|         Stack A          |\n");
    printf("+--------+-------+---------+\n");
    printf("| Number | Index | Position|\n");
    printf("+--------+-------+---------+\n");

    while (head)
    {
        printf("| %-6d | %-5d | %-7d |\n", head->number, head->index, head->position);
        head = head->next;
    }

    printf("+--------+-------+---------+\n");
}
void show_linked_stackb(t_nbrs *head)
{
    printf("+--------+-------+---------+\n");
    printf("|         Stack B          |\n");
    printf("+--------+-------+---------+\n");
    printf("| Number | Index | Position|\n");
    printf("+--------+-------+---------+\n");

    while (head)
    {
        printf("| %-6d | %-5d | %-7d |\n", head->number, head->index, head->position);
        head = head->next;
    }

    printf("+--------+-------+---------+\n");
}