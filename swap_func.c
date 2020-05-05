#include "./includes/checker.h"

void sa(t_folder **A)
{
    t_folder *tmp;

    if (*A == NULL)
        return ;
    tmp = *A;
    *A = (*A)->next;
    tmp->next = (*A)->next;
    (*A)->next = tmp;
}

void sb(t_folder **B)
{
    t_folder *tmp;

    if (*B == NULL)
        return ;
    tmp = *B;
    *B = (*B)->next;
    tmp->next = (*B)->next;
    (*B)->next = tmp;
}

void ss(t_folder **A, t_folder **B)
{
    sa(A);
	sb(B);
}