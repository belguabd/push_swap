#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h> // Added for write function
int ft_atoi(const char *str)
{
	int sign;
	unsigned long long res;
	int i;

	i = 0;
	sign = 1;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!str[i])
	{

		write(1, "Error", 5);
		exit(1);
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		write(1, "Error", 5);
		exit(1);
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + (res * 10);
		if (res > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
	{
		write(1, "Error", 5);
		exit(1);
	}

	return (res * sign);
}
typedef struct s_vars
{
	char **res;
	int i;
	int j;
	int flage;
	int start;
} t_vars;
int ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int ft_free(char **res, char *str, int index)
{
	int i;

	i = 0;
	if (!str)
	{
		while (i < index)
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (0);
	}
	return (1);
}
static int count_words(const char *str, char c)
{
	int i;
	int to_find;

	i = 0;
	to_find = 0;
	while (*str)
	{
		if (*str != c && to_find == 0)
		{
			to_find = 1;
			i++;
		}
		else if (*str == c)
			to_find = 0;
		str++;
	}
	return (i);
}

static char *word_dup(const char *str, int start, int end, int *flag)
{
	char *word;
	int i;

	word = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	*flag = 1;
	return (word);
}

char **ft_split(char const *str, char c)
{
	t_vars var;

	if (!str)
		return (NULL);
	var.res = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!var.res)
		return (NULL);
	var.i = -1;
	var.j = 0;
	var.flage = 1;
	while (++var.i <= ft_strlen(str))
	{
		if (str[var.i] != c && var.flage > 0)
		{
			var.start = var.i;
			var.flage = 0;
		}
		else if ((str[var.i] == c || !str[var.i]) && var.flage == 0)
		{
			var.res[var.j++] = word_dup(str, var.start, var.i, &var.flage);
			if (!ft_free(var.res, var.res[var.j - 1], var.j - 1))
				return (NULL);
		}
	}
	return (var.res[var.j] = 0, var.res);
}
typedef struct s_nbrs {
    int number;
    int index;
    struct s_nbrs *next;
} t_nbrs;

t_nbrs *ft_addnew_nbr(int number) {
    t_nbrs *new_nbr = (t_nbrs *)malloc(sizeof(t_nbrs));
    if (!new_nbr)
        exit(1); // Handle memory allocation failure
    new_nbr->number = number;
    new_nbr->index = 0;
    new_nbr->next = NULL;
    return new_nbr;
}

void ft_lstadd_end(t_nbrs **list, t_nbrs *new) {
    if (!list || !new)
        return; // Handle invalid input
    t_nbrs *current = *list;
    if (!current) {
        *list = new;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = new;
}

void sort_list(t_nbrs **list, t_nbrs *new) {
    t_nbrs *current = *list;
    while (current) {
        if (current->number > new->number) {
            current->index++;
        }
        current = current->next;
    }
}

void show_linked(t_nbrs *list) {
    while (list) {
        printf("Number: %d, Index: %d\n", list->number, list->index);
        list = list->next;
    }
}

int main(int ac, char *av[]) {
    if (ac > 1) { // Changed the condition to check if ac is greater than 1
        int i = 1;
        char **res;
        t_nbrs *stacka = NULL; // Initialize to NULL
        t_nbrs *temp;
        int j;
        while (av[i]) {
            if (av[i][0] == '\0') {
                write(1, "Error", 5);
                exit(1);
            }
            res = ft_split(av[i], ' '); // Assuming you have a function named ft_split
            j = 0;
            while (res[j]) {
                temp = ft_addnew_nbr(atoi(res[j])); // Changed to use atoi
                ft_lstadd_end(&stacka, temp);
                sort_list(&stacka, temp);
                j++;
            }
            i++;
        }
        show_linked(stacka);
    }
    return 0;
}
