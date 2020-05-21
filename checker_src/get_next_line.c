/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:20:23 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:22:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	len;

	s = (char *)malloc(sizeof(*s) * (size + 1));
	if (!s)
		return (NULL);
	len = size + 1;
	while (len-- > 0)
		((unsigned char *)s)[len] = (unsigned char)'\0';
	return (s);
}

char	*ft_strchr(const char *buffer, int c)
{
	char	*s;
	int		i;

	if ((char)c == '\0')
		return ((char *)buffer + ft_strlen(buffer));
	i = 0;
	s = (char *)buffer;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	char	*s12;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s12 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s12)
		return (NULL);
	while (s1[j])
	{
		s12[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		s12[i++] = s2[j++];
	}
	s12[i] = '\0';
	return (s12);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			text;
	static char	*s[255];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((text = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[text] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		temp = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (text < 0)
		return (-1);
	else if (text == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (new_line(s, line, fd, text));
}
