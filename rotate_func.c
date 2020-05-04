#include "./includes/checker.h"

void ra(t_folder **A, int i)
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
        if (i)
            write(1, "ra\n", 3);
    }
}

void rb(t_folder **B, int i)
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
        if (i)
            write(1, "rb\n", 3);
    }
}

void rr(t_folder **A, t_folder **B, int i)
{
    if (*B && *A)
    {
        ra(A, i);
        rb(B, i);
    }
    if (i)
		write(1, "rr\n", 3);
}