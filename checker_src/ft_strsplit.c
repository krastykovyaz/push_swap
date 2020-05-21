/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:17:01 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:19:03 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

static size_t	count_words(const char *s, char c)
{
	size_t i;

	i = 0;
	while (*s && s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char		**ft_free(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s[i]);
	free(s);
	s = NULL;
	return (s);
}

static size_t	ft_strsplit_count_len(char *s, char c)
{
	size_t j;

	j = 0;
	while (*s && *s != c)
	{
		j++;
		s++;
	}
	return (j);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	count;
	size_t	i;
	size_t	j;

	count = count_words((char *)s, c);
	if (!s || !(tab = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		j = 0;
		while (s && *s && *s == c)
			s++;
		j = ft_strsplit_count_len((char*)s, c);
		if (!(tab[i] = ft_strsub(s, 0, j)))
			return (ft_free(tab, i));
		while (s && *s && *s != c)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
