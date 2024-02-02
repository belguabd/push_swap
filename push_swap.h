/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:08:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/02/02 12:56:52 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
/*function of get_next_line*/
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *line, char *buffer);
size_t	ft_strlen(const char *s);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/*part parsing*/
int		parsing(const char *str);
typedef struct Numbers
{
	int				number;
	int				index;
	struct Numbers	*next;

}	t_nbrs;
/* Instructions */
void	sa(t_nbrs **stacka);
void	sb(t_nbrs **stackb);
void	ss(t_nbrs **stacka, t_nbrs **stackb);
void	ra(t_nbrs **stacka);
void	rb(t_nbrs **stackb);
void	rr(t_nbrs **stacka, t_nbrs **stackb);
void	rra(t_nbrs **stacka);
void	rrb(t_nbrs **stackb);
void	rrr(t_nbrs **stacka, t_nbrs **stackb);
void	pa(t_nbrs **stacka, t_nbrs **stackb);
void	pb(t_nbrs **stacka, t_nbrs **stackb);
/*utils*/
int		ft_lstsize(t_nbrs *head);

char	**ft_split(char const *str, char c);
/*struct for ft_split*/
typedef struct s_vars
{
	char	**res;
	size_t	i;
	int		j;
	int		flage;
	int		start;
}	t_vars;
void	ft_lstadd_end(t_nbrs **lst, t_nbrs *new);
t_nbrs	*ft_addnew_nbr(int number);

/*Implementation of the sorting algorithm for normal*/

void	sort_normal(t_nbrs **stacka, t_nbrs **stackb);
/*function of sort big */
void	sort_big(t_nbrs **stacka, t_nbrs **stackb);
/* utils of sort big */
int		ft_best_move(int size, int move);
void	get_pos(t_nbrs **stackb, int nbr, int *big_pos, int *small_pos);
void	push_slnbr_ska(t_nbrs **stackb, t_nbrs **stacka,
			int *optimal_move_count_2, int *small_pos);
void	push_bignbr_ska(t_nbrs **stacka, t_nbrs **stackb,
			int *optimal_move_count_1, int *big_pos);
void	push_bignbr_to_ska(t_nbrs **stacka, t_nbrs **stackb,
			int *big_pos, int *optimal_move_count_1);
/*sort normal utils*/
int		find_min_index(t_nbrs *stacka);
void	ft_sort_two(t_nbrs *stacka);
void	ft_sort_three(t_nbrs **stacka);
void	process_stack_four(t_nbrs **stacka, t_nbrs **stackb);
void	process_stack_five(t_nbrs **stacka, t_nbrs **stackb);
#endif