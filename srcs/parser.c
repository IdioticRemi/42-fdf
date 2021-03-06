/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:37 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/20 14:33:22 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

int	ft_get_width(char *path)
{
	char	**split;
	char	*gnl;
	int		fd;
	int		y;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	gnl = get_next_line(fd);
	split = ft_split(gnl, ' ');
	y = 0;
	while (split[y] && split[y][0] != '\n')
		free(split[y++]);
	free(split);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (y);
}

int	ft_get_height(char *path)
{
	char	*gnl;
	int		fd;
	int		x;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	x = 0;
	gnl = get_next_line(fd);
	while (gnl)
	{
		free(gnl);
		gnl = get_next_line(fd);
		x++;
	}
	close(fd);
	return (x);
}

int	ft_parse_map(t_fdf *fdf, char *path)
{
	char	**split;
	char	*gnl;
	int		x;
	int		y;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	y = -1;
	while (++y <= fdf->height)
	{
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		split = ft_split(gnl, ' ');
		if (!split)
			return (0);
		x = -1;
		while (++x < fdf->width)
			fdf->tab[x][y] = ft_atoi(split[x]);
		ft_free_array(split);
		free(gnl);
	}
	return (1);
}

int	ft_key_handler(int key, t_fdf *fdf)
{
	if (key == KEY_Q)
		fdf->scale /= SCALE_THRESHOLD;
	else if (key == KEY_E)
		fdf->scale *= SCALE_THRESHOLD;
	else if (key == KEY_D)
		fdf->x_shift += (SC_W / 10);
	else if (key == KEY_W)
		fdf->y_shift += (SC_H / 10);
	else if (key == KEY_S)
		fdf->y_shift -= (SC_H / 10);
	else if (key == KEY_A)
		fdf->x_shift -= (SC_W / 10);
	else if (key == KEY_UP)
		fdf->scale_z += 1;
	else if (key == KEY_DOWN)
		fdf->scale_z -= 1;
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		fdf->scale_z = -fdf->scale_z;
	else if (key == KEY_ESC)
		ft_clean_exit(fdf, NULL);
	else
		return (0);
	draw(fdf);
	return (0);
}
