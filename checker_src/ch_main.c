/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 20:13:31 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/21 16:22:36 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	n_valid(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int		main(int ac, char **av)
{
	t_folder	*a;
	t_folder	*b;
	t_num		count;
	char		*line;

	a = NULL;
	b = NULL;
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
