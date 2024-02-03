/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:29 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/03 00:13:04 by belguabd         ###   ########.fr       */
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

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void check_intraction(t_nbrs **stacka, t_nbrs **stackb, char *line)
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
	{
		ft_lstclear(stacka);
		ft_lstclear(stackb);
		free(line);
		exit(write(2, "Error\n", 6));
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
			exit(write(2, "Error\n", 6));
		res = ft_split(av[i], ' ');
		if (!res[0])
		{
			ft_free_split(res);
			exit(write(2, "Error\n", 6));
		}
		j = 0;
		while (res[j])
		{
			temp = ft_addnew_nbr(parsing(res[j], stacka, res));
			ft_lstadd_end(stacka, temp, res);
			j++;
		}
		ft_free_split(res);
		i++;
	}
}

int main(int ac, char *av[])
{
	t_nbrs *stacka;
	t_nbrs *stackb;
	char *line;
	char *tmp;
	tmp = NULL;
	stacka = NULL;
	stackb = NULL;
	if (ac != 1)
	{
		parse_init_stacka(&stacka, av);
		line = get_next_line(0);
		while (line)
		{
			tmp = line;
			check_intraction(&stacka, &stackb, line);
			line = get_next_line(0);
			free(tmp);
		}
		free(line);
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
