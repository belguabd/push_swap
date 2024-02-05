/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:36:31 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/04 18:11:15 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_puch_stacka(t_nbrs **stacka, t_nbrs **stackb)
{
	int	big_pos;
	int	small_pos;
	int	optimal_move_count_1;
	int	optimal_move_count_2;

	while (*stackb)
	{
		optimal_move_count_1 = 0;
		optimal_move_count_2 = 0;
		get_pos(stackb, 1, &big_pos, &small_pos);
		optimal_move_count_1 = ft_best_move(ft_lstsize(*stackb), big_pos);
		optimal_move_count_2 = ft_best_move(ft_lstsize(*stackb), small_pos);
		if (optimal_move_count_2 < optimal_move_count_1)
		{
			push_slnbr_ska(stackb, stacka, &optimal_move_count_2, &small_pos);
			get_pos(stackb, 0, &big_pos, &small_pos);
			push_bignbr_ska(stacka, stackb, &optimal_move_count_1, &big_pos);
		}
		else
			push_bignbr_to_ska(stacka, stackb, &big_pos, &optimal_move_count_1);
	}
}

bool	ft_push_stackb(t_nbrs **stacka, t_nbrs **stackb,
	int *change_chunk, int *chunk)
{
	if ((*stacka)->index < (*change_chunk))
	{
		if ((*stacka)->index < ((*change_chunk) - ((*chunk) / 2)))
			pb(stacka, stackb);
		else
		{
			pb(stacka, stackb);
			if ((*stacka) && (*stacka)->index >= (*change_chunk))
				rr(stacka, stackb);
			else
				rb(stackb);
		}
		return (true);
	}
	return (false);
}

void	sort_big(t_nbrs **stacka, t_nbrs **stackb)
{
	int	size_b;
	int	chunk;
	int	change_chunk;

	size_b = ft_lstsize(*stacka);
	chunk = size_b / 5;
	if (size_b > 100)
		chunk = size_b / 9;
	change_chunk = chunk;
	while (*stacka)
	{
		if (ft_push_stackb(stacka, stackb, &change_chunk, &chunk))
			;
		else
			ra(stacka);
		if (ft_lstsize(*stackb) == change_chunk)
			change_chunk += chunk;
	}
	ft_puch_stacka(stacka, stackb);
}
