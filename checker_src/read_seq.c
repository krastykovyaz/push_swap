/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_seq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:29:57 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/21 08:59:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void		free_stack(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_folder	*read_seq(char **av, t_num *count)
{
	int			i;
	char		**new;
	t_folder	*a;

	i = 1;
	count->c_a = 0;
	count->c_b = 0;
	a = NULL;
	while (av[i])
	{
		new = ft_strsplit(av[i], ' ');
		if (check_s(new))
			n_valid();
		count->c_a += pushtostack(new, &a);
		if (count->c_a < 0)
			exit(-1);
		i++;
		free_stack(new);
	}
	if (count->c_a == 1)
	{
		write(1, "OK\n", 3);
		exit(-1);
	}
	return (a);
}
