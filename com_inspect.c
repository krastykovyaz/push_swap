#include "./includes/checker.h"

int com_inspect_cont(t_folder **A, t_folder **B, char *line, int i)
{
    if (i == 2 && line[0] == 'r' && line[1] == 'b')
        rb(B, 0);
    else if (i == 2 && line[0] == 'r' && line[1] == 'r')
        rr(A, B, 0);
    else if (i == 3 && line[0] =='r' && line[1] == 'r' && line[2] == 'a')
        rra(A, 0);
    else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
        rrb(B, 0);
    else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
        rrr(A, B, 0);
    else
        return (1);
    return (0);
}

int com_inspect(t_folder **A, t_folder **B, char *line, t_num *count)
{
    int i;

    i = ft_strlen(line);
    if (i == 2 && line[0] == 's' && line[1] == 'a')
        sa(A, 0);
    else if (i == 2 && line[0] == 's' && line[1] == 'b')
        sb(B, 0);
    else if (i == 2 && line[0] == 's' && line[1] == 's')
        ss(A, B, 0);
    else if (i == 2 && line[0] == 'p' && line[1] == 'a')
        pa(A, B, count, 0);
    else if (i == 2 && line[0] == 'p' && line[1] == 'b')
        pb(A, B, count, 0);
    else if (i == 2 && line[0] == 'r' && line[1] == 'a')
        ra(A, 0);
    else if (com_inspect_cont(A, B, line, i))
        return(1);
    return(0);
}