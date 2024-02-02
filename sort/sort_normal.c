/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:24:28 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 12:00:38 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_normal(t_nbrs **stacka, t_nbrs **stackb)
{
	if (ft_lstsize((*stacka)) == 2)
		ft_sort_two((*stacka));
	if (ft_lstsize((*stacka)) == 3)
		ft_sort_three(&(*stacka));
	if (ft_lstsize((*stacka)) == 4)
	{
		process_stack_four(stacka, stackb);
		ft_sort_three(stacka);
		pa(stacka, stackb);
	}
	if (ft_lstsize((*stacka)) == 5)
	{
		process_stack_five(stacka, stackb);
		process_stack_four(stacka, stackb);
		ft_sort_three(stacka);
		pa(stacka, stackb);
		pa(stacka, stackb);
	}
}
