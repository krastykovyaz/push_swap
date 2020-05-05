#include "./includes/checker.h"

void rra(t_folder **A)
{
    t_folder *start;
    t_folder *finish;
    t_folder *tmp;

    if (*A)
    {
        tmp = *A;
        finish = *A;
        start = *A;
        while (start->next != NULL)
        {
            start = start->next;
            if (start->next != NULL)
                finish = finish->next;
        }
        if (start->next == NULL)
        {
            start->next = tmp;
            finish->next = NULL;
        }
        *A = start;
    }
}

void rrb(t_folder **B)
{
    t_folder *x;
    t_folder *y;
    t_folder *z;

    x = *B;
    y = *B;
    z = *B;
    if (*B)
    {
        while (x->next != NULL)
        {
            x = x->next;
            if (x->next != NULL)
                y = y->next;
        }
        if (x->next == NULL)
        {
            x->next = z;
            y->next = NULL;
        }
    }
}

void rrr(t_folder **A,t_folder **B)
{
    if (*B && *A)
    {
        rra(A);
        rrb(B);
    }
}