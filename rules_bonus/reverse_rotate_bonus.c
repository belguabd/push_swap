/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:30:59 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 11:47:30 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*reverse rotate stacka */
void	rra(t_nbrs **stacka)
{
	t_nbrs	*last;
	t_nbrs	*second_node;

	if (stacka && *stacka && (*stacka)->next)
	{
		last = *stacka;
		second_node = NULL;
		while (last->next)
		{
			second_node = last;
			last = last->next;
		}
		last->next = *stacka;
		second_node->next = NULL;
		*stacka = last;
	}
}

/*reverse rotate stackb*/
void	rrb(t_nbrs **stackb)
{
	t_nbrs	*last;
	t_nbrs	*second_node;

	second_node = NULL;
	if (stackb && *stackb && (*stackb)->next)
	{
		last = *stackb;
		while (last->next)
		{
			second_node = last;
			last = last->next;
		}
		last->next = *stackb;
		second_node->next = NULL;
		*stackb = last;
	}
}

void	ft_reverse_rotate_sk(t_nbrs **stack)
{
	t_nbrs	*last;
	t_nbrs	*second_node;

	second_node = NULL;
	if (stack && *stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
		{
			second_node = last;
			last = last->next;
		}
		last->next = *stack;
		second_node->next = NULL;
		*stack = last;
	}
}

/*reverse rotate stacka and stackb*/
void	rrr(t_nbrs **stacka, t_nbrs **stackb)
{
	ft_reverse_rotate_sk(stacka);
	ft_reverse_rotate_sk(stackb);
}
