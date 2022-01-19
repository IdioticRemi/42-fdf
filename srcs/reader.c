/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:26 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/19 21:09:16 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_file_exists(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDWR);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
