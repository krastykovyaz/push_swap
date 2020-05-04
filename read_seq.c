#include "./includes/checker.h"

void free_stack(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab);
}

t_folder *read_seq(char **av, t_num *count)
{
    int i;
    char **new;
    t_folder *A;

    i = 1;
    count->c_A = 0;
    count->c_B = 0;
    A = NULL;
    while (av[i])
    {
        new = ft_strsplit(av[i], ' ');
        if (check_s(new))
        {
            write(1, "Error\n", 6);
            exit(-1);
        }
        count->c_A += pushtostack(new, &A);
        if (count->c_A < 0)
            exit(-1);
        i++;
        free_stack(new);
    }
    return(A);
}