/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:15:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/31 14:44:31 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int parsing(const char *str)
{
	int sign;
	long res;
	int i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] >= 9 && str[i] <= 13)
		exit(write(2, "Error\n", 6));
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!str[i])
		exit(write(2,"Error", 5));
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		exit(write(2, "Error\n", 6));
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		exit(write(2, "Error\n", 6));
	res = res * sign;
	if (res > INT_MAX || res < INT_MIN)
		exit(write(2, "Error\n", 6));
	return (res);
}
