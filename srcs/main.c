/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:06:23 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/19 20:57:45 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd("ERROR: Unknown error.", 2);
	exit(1);
}

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
	if (msg)
		ft_exit(msg);
	exit(0);
}

int	mlx_exit(t_fdf *fdf)
{
	ft_clean_exit(fdf, NULL);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		ft_exit("ERROR: Usage: ./fdf <map>");
	if (!ft_file_exists(argv[1]))
		ft_exit("ERROR: Cannot open file, check name and permissions.");
	if (!ft_init(&fdf, argv[1]))
		ft_clean_exit(&fdf, "ERROR: Failed to initialize fdf.");
	if (!ft_init_mlx(&fdf))
		ft_clean_exit(&fdf, "ERROR: Failed to initialize graphics.");
	if (!ft_init_max_min(&fdf))
		ft_clean_exit(&fdf, "ERROR: Failed to calculate min and max.");
	draw(&fdf);
	mlx_key_hook(fdf.win_ptr, ft_key_handler, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, mlx_exit, &fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_clean_exit(&fdf, NULL);
}
