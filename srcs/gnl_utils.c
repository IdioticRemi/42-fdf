/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:59:50 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 12:02:58 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_gstrlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gstrchr(char *s, int c)
{
	ssize_t	i;

	i = -1;
	if (!s)
		return (0);
	if (!c)
		return (s + ft_gstrlen(s));
	while (s[++i])
		if (s[i] == (char) c)
			return (s + i);
	return (0);
}

char	*ft_gstrjoin(char *leftover, char *buf)
{
	ssize_t	i;
	ssize_t	j;
	char	*new;

	if (!leftover)
	{
		leftover = malloc(1 * sizeof(char));
		if (!leftover)
			return (0);
		leftover[0] = '\0';
	}
	if (!buf)
		return (0);
	new = malloc(((ft_gstrlen(leftover) + ft_gstrlen(buf)) + 1) * sizeof(char));
	if (!new)
		return (0);
	i = -1;
	j = 0;
	while (leftover[++i])
		new[i] = leftover[i];
	while (buf[j])
		new[i++] = buf[j++];
	new[i] = '\0';
	free(leftover);
	return (new);
}
