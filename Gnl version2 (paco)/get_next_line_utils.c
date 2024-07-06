/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czamora- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:16:07 by czamora-          #+#    #+#             */
/*   Updated: 2024/07/06 18:57:07 by czamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2)
		return (NULL);
	if (str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str [i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	caracter;
	char	*cadena;

	cadena = (char *)s;
	caracter = (char )c;
	while (*cadena)
	{
		if (*cadena == caracter)
			return (cadena);
		cadena++;
	}
	if (caracter == '\0')
		return (cadena);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	while (start < len && s[start++])
		str[start] = s[start];
	str[start] = '\0';
	return (str);
}
