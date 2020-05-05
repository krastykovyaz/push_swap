#include "./includes/checker.h"

int com_inspect(t_folder **A, t_folder **B, char *line, t_num *count)
{
    int i;

    i = ft_strlen(line);
    if (i == 2 && line[0] == 's' && line[1] == 'a')
        sa(A);
    else if (i == 2 && line[0] == 's' && line[1] == 'b')
        sb(B);
    else if (i == 2 && line[0] == 's' && line[1] == 's')
        ss(A, B);
    else if (i == 2 && line[0] == 'p' && line[1] == 'a')
        pa(A, B, count);
    else if (i == 2 && line[0] == 'p' && line[1] == 'b')
        pb(A, B, count);
    else if (i == 2 && line[0] == 'r' && line[1] == 'a')
        ra(A);
    else if (i == 2 && line[0] == 'r' && line[1] == 'b')
        rb(B);
    else if (i == 2 && line[0] == 'r' && line[1] == 'r')
        rr(A, B);
    else if (i == 3 && line[0] =='r' && line[1] == 'r' && line[2] == 'a')
        rra(A);
    else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
        rrb(B);
    else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
        rrr(A, B);
    else
        return (1);
    return(0);
}