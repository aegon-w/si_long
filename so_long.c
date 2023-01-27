/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:08:01 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/26 13:47:36 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

int	count_car(char c, int *arr, t_data *data)
{
	if (c == 'E')
		arr[0]++;
	else if (c == 'P')
		arr[1]++;
	else if (c == 'C')
		arr[2]++;
	else if (c != '1' && c != '0')
		arr[3]++;
	data->collectible = arr[2];
	return (0);
}

int	check_walls(t_data *data, int x, int y)
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
			if (data->map[0][i] != '1')
				return (1);
			if (data->map[y - 1][i] != '1')
				return (1);
			if (data->map[j][0] != '1')
				return (1);
			if (data->map[j][x - 1] != '1')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

void	check_cara(int *arr)
{
	if (arr[0] != 1 || arr[1] != 1 || arr[2] < 1 || arr[3] != 0)
	{
		ft_putstr("CHECK CARACTERS!\n");
		exit(EXIT_FAILURE);
	}
}

void	check_lines(t_data *data, int j)
{
	if (data->clomun != (int)ft_strlen(data->map[j]))
	{
		ft_putstr("CHECK LINES!\n");
		exit(EXIT_FAILURE);
	}
}

int	check_map(t_data *data)
{
	int	i;
	int	j;
	int	arr[4];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	j = 0;
	data->clomun = ft_strlen(data->map[0]);
	while (data->map[j])
	{
		i = 0;
		check_lines(data, j);
		while (data->map[j][i])
			count_car(data->map[j][i++], arr, data);
		j++;
	}
	data->row = j;
	if (check_walls(data, data->clomun, data->row) == 1)
	{
		ft_putstr("WALLS ERROR!\n");
		exit(EXIT_FAILURE);
	}
	return (check_cara(arr), 0);
}
