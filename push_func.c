#include "./includes/checker.h"

void pa(t_folder **A, t_folder **B, t_num *count)
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
    }
}

void pb(t_folder **A, t_folder **B, t_num *count)
{
    t_folder *tmp;

    if (*A)
    {
        tmp = *A;
        *A = (*A)->next;
        tmp->next = NULL;
        if (!*B)
            *B = tmp;
        else
        {
            tmp->next = *B;
            *B = tmp;
        }
        count->c_A--;
        count->c_B++;
    }
}
