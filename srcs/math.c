/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:21:16 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 18:43:29 by tjolivea         ###   ########.fr       */
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
