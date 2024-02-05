/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:26:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/03 23:07:53 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_best_move(int size, int move)
{
	if (move > size / 2)
		move = size - move;
	return (move);
}

void	get_pos(t_nbrs **stackb, int a, int *big_pos, int *small_pos)
{
	t_nbrs	*temp;
	int		size;

	(*big_pos) = 0;
	(*small_pos) = 0;
	size = ft_lstsize(*stackb);
	temp = *stackb;
	while (temp)
	{
		if (temp->index == size - a)
			break ;
		(*big_pos)++;
		temp = temp->next;
	}
	temp = *stackb;
	while (temp)
	{
		if (temp->index == size - 2)
			break ;
		(*small_pos)++;
		temp = temp->next;
	}
}

void	push_slnbr_ska(t_nbrs **stackb, t_nbrs **stacka,
	int *optimal_move_count_2, int *small_pos)
{
	while ((*optimal_move_count_2)--)
	{
		if ((*small_pos) > ft_lstsize(*stackb) / 2)
			rrb(stackb);
		else
			rb(stackb);
	}
	pa(stacka, stackb);
}

void	push_bignbr_ska(t_nbrs **stacka, t_nbrs **stackb,
	int *optimal_move_count_1, int *big_pos)
{
	(*optimal_move_count_1) = ft_best_move(ft_lstsize(*stackb), (*big_pos));
	while ((*optimal_move_count_1)--)
	{
		if ((*big_pos) > ft_lstsize(*stackb) / 2)
			rrb(stackb);
		else
			rb(stackb);
	}
	pa(stacka, stackb);
	sa(stacka);
}

void	push_bignbr_to_ska(t_nbrs **stacka, t_nbrs **stackb,
	int *big_pos, int *optimal_move_count_1)
{
	if ((*big_pos) > ft_lstsize(*stackb) / 2)
		while ((*optimal_move_count_1)--)
			rrb(stackb);
	else
		while ((*optimal_move_count_1)--)
			rb(stackb);
	pa(stacka, stackb);
}
