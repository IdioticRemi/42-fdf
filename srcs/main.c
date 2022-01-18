/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:06:23 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 12:05:26 by tjolivea         ###   ########.fr       */
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
	free(fdf->__tab);
	free(fdf->tab);
	if (msg)
		ft_exit(msg);
	exit(0);
}

// void	ft_puttab(t_fdf *fdf)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 		{
// 			ft_putchar_fd('\t', 1);
// 			ft_putnbr_fd(fdf->tab[x][y], 1);
// 		}
// 		ft_putchar_fd('\n', 1);
// 	}
// }

void	ft_init(t_fdf *fdf, char *path)
{
	int	x;

	fdf->tab = 0;
	fdf->__tab = malloc(WIDTH * HEIGHT * sizeof(int));
	if (!fdf->__tab)
		ft_clean_exit(fdf, "ERROR: Malloc failed.");
	ft_bzero((void *) fdf->__tab, WIDTH * HEIGHT * sizeof(int));
	fdf->tab = malloc(WIDTH * sizeof(int *));
	if (!fdf->tab)
		ft_clean_exit(fdf, "ERROR: Malloc failed.");
	x = -1;
	while (++x < WIDTH)
		fdf->tab[x] = &fdf->__tab[x * HEIGHT];
	(void) path;
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		ft_exit("ERROR: Usage: ./fdf <map>");
	if (!ft_file_exists(argv[1]))
		ft_exit("ERROR: Cannot open file, check name and permissions.");
	ft_init(&fdf, argv[1]);
	ft_clean_exit(&fdf, NULL);
}
