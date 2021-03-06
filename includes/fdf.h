/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:03:23 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/20 14:49:57 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "fcntl.h"
# include "mlx.h"
# include "math.h"
# include "keys_linux.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define SC_W 1920
# define SC_H 1080
# define ANGLE 0.8
# define SCALE_THRESHOLD 1.2

# define COLOR_TOP 0xFFFFFF
# define COLOR_BOT 0x000000

typedef struct s_img {
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf {
	int		*__tab;
	int		**tab;

	int		width;
	int		height;

	double	scale_z;
	double	scale;
	double	x_shift;
	double	y_shift;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	t_img	img;

	int		max;
	int		min;
}	t_fdf;

// Clean
void	ft_clean_exit(t_fdf *fdf, char *msg);

// Main
void	ft_exit(char *msg);

// Init
int		ft_init(t_fdf *fdf, char *path);
int		ft_init_mlx(t_fdf *fdf);
int		ft_init_max_min(t_fdf *fdf);

// GNL
char	*get_next_line(int fd);

char	*ft_gstrchr(char *s, int c);
char	*ft_gstrjoin(char *leftover, char *buff);
size_t	ft_gstrlen(char *s);

// Reader
int		ft_file_exists(char *path);

// Parser
int		ft_get_width(char *path);
int		ft_get_height(char *path);
int		ft_parse_map(t_fdf *fdf, char *path);
int		ft_key_handler(int key, t_fdf *fdf);

// Math
void	ft_transform(t_fdf *fdf, double *x, double *y, double dest[2]);
void	ft_scale(t_fdf *fdf, double *x, double *y, double dest[2]);
void	ft_isometric(t_fdf *fdf, double *x, double *y, int z);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		max(int a, int b);

// Graphics
void	draw(t_fdf *fdf);

#endif