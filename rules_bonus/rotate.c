/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:12:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 11:48:17 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*rotate stacka*/
void	ra(t_nbrs **stacka)
{
	t_nbrs	*temp;
	t_nbrs	*last;

	if (stacka && *stacka && (*stacka)->next)
	{
		temp = *stacka;
		*stacka = (*stacka)->next;
		last = *stacka;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

/*rotaet stackb*/
void	rb(t_nbrs **stackb)
{
	t_nbrs	*temp;
	t_nbrs	*last;

	if (stackb && *stackb && (*stackb)->next)
	{
		temp = *stackb;
		*stackb = (*stackb)->next;
		last = *stackb;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

void	ft_reverse_rotate(t_nbrs **stack)
{
	t_nbrs	*temp;
	t_nbrs	*last;

	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->next = NULL;
	}
}

/*rotate stacka and stackb*/
void	rr(t_nbrs **stacka, t_nbrs **stackb)
{
	ft_reverse_rotate(stacka);
	ft_reverse_rotate(stackb);
}
