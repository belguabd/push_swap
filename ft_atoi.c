/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:15:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/20 20:11:18 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
int ft_atoi(const char *str)
{
	int sign;
	unsigned long long res;
	int i;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!str[i])
	{

		write(1, "Error", 5);
		exit(1);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		write(1, "Error", 5);
		exit(1);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + (res * 10);
		if (res > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		write(1, "Error", 5);
		exit(1);
	}

	return (res * sign);
}
