/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:15:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 22:52:10 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_sign(char c, int *i, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			(*sign) *= -1;
		(*i)++;
	}
}

void	ft_exit(t_nbrs **stacka, char **str)
{
	ft_free_split(str);
	ft_lstclear(stacka);
	exit(write(2, "Error\n", 6));
}

int	parsing(char *str, t_nbrs **stacka, char **res_spl)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] >= 9 && str[i] <= 13)
		ft_exit(stacka, res_spl);
	while (str[i] == 32)
		i++;
	ft_check_sign(str[i], &i, &sign);
	if (!str[i])
		ft_exit(stacka, res_spl);
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		ft_exit(stacka, res_spl);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i++] - 48) + (res * 10);
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			ft_exit(stacka, res_spl);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		ft_exit(stacka, res_spl);
	return (res * sign);
}
