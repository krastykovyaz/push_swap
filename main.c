#include "./includes/checker.h"

int main(int ac, char **av)
{
    t_folder *A;
    t_folder *B;
    t_num count;
    char *line;

    A = NULL;
    B = NULL;
    if (ac != 1)
        A = read_seq(av, &count);
    else
        exit(-1);
    while (get_next_line(0, &line) == 1)
    {
        if (com_inspect(&A, &B, line, &count))
        {
            write(1, "Error\n", 6);
            exit(-1);
        }
        if (line)
        {
            free(line);
            line = NULL;
        }
    }
    ch_order(&A, &count);
    free_st(&A, &B);
    return (0);
}