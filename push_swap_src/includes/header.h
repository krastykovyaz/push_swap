/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:11:27 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/20 20:00:05 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct			s_stack
{
	int					index;
	int					element;
	struct s_stack		*next;
}						t_stack;

typedef struct			s_pos
{
	int					min_position;
	int					min_element;
	int					max_position;
	int					max_element;
	int					len;
}						t_pos;

void					raise_not_integer_error();
void					raise_memory_error(void);
void					raise_not_unique_error(void);
int						is_integer(char *line);
void					print_both_stack(t_stack *a, t_stack *b);
int						get_largest_width(t_stack *stack);
void					print_n_spaces(int n);
void					print_init(t_stack *a);
int						is_sorted(t_stack *stack);
void					print_answer(t_stack *a);
int						check_unique_int_mass(int len, int *mass);
void					pass(void);
void					swap(t_stack *stack, char act);
void					push(t_stack **rem_head, t_stack **get_head, char act);
void					rotate(t_stack **stack, char act);
void					reverse_rotate(t_stack **stack, char act);
t_stack					*create_head(int element);
void					free_stack(t_stack *stack);
t_stack					*init_stack_with_mass(int len, int *mass);
t_stack					*init_stack_with_char_mass(int len, char **av);
void					print_stack(t_stack *stack);
int						delete_element(t_stack **stack, int i);
int						delete_head(t_stack **head);
int						delete_last(t_stack *stack);
void					append_element(int element, t_stack *stack);
void					append_head(t_stack **stack, int element);
int						stack_len(t_stack *stack);
int						have_two(t_stack *stack);
t_pos					get_position_info(t_stack *stack);
void					ft_qsort(int len, int *mass);
int						*stack_2_mass(int len, t_stack *a);
t_pos					get_position(t_stack *stack);
void					solve_2(t_stack **a);
void					solve_3(t_stack **a);
void					solve_4(t_stack **a);
void					solve_5(t_stack **a);
void					solve_b(t_stack **a, t_stack **b);
void					mysolve(t_stack **a, int col_blocks);
void					move_one_smaller(t_stack **a, t_stack **b);
void					switcher(t_stack *a);
int						ft_atoi(const char *str);
int						is_int(char *str);

#endif
