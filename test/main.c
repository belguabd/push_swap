#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
// int ft_atoi(const char *str)
// {
//     int sign;
//     unsigned long long res;
//     int i;

//     i = 0;
//     sign = 1;
//     res = 0;
//     while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
//         i++;
//     if (str[i] == '-' || str[i] == '+')
//         if (str[i++] == '-')
//             sign *= -1;
//     if (str[i] && (str[i] < '0' || str[i] > '9'))
//     {
//         write(1, "Error", 5);
//         exit(1);
//     }
//     while (str[i] && str[i] >= '0' && str[i] <= '9')
//     {
//         res = (str[i] - 48) + (res * 10);
//         if (res > LONG_MAX)
//         {
//             if (sign == 1)
//                 return (-1);
//             return (0);
//         }
//         i++;
//     }
//     if (str[i] && (str[i] < '0' || str[i] > '9'))
//     {
//         write(1, "Error", 5);
//         exit(1);
//     }

//     return (res * sign);
// }
// typedef struct Numbers
// {
//     int nbr;
//     struct Numbers *next;
// } t_list;
// t_list *add_new(int nbr)
// {
//     t_list *p;
//     p = (t_list *)malloc(sizeof(t_list));
//     if (!p)
//         return (NULL);
//     // p->nbr = nbr;
//     p->next = NULL;
//     return (p);
// }

// void ft_add_back(t_list **list, t_list *new)
// {
//     t_list *current = *list;
//     while (current->next)
//         current = current->next;
//     current->next = new;
// }

// void ft_add_front(t_list **list, t_list *new)
// {
//     new->next = *list;
//     *list = new;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct Numbers
{
    int i;
    struct Numbers *next;
} t_list;

t_list *add_new(int i)
{
    t_list *p;
    p = (t_list *)malloc(sizeof(t_list));
    if (!p)
        return (NULL);
    p->i = i;
    p->next = NULL;
    return (p);
}
int main(int ac, char *av[])
{
    t_list *list = add_new(1);
    list->i++;
    printf("%d\n", list->i);

    return 0;
}
