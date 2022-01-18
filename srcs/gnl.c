/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:00:09 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 12:02:38 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*ft_get_line(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover[i])
		return (0);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
		line[i] = leftover[i];
	line[i + (leftover[i] == '\n')] = '\0';
	return (line);
}

static char	*ft_new_leftover(char *leftover)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (0);
	}
	new = malloc((ft_gstrlen(leftover) - i + 1) * sizeof(char));
	if (!new)
		return (0);
	i++;
	j = 0;
	while (leftover[i])
		new[j++] = leftover[i++];
	new[j] = '\0';
	free(leftover);
	return (new);
}

static char	*ft_read_leftover(int fd, char *leftovers)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	buf[0] = '\0';
	while (!ft_gstrchr(buf, '\n') && r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (0);
		buf[r] = '\0';
		leftovers = ft_gstrjoin(leftovers, buf);
	}
	return (leftovers);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftovers[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers[fd] = ft_read_leftover(fd, leftovers[fd]);
	if (!leftovers[fd])
		return (0);
	line = ft_get_line(leftovers[fd]);
	leftovers[fd] = ft_new_leftover(leftovers[fd]);
	return (line);
}
