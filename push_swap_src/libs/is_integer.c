/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 19:17:20 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/25 09:36:45 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
