/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:48:27 by agimi             #+#    #+#             */
/*   Updated: 2022/11/14 13:56:40 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*kra(int fd, char *naah)
{
	char	*buff;
	int		ak;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ak = 1;
	while (!ft_strchr(naah, '\n') && ak != 0)
	{
		ak = read(fd, buff, BUFFER_SIZE);
		if (ak == -1)
		{
			free(naah);
			naah = NULL;
			break ;
		}
		buff[ak] = '\0';
		naah = ft_strjoin(naah, buff);
	}
	free(buff);
	return (naah);
}

char	*get_next_line(int fd)
{
	char		*ster;
	static char	*naah;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	naah = kra(fd, naah);
	if (!naah)
		return (NULL);
	ster = thisone(naah);
	naah = notthisone(naah);
	return (ster);
}
