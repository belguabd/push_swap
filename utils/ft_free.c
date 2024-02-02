/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:24:14 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 17:20:05 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_free_split(char **res)
{
	int i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	ft_lstclear(t_nbrs **stack)
{
	t_nbrs	*tmp;

	while (stack && *stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	// *stack = NULL;
}