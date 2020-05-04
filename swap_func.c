#include "./includes/checker.h"

void sa(t_folder **A, int i)
{
    t_folder *tmp;

    if (*A == NULL)
        return ;
    tmp = *A;
    *A = (*A)->next;
    tmp->next = (*A)->next;
    (*A)->next = tmp;
    if (i)
        write(1, "sa\n", 3);
}

void sb(t_folder **B, int i)
{
    t_folder *tmp;

    if (*B == NULL)
        return ;
    tmp = *B;
    *B = (*B)->next;
    tmp->next = (*B)->next;
    (*B)->next = tmp;
    if (i)
        write(1, "sb\n", 3);
}

void ss(t_folder **A, t_folder **B, int i)
{
    t_folder *tmp;

    sa(A, 0);
	sb(B, 0);
	if (i)
		write(1, "ss\n", 3);
}