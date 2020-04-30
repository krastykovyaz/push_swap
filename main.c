#include "./includes/checker.h"

int main(int ac, char **av)
{
    t_folder *A;
    t_folder *B;
    t_num count;

    A = NULL;
    B = NULL;
    if (ac != 1)
        A = read_seq(av, &count);
    else
        exit(-1);
    printf("OK\n");
    return (0);
}