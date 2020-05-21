/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:35:24 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/21 09:00:20 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFF_SIZE 10
# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_folder
{
	int					data;
	struct s_folder		*next;
}						t_folder;

typedef	struct			s_num
{
	int					c_a;
	int					c_b;
}						t_num;

t_folder				*read_seq(char **av, t_num *count);
char					**ft_strsplit(const char *s, char c);
int						pushtostack(char **tab, t_folder **a);
int						check_s(char **s);
int						get_next_line(const int fd, char **line);
size_t					ft_strlen(const char *s);
int						new_line(char **tab, char **line, int fd, int text);
int						com_inspect(t_folder **a, t_folder **b, \
						char *line, t_num *count);
void					ss(t_folder **a, t_folder **b);
void					sa(t_folder **a);
void					sb(t_folder **b);
void					pa(t_folder **a, t_folder **b, t_num *count);
void					pb(t_folder **a, t_folder **b, t_num *count);
void					ra(t_folder **a);
void					rb(t_folder **b);
void					rr(t_folder **a, t_folder **b);
void					rra(t_folder **a);
void					rrb(t_folder **b);
void					rrr(t_folder **a, t_folder **b);
void					ch_order(t_folder **a, t_num *count);
void					free_st(t_folder **a, t_folder **b);
char					*ft_strsub(const char *s, unsigned int a, size_t b);
void					n_valid(void);
__int128_t				ft_atois(const char *str);
char					*ft_itoas(long long int n);

#endif
