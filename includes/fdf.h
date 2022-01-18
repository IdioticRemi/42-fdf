/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:03:23 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/18 12:04:15 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "fcntl.h"
# include "mlx.h"
# include "math.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# define WIDTH 15
# define HEIGHT 7

typedef struct s_fdf {
	int	*__tab;
	int	**tab;
}	t_fdf;

// GNL
char	*get_next_line(int fd);

char	*ft_gstrchr(char *s, int c);
char	*ft_gstrjoin(char *leftover, char *buff);
size_t	ft_gstrlen(char *s);

// Reader
int		ft_file_exists(char *path);

// Parser

#endif