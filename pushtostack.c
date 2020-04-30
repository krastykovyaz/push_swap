#include "./includes/checker.h"

int ch_num(int data, t_folder **A)
{
    t_folder *buf;

    buf = *A;
    while (buf)
    {
        if (buf->data == data)
            return (1);
        buf = buf->next;
    }
    return (0);
}
void ch_int(char *tab, t_folder *head, t_folder **A)
{
    head->data = ft_atoiS(tab);
    if (ch_num(head->data, A))
    {
        write(1, "Error\n", 6);
		exit(-1);
    }
    head->next = NULL;
}

t_folder *skip(t_folder **A)
{
    t_folder *last_nb;

    last_nb = *A;
    while (last_nb->next != NULL)
        last_nb = last_nb->next;
    return(last_nb);
}

int pushtostack(char **tab, t_folder **A)
{
    int i;
    t_folder *head;
    t_folder *buf;

    i = 0;
    while(tab[i])
    {
        if (!(head = malloc(sizeof(t_folder))))
            return (0);
        if (ft_atoiS(tab[i]) <= 2147483647 && ft_atoiS(tab[i]) >= -2147483648)
            ch_int(tab[i], head, A);
        else
            return (0);
        if (*A)
        {
            buf = skip(A);
            buf->next = head;
        }
        else
            *A = head;
        i++;
    }
    return (i);
}