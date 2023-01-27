/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:11:23 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/26 15:52:10 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

void	put_image(t_mlx *mlx, char c, int y, int x)
{
	int		nil;
	char	str[20];
	void	*img;

	ft_strcpy(str, "./textures/X.xpm");
	str[11] = c;
	img = mlx_xpm_file_to_image(mlx->mlx, str, &nil, &nil);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, DIM * x, DIM * y);
}

void	move_player(t_mlx *mlx, int y, int x)
{
	static int	i;

	if (mlx->data.map[y][x] == 'C' || mlx->data.map[y][x] == '0')
	{
		if (mlx->data.map[y][x] == 'C')
			mlx->data.collectible--;
		put_image(mlx, '0', y, x);
		put_image(mlx, '0', mlx->pos.y, mlx->pos.x);
		put_image(mlx, 'P', y, x);
		mlx->data.map[y][x] = 'P';
		mlx->data.map[mlx->pos.y][mlx->pos.x] = '0';
		ft_printf("You have a %d move\n", i++);
		mlx->pos.y = y;
		mlx->pos.x = x;
	}
	if (mlx->data.map[y][x] == 'E' && mlx->data.collectible == 0)
	{
		ft_putstr("We have a WINER!");
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(1);
	}
}

int	key(int keyhook, t_mlx *mlx)
{
	if (keyhook == 13 || keyhook == 126)
		move_player(mlx, mlx->pos.y - 1, mlx->pos.x);
	if (keyhook == 1 || keyhook == 125)
		move_player(mlx, mlx->pos.y + 1, mlx->pos.x);
	if (keyhook == 0 || keyhook == 123)
		move_player(mlx, mlx->pos.y, mlx->pos.x - 1);
	if (keyhook == 2 || keyhook == 124)
		move_player(mlx, mlx->pos.y, mlx->pos.x + 1);
	if (keyhook == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(1);
	}
	return (0);
}
