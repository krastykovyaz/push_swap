#ifndef CHECKER_H
# define CHECKER_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct			s_folder
{
	int					data;
	struct s_folder		*next;
}						t_folder;

typedef	struct			s_num
{
	int					c_A;
	int					c_B;
}						t_num;

t_folder *read_seq(char **av, t_num *count);
char **ft_strsplit(const char *s, char c);
int pushtostack(char **tab, t_folder **A);
int check_s(char **s);
int get_next_line(const int fd, char **line);
size_t ft_strlen(const char *s);
int new_line(char **tab, char **line, int fd, int text);
int com_inspect(t_folder **A, t_folder **B, char *line, t_num *count);
void ss(t_folder **A, t_folder **B);
void sa(t_folder **A);
void sb(t_folder **B);
void pa(t_folder **A, t_folder **B, t_num *count);
void pb(t_folder **A, t_folder **B, t_num *count);
void ra(t_folder **A);
void rb(t_folder **B);
void rr(t_folder **A, t_folder **B);
void rra(t_folder **A);
void rrb(t_folder **B);
void rrr(t_folder **A, t_folder **B);
void	ch_order(t_folder **A, t_num *count);
void free_st(t_folder **A, t_folder **B);
char *ft_strsub(const char *s, unsigned int a, size_t b);

__int128_t	ft_atoiS(const char *str);
char	*ft_itoaS(long long int n);

#endif