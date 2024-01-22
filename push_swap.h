/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:08:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/22 14:29:00 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
int ft_atoi(const char *str);
char **ft_split(char const *str, char c);

typedef struct s_vars
{
	char **res;
	int i;
	int j;
	int flage;
	int start;
} t_vars;

typedef struct Numbers
{
    int number;
	int index;
    struct Numbers *next;
} t_nbrs;

#endif