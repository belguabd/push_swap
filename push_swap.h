/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:08:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:11 by belguabd         ###   ########.fr       */
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

/*part parsing*/
int parsing(const char *str);

typedef struct Numbers
{
	int number;
	int index;
	struct Numbers *next;
} t_nbrs;
/* Instructions */
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

/*utils*/
int ft_lstsize(t_nbrs *head);

char **ft_split(char const *str, char c);
/*struct for ft_split*/
typedef struct s_vars
{
	char **res;
	int i;
	int j;
	int flage;
	int start;
} t_vars;

void ft_lstadd_end(t_nbrs **lst, t_nbrs *new);
t_nbrs *ft_addnew_nbr(int number);
#endif