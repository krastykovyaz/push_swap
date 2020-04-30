#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef HEADER_H
# define HEADER_H

typedef	struct			s_folder
{
	int					data;
	int					index;
	struct s_folder		*next;
}						t_folder;

typedef	struct			s_num
{
	int					c_A;
	int					c_B;
}						t_num;

int main(int ac, char **av);
t_folder *read_seq(char **av, t_num *count);
char **ft_strsplit(const char *s, char c);
int pushtostack(char **tab, t_folder **A);
int check_s(char **s);

__int128_t	ft_atoiS(const char *str);
char	*ft_itoaS(long long int n);

#endif