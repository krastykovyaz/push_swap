/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:17:01 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 16:04:21 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"
#include <stdio.h>

int		ft_strcmp(char *l1, char *l2)
{
	int	i;

	i = 0;
	while (l1[i] != '\0' && l2[i] != '\0')
	{
		if (l1[i] != l2[i])
			return (l2[i] - l1[i]);
		i++;
	}
	return (0);
}

int		is_int(char *str)
{
	int	len;
	int	is_minus;

	is_minus = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		len--;
		is_minus = 1;
		str = str + 1;
	}
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (is_minus == 1)
	{
		if (ft_strcmp(str, "2147483648") >= 0)
			return (1);
	}
	if (is_minus == 0)
		if (ft_strcmp(str, "2147483647") >= 0)
			return (1);
	return (0);
}

int		add_ch(char *s)
{
	if (!is_int(s))
		return (1);
	return (0);
}

int		check_s(char **s)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] >= 48 && s[i][j] <= 57)
				j++;
			else if ((s[i][j] == '-' || s[i][j] == '+') &&\
	s[i][j + 1] != '\0' && s[i][j + 1] >= 48 && s[i][j + 1] <= 57)
				j++;
			else
				return (1);
		}
		if (add_ch(s[i]))
			return (1);
		j = 0;
		i++;
	}
	return (0);
}
