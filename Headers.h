/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:08:15 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/26 14:55:37 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

# define DIM 60

typedef struct pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct data
{
	int		player;
	int		exit;
	int		collectible;
	int		row;
	int		clomun;
	char	**map;
	char	**cmap;
}			t_data;

typedef struct mlx
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_pos	pos;
	int		count;
}			t_mlx;

void		read_map(t_data *data, int fd);
int			key(int keyhook, t_mlx *mlx);
void		flood_fill(char **map, int x, int y);
void		find_p(t_data *data, t_pos *pos);
void		check_path(t_data *data, t_pos *pos);
char		**ft_split(char *s, char c);
void		aff_map(t_data *data, t_mlx mlx);
void		*get_img(char c, t_mlx mlx);
int			check_map(t_data *data);
char		*ft_strcpy(char *s1, char *s2);

#endif