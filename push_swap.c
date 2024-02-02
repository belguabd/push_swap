/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:19:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 17:25:09 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool check_sorted(t_nbrs *head)
{
	while (head->next)
	{
		if (head->number > head->next->number)
			return (false);
		head = head->next;
	}
	return (true);
}

void sort_list(t_nbrs *head)
{
	t_nbrs *temp;
	t_nbrs *temp2;

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

void parse_init_stacka(t_nbrs **stacka, char **av)
{
	t_nbrs *temp;
	char **res;
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			ft_free_split(res);
			ft_lstclear(stacka);
			exit(write(2, "Error\n", 6));
		}
		res = ft_split(av[i], ' ');
		if (!res[0])
		{
			ft_free_split(res);
			ft_lstclear(stacka);
			exit(write(2, "Error\n", 6));
		}
		j = 0;
		while (res[j])
		{
			temp = ft_addnew_nbr(parsing(res[j], stacka));
			// if (!temp)
			// 	ft_lstclear(stacka);
			ft_lstadd_end(stacka, temp, res);
			j++;
		}
		i++;
		ft_free_split(res);
	}
	if (check_sorted(*stacka))
	{
		ft_free_split(res);
		ft_lstclear(stacka);
		exit(1);
	}
}

int main(int ac, char *av[])
{
	t_nbrs *stacka;
	t_nbrs *stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac != 1)
	{
		parse_init_stacka(&stacka, av);
		sort_list(stacka);
		sort_normal(&stacka, &stackb);
		if (ft_lstsize(stacka) > 5)
			sort_big(&stacka, &stackb);
		ft_lstclear(&stacka);
	}
	return (0);
}
