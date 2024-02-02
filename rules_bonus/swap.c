/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:46:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 11:49:15 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_nbrs **stacka)
{
	t_nbrs	*temp;
	int		nbr;
	int		index;

	if (stacka && *stacka && (*stacka)->next)
	{
		nbr = (*stacka)->number;
		index = (*stacka)->index;
		temp = (*stacka)->next;
		(*stacka)->number = temp->number;
		(*stacka)->index = temp->index;
		temp->number = nbr;
		temp->index = index;
	}
}

/*swap stackb*/
void	sb(t_nbrs **stackb)
{
	t_nbrs	*temp;
	int		nbr;
	int		index;

	if (stackb && *stackb && (*stackb)->next)
	{
		nbr = (*stackb)->number;
		index = (*stackb)->index;
		temp = (*stackb)->next;
		(*stackb)->number = temp->number;
		(*stackb)->index = temp->index;
		temp->number = nbr;
		temp->index = index;
	}
}

void	ft_swap_sk(t_nbrs **stack)
{
	t_nbrs	*temp;
	int		nbr;
	int		index;

	if (stack && *stack && (*stack)->next)
	{
		nbr = (*stack)->number;
		index = (*stack)->index;
		temp = (*stack)->next;
		(*stack)->number = temp->number;
		(*stack)->index = temp->index;
		temp->number = nbr;
		temp->index = index;
	}
}

/*swap a and swap b*/
void	ss(t_nbrs **stacka, t_nbrs **stackb)
{
	ft_swap_sk(stacka);
	ft_swap_sk(stackb);
}
