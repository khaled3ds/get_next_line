/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:36:27 by kadas             #+#    #+#             */
/*   Updated: 2025/09/24 18:05:53 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nextline(char *next)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (next[i] && next[i] != '\n')
		i++;
	if (next[i] == '\0')
	{
		free(next);
		return (NULL);
	}
	i++;
	s = malloc(ft_strlen(next) - i + 1);
	if (!s)
	{
		free(next);
		return (NULL);
	}
	while (next[i])
		s[j++] = next[i++];
	s[j] = '\0';
	free(next);
	return (s);
}

char	*returnval(char *next)
{
	char	*r;
	int		i;

	i = 0;
	while (next[i] && next[i] != '\n')
		i++;
	if (next[i] == '\n')
		r = malloc(i + 2);
	else
		r = malloc(i + 1);
	if (!r)
		return (NULL);
	i = 0;
	while (next[i] && next[i] != '\n')
	{
		r[i] = next[i];
		i++;
	}
	if (next[i] == '\n')
		r[i++] = '\n';
	r[i] = '\0';
	return (r);
}

char	*readline2(int i, int fd, char *s, char *next)
{
	while (i > 0 && !ft_strchr(next, '\n'))
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == -1)
		{
			free(next);
			free(s);
			return (NULL);
		}
		s[i] = '\0';
		next = ft_strjoin(next, s);
		if (!next)
		{
			free(s);
			return (NULL);
		}
	}
	return (next);
}

char	*readline(int fd, char *next)
{
	int		i;
	char	*s;

	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	i = read(fd, s, BUFFER_SIZE);
	if (i == -1)
	{
		free(next);
		free(s);
		return (NULL);
	}
	s[i] = '\0';
	next = ft_strjoin(next, s);
	if (!next)
	{
		free(s);
		return (NULL);
	}
	next = readline2(i, fd, s, next);
	free(s);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*returned;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next = readline(fd, next);
	if (!next || next[0] == '\0')
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	returned = returnval(next);
	if (!returned)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	next = nextline(next);
	return (returned);
}
