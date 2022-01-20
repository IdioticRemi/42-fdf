/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_mac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:11 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/20 14:49:27 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean_exit(t_fdf *fdf, char *msg)
{
	free(fdf->__tab);
	free(fdf->tab);
	if (fdf->mlx_ptr && fdf->img_ptr)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->mlx_ptr && fdf->win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_exit(msg);
}
