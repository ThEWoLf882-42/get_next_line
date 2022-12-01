/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:48:22 by agimi             #+#    #+#             */
/*   Updated: 2022/11/06 11:55:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *naah, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!naah)
	{
		naah = (char *)malloc(1 * sizeof(char));
		naah[0] = '\0';
	}
	if (!naah || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(naah) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (naah)
		while (naah[++i] != '\0')
			str[i] = naah[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(naah) + ft_strlen(buff)] = '\0';
	free(naah);
	return (str);
}

char	*thisone(char *naah)
{
	int		i;
	char	*str;

	i = 0;
	if (!naah[i])
		return (NULL);
	while (naah[i] && naah[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (naah[i] && naah[i] != '\n')
	{
		str[i] = naah[i];
		i++;
	}
	if (naah[i] == '\n')
	{
		str[i] = naah[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*notthisone(char *naah)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (naah[i] && naah[i] != '\n')
		i++;
	if (!naah[i])
	{
		free(naah);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(naah) - i + 1));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (naah[i])
		str[j++] = naah[i++];
	str[j] = '\0';
	free(naah);
	return (str);
}
