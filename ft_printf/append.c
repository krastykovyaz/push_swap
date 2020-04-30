/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:14:34 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 13:52:50 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	append_symb(char **line, char symb)
{
	char	*out;
	int		i;
	int		len;

	len = ft_strlen(*line);
	if (!(out = (char*)malloc(sizeof(char) * (len + 2))))
		raise_memory_error();
	i = 0;
	while (i < len)
	{
		out[i] = (*line)[i];
		i++;
	}
	out[i] = symb;
	out[i + 1] = '\0';
	free(*line);
	*line = out;
}
