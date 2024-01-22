
#include <stdio.h>
#include "rules.h"

t_nbrs *ft_addnew_nbr(int number)
{
    t_nbrs *p;
    p = (t_nbrs *)malloc(sizeof(t_nbrs));
    if (!p)
        return (NULL);
    p->number = number;
    p->index = 0;
    p->next = NULL;
    return (p);
}

void show_numbers(t_nbrs *head)
{
    while (head)
    {
        printf("%d\n", head->number);
        head = head->next;
    }
}

int main()
{
    t_nbrs *stacka = ft_addnew_nbr(9);
    stacka->next = ft_addnew_nbr(-4);
    stacka->next->next = ft_addnew_nbr(3);
    stacka->next->next->next = ft_addnew_nbr(6);
    // rra(&stacka);
    // show_numbers(stacka);
    t_nbrs *stackb = ft_addnew_nbr(5);
    stackb->next = ft_addnew_nbr(-2);
    stackb->next->next = ft_addnew_nbr(3);
    stackb->next->next->next = ft_addnew_nbr(6);

    // rrr(&stacka, &stackb);
    printf("************stacka************\n");
    show_numbers(stacka);
    printf("************stackb************\n");
    show_numbers(stackb);
    // rrb(&stacka);
    pa(&stacka,&stackb);
    printf("=========+++stacka++=========\n");
    show_numbers(stacka);
    printf("=========+++stackb++=========\n");
    show_numbers(stackb);

    return 0;
}