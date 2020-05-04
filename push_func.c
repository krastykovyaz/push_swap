#include "./includes/checker.h"

void pa(t_folder **A, t_folder **B, t_num *count, int i)
{
    t_folder *tmp;

    if (*B)
    {
        tmp = (*B);
        (*B) = (*B)->next;
        tmp->next = NULL;
        if ((*A) == NULL)
            *A = tmp;
        else
        {
            tmp->next = (*A);
            *A = tmp;
        }
        count->c_A++;
        count->c_B--;
        if (i)
            write(1, "pa\n", 3);
    }
}

void pb(t_folder **A, t_folder **B, t_num *count, int i)
{
    t_folder *tmp;

    if (*B)
    {
        tmp = *B;
        *B = (*B)->next;
        tmp->next = NULL;
        if (!*A)
            *A = tmp;
        else
        {
            tmp->next = *A;
            *A = tmp;
        }
        count->c_A++;
        count->c_B--;
        if (i)
            write(1, "pb\n", 3);
    }
}
