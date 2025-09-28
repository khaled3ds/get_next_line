/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadas <kadas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:05:14 by kadas             #+#    #+#             */
/*   Updated: 2025/09/01 20:23:21 by kadas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*c;

	i = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	c = malloc(s1len + s2len + 1);
	if (!c)
		return (NULL);
	while (++i < s1len)
		c[i] = s1[i];
	i = -1;
	while (++i < s2len)
		c[i + s1len] = s2[i];
	c[s1len + s2len] = '\0';
	free(s1);
	return (c);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;
	size_t	l;

	l = 0;
	if (!s)
		return (NULL);
	while (s[l])
		l++;
	d = malloc((l + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
