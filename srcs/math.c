/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:21:16 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/19 21:02:57 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform(t_fdf *fdf, double *x, double *y, double dest[2])
{
	*x += fdf->x_shift;
	*y += fdf->y_shift;
	dest[0] += fdf->x_shift;
	dest[1] += fdf->y_shift;
}

void	ft_isometric(t_fdf *fdf, double *x, double *y, int z)
{
	*x = (*x - *y) * cos(ANGLE);
	*y = ((*x + *y) * sin(ANGLE)) - z * fdf->scale_z;
}

void	ft_scale(t_fdf *fdf, double *x, double *y, double dest[2])
{
	*x *= fdf->scale;
	*y *= fdf->scale;
	dest[0] *= fdf->scale;
	dest[1] *= fdf->scale;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
