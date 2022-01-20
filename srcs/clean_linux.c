/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:43:32 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/20 14:49:22 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_exit(t_fdf *fdf, char *msg)
{
	if (fdf->mlx_ptr && fdf->img_ptr)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->mlx_ptr && fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->mlx_ptr)
		mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->__tab);
	free(fdf->tab);
	free(fdf->mlx_ptr);
	ft_exit(msg);
}
