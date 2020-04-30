/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:34:20 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 14:30:22 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	do_color(char *line)
{
	if (ft_equal(line, "red"))
		ft_putstring(COLOR_RED);
	else if (ft_equal(line, "green"))
		ft_putstring(COLOR_GREEN);
	else if (ft_equal(line, "yellow"))
		ft_putstring(COLOR_YELLOW);
	else if (ft_equal(line, "blue"))
		ft_putstring(COLOR_BLUE);
	else if (ft_equal(line, "magente"))
		ft_putstring(COLOR_MAGENTE);
	else if (ft_equal(line, "cyan"))
		ft_putstring(COLOR_CYAN);
	else if (ft_equal(line, "white"))
		ft_putstring(COLOR_WHITE);
	else if (ft_equal(line, "eoc"))
		ft_putstring(COLOR_NORMAL);
	else
	{
		free(line);
		raise_error("Unknown color");
	}
	free(line);
}

void	parse_colors_flags(const char *format, t_pr *stut)
{
	char	*line;

	line = ft_strdup("");
	empty_line(&line);
	stut->i++;
	while (format[stut->i] != '}')
	{
		if (format[stut->i] == '\0')
		{
			free(line);
			raise_error("expected: \'}\'");
		}
		append_symb(&line, format[stut->i]);
		stut->i++;
	}
	stut->i++;
	do_color(line);
}
