/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:50:10 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/27 17:25:04 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define COLOR_NORMAL	"\x1B[0m"
# define COLOR_RED		"\x1B[31m"
# define COLOR_GREEN	"\x1B[32m"
# define COLOR_YELLOW	"\x1B[33m"
# define COLOR_BLUE		"\x1B[34m"
# define COLOR_MAGENTE	"\x1B[35m"
# define COLOR_CYAN		"\x1B[36m"
# define COLOR_WHITE	"\x1B[37m"

typedef	struct	s_pr
{
	int			nb;
	int			i;
	char		plus;
	char		minus;
	char		space;
	char		grid;
	int			zero;
	int			width;
	int			accuracy;
	int			dot;
	int			size;
	__int128_t	a;
	int			len;
	char		*ptr;
	long double	fl;
	long double	fl_save;
	char		*s;
}				t_pr;

int				ft_printf(const char *format, ...);
void			free_list(t_pr *stut);
int				percent(va_list arg, const char *format, t_pr *stut);
void			ft_putchar(const char c, t_pr *stut);
int				flag(va_list arg, const char *format, t_pr *stut);
int				width(va_list arg, const char *format, t_pr *stut);
int				ft_atoi(const char *str);
int				if_digit(int c);
int				precision(va_list ap, const char *format, t_pr *stut);
int				size(va_list ap, const char *format, t_pr *stut);
int				search_type(va_list ap, const char *format, t_pr *stut);
int				type_decimal_size(va_list ap, const char *format, t_pr *stut);
void			ft_putstr(const char *str, t_pr *stut);
void			type_decimal_priority(const char *format, t_pr *stut);
int				decimal_pregular_space(t_pr *stut);
int				type_decimal_regular(t_pr *stut);
int				ft_strlen(const char *str);
char			*ft_itoa(long long int n);
char			*ft_itoa2(long long int n);
void			ft_putnchar(const char c, int i, t_pr *stut);
void			ft_putnbr(__int128 n, t_pr *stut);
void			ft_putstring(char *line);
__int128_t		convert(t_pr *stut, int base);
int				type_decimal_minus(t_pr *stut);
int				type_decimal_plus(const char *format, t_pr *stut);
int				type_decimal_zero(t_pr *stut);
int				type_decimal_space(const char *format, t_pr *stut);
void			decimal_pregular_zero(int i, t_pr *stut);
int				type_octal_size(va_list ap, t_pr *stut);
int				type_priority_octal(t_pr *stut);
int				type_octal_minus(t_pr *stut);
int				type_octal_zero(t_pr *stut);
int				type_octal_regular(t_pr *stut);
int				type_hex_size(va_list ap, const char *format, t_pr *stut);
int				type_priority_hex(const char *format, t_pr *stut);
char			*convert_hex(const char *format, t_pr *stut, int base);
int				type_hex_minus(const char *format, t_pr *stut);
int				type_hex_regular(const char *format, t_pr *stut);
int				type_float_size(va_list ap, t_pr *stut);
int				type_float_priority(t_pr *stut);
int				float_minus(t_pr *stut);
void			convertf(t_pr *stut);
int				float_zero(t_pr *stut);
int				float_plus(t_pr *stut);
int				float_space(t_pr *stut);
int				regular_float(t_pr *stut);
int				ft_round(__int128_t n);
__int128_t		afterdot(__int128_t n, int i);
void			ft_float(long long nb, __int128_t n, long long i, t_pr *stut);
void			convertf2(t_pr *stut);
int				type_str(va_list ap, const char *format, t_pr *stut);
void			ft_putnstr(const char *s, int k, t_pr *stut);
void			raise_flag_error(char flag);
void			raise_memory_error();
void			raise_error(char *message);
void			parse_colors_flags(const char *format, t_pr *stut);
void			append_symb(char **line, char symb);
int				ft_equal(char *one, char *two);
int				type_address(const char *format, void *p, t_pr *stut);
int				type_perc(t_pr *stut);
char			*ft_strdup(char *line);
void			empty_line(char **line);

#endif
