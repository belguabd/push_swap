/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:08:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/24 14:24:40 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
int parsing(const char *str);
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

void sa(t_nbrs **stacka);
void sb(t_nbrs **stackb);
void ss(t_nbrs **stacka, t_nbrs **stackb);
void ra(t_nbrs **stacka);
void rb(t_nbrs **stackb);
void rr(t_nbrs **stacka, t_nbrs **stackb);
void rra(t_nbrs **stacka);
void rrb(t_nbrs **stackb);
void rrr(t_nbrs **stacka, t_nbrs **stackb);
void pa(t_nbrs **stacka, t_nbrs **stackb);
void pb(t_nbrs **stacka, t_nbrs **stackb);
#endif