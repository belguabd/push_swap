/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:47:59 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/03 09:14:23 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

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

void	fill_stacka(char **res, t_nbrs **stacka)
{
	t_nbrs	*temp;
	int		i;

	i = 0;
	while (res[i])
	{
		temp = ft_addnew_nbr(parsing(res[i], stacka, res));
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
		if (av[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		res = ft_split(av[i], ' ');
		if (!res[0])
		{
			ft_free_split(res);
			exit(write(2, "Error\n", 6));
		}
		fill_stacka(res, stacka);
		i++;
	}
}
