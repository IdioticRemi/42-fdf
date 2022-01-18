/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:12:55 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 19:41:07 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_gradient(int from, int to, double p)
{
	double	f[3];
	double	t[3];
	int		ret[3];

	if (p == 1)
		return (from);
	f[0] = from >> 16;
	f[1] = (from >> 8) - ((int)f[0] << 8);
	f[2] = from - ((int)f[0] << 16) - ((int)f[1] << 8);
	t[0] = to >> 16;
	t[1] = (to >> 8) - ((int)t[0] << 8);
	t[2] = to - ((int)t[0] << 16) - ((int)t[1] << 8);
	ret[0] = f[0] * p + (1 - p) * t[0];
	ret[1] = f[1] * p + (1 - p) * t[1];
	ret[2] = f[2] * p + (1 - p) * t[2];
	return (255 << 24 | ret[0] << 16 | ret[1] << 8 | ret[2]);
}

int	ft_get_color(t_fdf *fdf, double z)
{
	return (ft_gradient(COLOR_BOT, COLOR_TOP,
			1 - (z + ABS(fdf->min)) / (fdf->max + ABS(fdf->min))));
}

double	*ft_point(double point[2], double x, double y)
{
	point[0] = x;
	point[1] = y;
	return (point);
}

void	bresenham(t_fdf *fdf, double x, double y, double dest[2])
{
	double	step[2];
	int		z[4];

	z[0] = fdf->tab[(int)x][(int)y];
	z[1] = fdf->tab[(int)dest[0]][(int)dest[1]];
	ft_scale(fdf, &x, &y, dest);
	ft_isometric(fdf, &x, &y, z[0]);
	ft_isometric(fdf, &dest[0], &dest[1], z[1]);
	ft_transform(fdf, &x, &y, dest);
	z[2] = x;
	if (dest[0] > SC_W || dest[1] > SC_H || x < 0 || y < 0)
		return ;
	step[0] = dest[0] - x;
	step[1] = dest[1] - y;
	z[3] = MAX(ABS(step[0]), ABS(step[1]));
	step[0] /= z[3];
	step[1] /= z[3];
	while ((int)(x - dest[0]) || (int)(y - dest[1]))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y,
			ft_get_color(fdf, z[0] + ((x - z[2]) / (
						dest[0] - z[2])) * (z[1] - z[0])));
		x += step[0];
		y += step[1];
	}
}

void	draw(t_fdf *fdf)
{
	double	d[2];
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			if (x < fdf->width - 1)
				bresenham(fdf, x, y, ft_point(d, x + 1, y));
			if (y < fdf->height - 1)
				bresenham(fdf, x, y, ft_point(d, x, y + 1));
		}
	}
}