/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normal_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:58:43 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 12:01:17 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min_index(t_nbrs *stacka)
{
	int	index;

	index = stacka->index;
	stacka = stacka->next;
	while (stacka)
	{
		if (stacka->index < index)
			index = stacka->index;
		stacka = stacka->next;
	}
	return (index);
}

void	ft_sort_two(t_nbrs *stacka)
{
	sa(&stacka);
}

void	ft_sort_three(t_nbrs **stacka)
{
	int	a;
	int	b;
	int	c;

	a = (*stacka)->number;
	b = (*stacka)->next->number;
	c = (*stacka)->next->next->number;
	if (a < b && b < c)
		return ;
	if (a > b && b > c && a > c)
	{
		sa(stacka);
		rra(stacka);
	}
	else if (a > b && a > c)
		ra(stacka);
	else if (a > b && a < c)
		sa(stacka);
	else if (a < b && a < c)
	{
		sa(stacka);
		ra(stacka);
	}
	else if (a < b && a > c)
		rra(stacka);
}

void	process_stack_four(t_nbrs **stacka, t_nbrs **stackb)
{
	t_nbrs	*temp;
	int		count;
	int		index;

	count = 0;
	temp = *stacka;
	index = find_min_index(*stacka);
	while (temp && temp->index != index && ++count)
		temp = temp->next;
	if (count == 1)
		sa(stacka);
	else if (count == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (count == 3)
		rra(stacka);
	pb(stacka, stackb);
}

void	process_stack_five(t_nbrs **stacka, t_nbrs **stackb)
{
	t_nbrs	*temp;
	int		count;

	count = 0;
	temp = *stacka;
	while (temp && temp->index != 0 && ++count)
		temp = temp->next;
	if (count == 1)
		sa(stacka);
	else if (count == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (count == 3)
	{
		rra(stacka);
		rra(stacka);
	}
	else if (count == 4)
		rra(stacka);
	pb(stacka, stackb);
}
