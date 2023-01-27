/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:08:18 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/26 16:36:36 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

int	key1(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(1);
	return (0);
}

int	mlx_check(t_mlx *mlx, t_data *data)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (-1);
	mlx->win = mlx_new_window(mlx->mlx, data->clomun * DIM, data->row * DIM,
			"./so_long");
	if (mlx->win == NULL)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	t_mlx		mlx;
	t_data		data;
	t_pos		pos;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (perror("Error"), -1);
		read_map(&data, fd);
		if (check_map(&data))
			ft_putstr("Error\n");
		check_path(&data, &pos);
		if (mlx_check(&mlx, &data) == -1)
			return (-1);
		aff_map(&data, mlx);
		mlx.data = data;
		mlx.pos = pos;
		mlx_hook(mlx.win, 2, 0, key, &mlx);
		mlx_hook(mlx.win, 17, 0, key1, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (ft_putstr("CHECK ARG!"), 0);
}
