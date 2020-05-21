/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:19:19 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:20:10 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

char	*ft_strsub(const char *s, unsigned int a, size_t b)
{
	char			*tab;
	unsigned int	i;

	if (!s || !(tab = (char *)malloc(sizeof(char *) * (b + 1))))
		return (NULL);
	i = 0;
	while (b-- > 0)
	{
		if (s[a + i] == '\0')
			return (0);
		tab[i] = s[a + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
