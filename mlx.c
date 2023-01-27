/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:11:09 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/24 21:11:11 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"
#include <mlx.h>

void	aff_map(t_data *data, t_mlx mlx)
{
	int		i;
	int		j;
	void	*img;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			img = get_img(data->map[j][i], mlx);
			if (!img)
				exit(1);
			mlx_put_image_to_window(mlx.mlx, mlx.win, img, i * DIM, j * DIM);
			i++;
		}
		j++;
	}
}

void	*get_img(char c, t_mlx mlx)
{
	int	nil;

	if (c == '0')
		return (mlx_xpm_file_to_image(mlx.mlx, "./textures/0.xpm", &nil, &nil));
	else if (c == '1')
		return (mlx_xpm_file_to_image(mlx.mlx, "./textures/1.xpm", &nil, &nil));
	else if (c == 'P')
		return (mlx_xpm_file_to_image(mlx.mlx, "./textures/P.xpm", &nil, &nil));
	else if (c == 'E')
		return (mlx_xpm_file_to_image(mlx.mlx, "./textures/E.xpm", &nil, &nil));
	else if (c == 'C')
		return (mlx_xpm_file_to_image(mlx.mlx, "./textures/C.xpm", &nil, &nil));
	return (0);
}
