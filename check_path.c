/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:08:06 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/26 13:20:49 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

void	find_p(t_data *data, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				pos->x = i;
				pos->y = j;
			}
			i++;
		}
		j++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	check_path(t_data *data, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_p(data, pos);
	flood_fill(data->cmap, pos->x, pos->y);
	while (data->cmap[j])
	{
		i = 0;
		while (data->cmap[j][i])
		{
			if (data->cmap[j][i] != '1' && data->cmap[j][i] != 'F')
			{
				ft_putstr("CHECK POSITION!!");
				exit(1);
			}
			i++;
		}
		j++;
	}
}
