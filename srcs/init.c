/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:30:05 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/19 20:24:17 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init(t_fdf *fdf, char *path)
{
	int	x;

	fdf->width = ft_get_width(path);
	fdf->height = ft_get_height(path);
	if (fdf->width <= 0 || fdf->height <= 0)
		return (0);
	fdf->__tab = malloc(fdf->width * fdf->height * sizeof(int));
	if (!fdf->__tab)
		return (0);
	ft_bzero((void *) fdf->__tab, fdf->width * fdf->height * sizeof(int));
	fdf->tab = malloc(fdf->width * sizeof(int *));
	if (!fdf->tab)
		return (0);
	x = -1;
	while (++x < fdf->width)
		fdf->tab[x] = &fdf->__tab[x * fdf->height];
	if (!ft_parse_map(fdf, path))
		return (0);
	return (1);
}

int	ft_init_mlx(t_fdf *fdf)
{
	fdf->scale = 20;
	fdf->scale_z = 1;
	fdf->x_shift = SC_W / 8;
	fdf->y_shift = SC_H / 8;
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (0);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, SC_W, SC_H, "FDF de Remi :D");
	if (!fdf->win_ptr)
		return (0);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, SC_W, SC_H);
	if (!fdf->img_ptr)
		return (0);
	fdf->img.addr = mlx_get_data_addr(fdf->img_ptr, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	if (!fdf->img.addr)
		return (0);
	return (1);
}

int	ft_init_max_min(t_fdf *fdf)
{
	int	x;

	fdf->max = INT_MIN;
	fdf->min = INT_MAX;
	x = -1;
	while (++x < fdf->width * fdf->height)
	{
		if (fdf->__tab[x] > fdf->max)
			fdf->max = fdf->__tab[x];
		if (fdf->__tab[x] < fdf->min)
			fdf->min = fdf->__tab[x];
	}
	return (1);
}
