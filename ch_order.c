#include "./includes/checker.h"

void free_st(t_folder **A, t_folder **B)
{
    t_folder *tmp;

    while(*A)
    {
        tmp = (*A);
        tmp->data = 0;
        *A = (*A)->next;
        free(tmp);
    }
    while (*B)
    {
        tmp = (*B);
        tmp->data = 0;
        *B = (*B)->next;
        free(tmp);
    }
}

void ch_order(t_folder **A, t_num *count)
{
    int flag;
    t_folder *tmp;

    flag = 0;
    tmp = *A;
    if (count->c_B)
        flag = 1;
    while (tmp && tmp->next)
    {
        if (tmp->next)
            if (tmp->data > tmp->next->data)
                flag = 1;
        tmp = tmp->next;
    }
    if (flag)
        write(1, "KO\n", 3);
    else
        write(1, "OK\n", 3);
}