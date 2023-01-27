/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:08:22 by m-boukel          #+#    #+#             */
/*   Updated: 2023/01/25 14:22:44 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers.h"

void	read_map(t_data *data, int fd)
{
	char	*str_map;
	char	*buffer;

	str_map = NULL;
	buffer = NULL;
	buffer = get_next_line(fd);
	if (!buffer)
	{
		ft_putstr("EMPTY FILE!\n");
		exit(1);
	}
	while (buffer)
	{
		if (ft_strlen(buffer) == 1)
		{
			ft_putstr("EMPTY LINE!\n");
			exit(EXIT_FAILURE);
		}
		str_map = ft_strjoin(str_map, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	data->map = ft_split(str_map, '\n');
	data->cmap = ft_split(str_map, '\n');
	free(str_map);
}
