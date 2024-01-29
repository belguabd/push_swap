/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:36:31 by belguabd          #+#    #+#             */
/*   Updated: 2024/01/29 13:06:08 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void get_pos(t_nbrs **stackb, int a, int *big_pos, int *small_pos)
{

    (*big_pos) = 0;
    (*small_pos) = 0;
    int size = ft_lstsize(*stackb);
    t_nbrs *temp;
    temp = *stackb;
    while (temp)
    {
        if (temp->index == size - a)
            break;
        (*big_pos)++;
        temp = temp->next;
    }
    // printf("*********%d*********\n", (*big_pos));
    // printf("|||||||||||%d|||||||||||\n", size);
    temp = *stackb;
    while (temp)
    {
        if (temp->index == size - 2)
            break;
        (*small_pos)++;
        temp = temp->next;
    }
    // printf("*********%d*********\n", (*small_pos));
}
int ft_best_move(int size, int a)
{
    if (a > size / 2)
        a = size - a;
    return (a);
}

void ft_puch_stacka(t_nbrs **stacka, t_nbrs **stackb)
{

    int big_pos;
    int small_pos;
    int best_move_1;
    int best_move_2;

    // int i = 0;
    (void)stacka;
    // int i = 0;
    while (*stackb)
    {
        best_move_1 = 0;
        best_move_2 = 0;
        big_pos = 0;
        small_pos = 0;
        // show_linked_stackb(*stackb);
        get_pos(stackb, 1, &big_pos, &small_pos);

        // printf("-------------big is :{%d}--------------\n", big_pos);
        // printf("------------- small is :[%d]--------------\n", small_pos);
        // printf("-------------size is :[%d]--------------\n", ft_lstsize(*stackb));
        int max = big_pos;
        // int min = small_pos;
        best_move_1 = ft_best_move(ft_lstsize(*stackb), big_pos);
        best_move_2 = ft_best_move(ft_lstsize(*stackb), small_pos);
        // printf("-------------best_move_1 is :{%d}--------------\n", best_move_1);
        // printf("------------- best_move_2 is :[%d]--------------\n", best_move_2);

        // printf("-------------%d--------------\n", big_pos);
        // printf("-------------%d--------------\n", small_pos);
        if (best_move_2 < best_move_1)
        {
            while (best_move_2 > 0)
            {
                // printf("small%d\n",small_pos);
                if (small_pos > ft_lstsize(*stackb) / 2)
                    rrb(stackb);
                else
                {
                    // printf("hshjgsd\n");
                    rb(stackb);
                }
                best_move_2--;
            }
            pa(stacka, stackb);
            get_pos(stackb, 0, &big_pos, &small_pos);
            best_move_1 = ft_best_move(ft_lstsize(*stackb), big_pos);
            while (best_move_1 > 0)
            {
                if (big_pos > ft_lstsize(*stackb) / 2)
                    rrb(stackb);
                else
                    rb(stackb);
                best_move_1--;
            }
            // }
            pa(stacka, stackb);
            sa(stacka);
        }
        else
        {
            if (max > ft_lstsize(*stackb) / 2)
            {
                while (best_move_1--)
                    rrb(stackb);
            }
            else
            {
                while (best_move_1--)
                    rb(stackb);
            }
            pa(stacka, stackb);
        }

        // if (small_pos < big_pos)
        // {

        //     while (small_pos--)
        //         rb(stackb);
        //     pa(stacka, stackb);
        //     while (big_pos--)
        //         rb(stackb);
        //     pa(stacka, stackb);
        //     sa(stacka);
        // }
        // if (index <= ft_lstsize(*stackb) / 2)
        // {
        //     while (index--)
        //         rb(stackb);
        // }
        // else
        // {
        //     index = ft_lstsize(*stackb) - index;
        //     while (index--)
        //         rrb(stackb);
        // }
        // pa(stacka, stackb);
        // i++;
    }
}

void sort_big(t_nbrs **stacka, t_nbrs **stackb)
{
    int size_b = ft_lstsize(*stacka);
    int chunk = size_b / 5;
    if (size_b > 100)
        chunk = size_b / 9;
        
    int change_chunk = chunk;

    while (*stacka)
    {
        if ((*stacka)->index < change_chunk)
        {
            if ((*stacka)->index >= (change_chunk - (chunk / 2)))
            {
                pb(stacka, stackb);
                if((*stacka)->index >= change_chunk)
                    rr(stacka, stackb);
                else
                    rb(stackb);
            }
            else
                pb(stacka, stackb);
        }
        else
            ra(stacka);
        if (ft_lstsize(*stackb) == change_chunk)
            change_chunk += chunk;
    }
    // show_linked_stackb(*stackb);
    ft_puch_stacka(stacka, stackb);
}