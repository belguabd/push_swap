/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:22:29 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 12:40:32 by belguabd         ###   ########.fr       */
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

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	check_intraction(t_nbrs **stacka, t_nbrs **stackb, char *line)
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
		exit(write(2, "Error\n", 6));
}

void	parse_init_stacka(t_nbrs **stacka, char **av)
{
	t_nbrs	*temp;
	char	**res;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			exit(write(2, "Error\n", 6));
		res = ft_split(av[i], ' ');
		if (!res[0])
			exit(write(2, "Error\n", 6));
		j = 0;
		while (res[j])
		{
			temp = ft_addnew_nbr(parsing(res[j]));
			ft_lstadd_end(stacka, temp);
			j++;
		}
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_nbrs	*stacka;
	t_nbrs	*stackb;
	char	*line;

	stacka = NULL;
	stackb = NULL;
	line = NULL;
	if (ac != 1)
	{
		parse_init_stacka(&stacka, av);
		line = get_next_line(0);
		while (line)
		{
			check_intraction(&stacka, &stackb, line);
			line = get_next_line(0);
		}
		if (stackb)
			write(1, "KO\n", 3);
		else if (check_sorted(stacka))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
