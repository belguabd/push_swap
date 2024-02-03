/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:29 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/03 09:28:15 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_ska_skb(t_nbrs **stacka, t_nbrs **stackb, char *line)
{
	ft_lstclear(stacka);
	ft_lstclear(stackb);
	free(line);
	exit(write(2, "Error\n", 6));
}

void	check_intraction(t_nbrs **stacka, t_nbrs **stackb, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stacka);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stacka);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stacka, stackb);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stacka);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stackb);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stacka, stackb);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stacka);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stackb);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stacka, stackb);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stacka, stackb);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stacka, stackb);
	else
		ft_free_ska_skb(stacka, stackb, line);
}

void	ft_read(t_nbrs **stacka, t_nbrs **stackb)
{
	char	*tmp;
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		tmp = line;
		check_intraction(stacka, stackb, line);
		line = get_next_line(0);
		free(tmp);
	}
	free(line);
}

int	main(int ac, char *av[])
{
	t_nbrs	*stacka;
	t_nbrs	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac != 1)
	{
		parse_init_stacka(&stacka, av);
		ft_read(&stacka, &stackb);
		if (stackb)
			write(1, "KO\n", 3);
		else if (check_sorted(stacka))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_lstclear(&stacka);
		ft_lstclear(&stackb);
	}
}
