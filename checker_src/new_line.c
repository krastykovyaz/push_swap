/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:24:18 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:24:19 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

char	*ft_strdub(const char *s)
{
	char	*t;
	int		i;

	t = (char *)malloc(sizeof(*t) * (ft_strlen(s) + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

void	ft_strdel(char **s)
{
	if (!s)
		return ;
	free((void *)*s);
	*s = NULL;
}

int		new_line(char **tab, char **line, int fd, int text)
{
	int		len;
	char	*tmp;

	len = 0;
	while (tab[fd][len] != '\n' && tab[fd][len] != '\0')
		len++;
	if (tab[fd][len] == '\n')
	{
		*line = ft_strsub(tab[fd], 0, len);
		tmp = ft_strdub(tab[fd] + len + 1);
		free(tab[fd]);
		tab[fd] = tmp;
		if (tab[fd][0] == '\0')
			ft_strdel(&tab[fd]);
	}
	else if (tab[fd][len] == '\0')
	{
		if (text == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdub(tab[fd]);
		ft_strdel(&tab[fd]);
	}
	return (1);
}
