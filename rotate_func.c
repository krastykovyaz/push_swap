#include "./includes/checker.h"

void ra(t_folder **A)
{
    t_folder *tmp;

    if (*A)
    {
        tmp = *A;
        while ((*A)->next != NULL)
            *A = (*A)->next;
        (*A)->next = tmp;
        tmp = tmp->next;
        *A = (*A)->next;
        (*A)->next = NULL;
        *A = tmp;
    }
}

void rb(t_folder **B)
{
    t_folder *tmp;

    if (*B)
    {
        tmp = *B;
        while ((*B)->next != NULL)
            *B = (*B)->next;
        (*B)->next = tmp;
        tmp = tmp->next;
        *B = (*B)->next;
        (*B)->next = NULL;
        *B = tmp;
    }
}

void rr(t_folder **A, t_folder **B)
{
    if (*B && *A)
    {
        ra(A);
        rb(B);
    }
}