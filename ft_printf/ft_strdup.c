/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:26:38 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 14:02:53 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*ft_strdup(char *line)
{
	char	*out;
	int		i;

	if (!(out = (char *)malloc(sizeof(char) * (ft_strlen(line)))))
		raise_memory_error();
	i = 0;
	while (line[i] != '\0')
	{
		out[i] = line[i];
		i++;
	}
	return (out);
}

void	empty_line(char **line)
{
	char *out;

	out = (char *)malloc(sizeof(char) * 1);
	out[0] = '\0';
	free(*line);
	*line = out;
}
