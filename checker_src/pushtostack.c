/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtostack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:26:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:29:33 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int			ch_num(int data, t_folder **a)
{
	t_folder *buf;

	buf = *a;
	while (buf)
	{
		if (buf->data == data)
			return (1);
		buf = buf->next;
	}
	return (0);
}

void		ch_int(char *tab, t_folder *head, t_folder **a)
{
	head->data = ft_atois(tab);
	if (ch_num(head->data, a))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	head->next = NULL;
}

t_folder	*skip(t_folder **a)
{
	t_folder *last_nb;

	last_nb = *a;
	while (last_nb->next != NULL)
		last_nb = last_nb->next;
	return (last_nb);
}

int			pushtostack(char **tab, t_folder **a)
{
	int			i;
	t_folder	*head;
	t_folder	*buf;

	i = 0;
	while (tab[i] != '\0')
	{
		if (!(head = malloc(sizeof(t_folder))))
			return (0);
		if (ft_atois(tab[i]) <= 2147483647 && ft_atois(tab[i]) >= -2147483648)
			ch_int(tab[i], head, a);
		else
			return (0);
		if (*a)
		{
			buf = skip(a);
			buf->next = head;
		}
		else
			*a = head;
		i++;
	}
	return (i);
}
