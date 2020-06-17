/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:13:31 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 16:17:26 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	n_valid(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int		is_integer(char *line)
{
	int i;

	i = 0;
	if (line[0] == '-' && line[1] == '\0')
		return (0);
	if (line[i] == '-')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	parenth_check(int len, char **av)
{
	int i;

	if (len < 2)
	{
		exit(0);
	}
	i = 1;
	while (i < len)
	{
		if (!is_integer(av[i]))
			n_valid();
		i++;
	}
}

int		main(int ac, char **av)
{
	t_folder	*a;
	t_folder	*b;
	t_num		count;
	char		*line;

	a = NULL;
	b = NULL;
	parenth_check(ac, av);
	if (ac != 1)
		a = read_seq(av, &count);
	else
		exit(-1);
	while (get_next_line(0, &line) == 1)
	{
		if (com_inspect(&a, &b, line, &count))
			n_valid();
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	ch_order(&a, &count);
	free_st(&a, &b);
	return (0);
}
