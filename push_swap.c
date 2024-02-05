/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/05 11:23:22 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_nbrs *head)
{
	while (head->next)
	{
		if (head->number > head->next->number)
			return (false);
		head = head->next;
	}
	return (true);
}

void	set_index(t_nbrs *head)
{
	t_nbrs	*temp;
	t_nbrs	*temp2;

	temp = head;
	while (temp->next)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->number > temp2->number)
				temp->index++;
			else
				temp2->index++;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	fill_stacka(char **res, t_nbrs **stacka)
{
	t_nbrs	*temp;
	int		i;

	i = 0;
	while (res[i])
	{
		temp = ft_addnew_nbr(parsing(res[i], stacka, res));
		if (!temp)
		{
			ft_lstclear(stacka);
			ft_free_split(res);
			exit(1);
		}
		ft_lstadd_end(stacka, temp, res);
		i++;
	}
	ft_free_split(res);
}

void	parse_init_stacka(t_nbrs **stacka, char **av)
{
	char	**res;
	int		i;

	i = 1;
	while (av[i])
	{
		res = ft_split(av[i], ' ');
		if (!res)
		{
			ft_lstclear(stacka);
			exit(1);
		}
		if (!res[0])
		{
			ft_lstclear(stacka);
			ft_free_split(res);
			exit(write(2, "Error\n", 6));
		}
		fill_stacka(res, stacka);
		i++;
	}
	if (check_sorted(*stacka))
		return (ft_lstclear(stacka), exit(0));
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
		set_index(stacka);
		sort_normal(&stacka, &stackb);
		if (ft_lstsize(stacka) > 5)
			sort_big(&stacka, &stackb);
		ft_lstclear(&stacka);
	}
	return (0);
}
