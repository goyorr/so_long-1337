/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkstuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:21:45 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/26 16:30:04 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

//checks if thers only right assets.
int	checkassets(t_data *data)
{
	data->ve = 0;
	data->ho = 0;
	while (data->ve < data->map_height)
	{
		while (data->ho < data->map_width)
		{
			if (data->map[data->ve][data->ho] == 'E'
			|| data->map[data->ve][data->ho] == 'P'
			|| data->map[data->ve][data->ho] == 'C'
			|| data->map[data->ve][data->ho] == '1'
			|| data->map[data->ve][data->ho] == '0')
				data->ho++;
			else
				return (1);
		}
		data->ho = 0;
		data->ve++;
	}
	return (0);
}

//check right number of coins - player - exits.
int	rightnumassets(t_data *data)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	data->ve = -1;
	while (++data->ve < data->map_height)
	{
		while (data->ho < data->map_width)
		{
			if (data->map[data->ve][data->ho] == 'E')
				e++;
			else if (data->map[data->ve][data->ho] == 'P')
				p++;
			else if (data->map[data->ve][data->ho] == 'C')
				c++;
			data->ho++;
		}
		data->ho = 0;
	}
	if (e != 1 || p != 1 || c < 1)
		return (1);
	return (0);
}

//checks if map is surounded by walls.
int	topdown(t_data *data)
{
	data->ve = 0;
	while (data->ho < data->map_width)
	{
		if (data->map[data->ve][data->ho] != '1')
			return (1);
		data->ho++;
	}
	data->ho = 0;
	data->ve = data->map_height - 1;
	while (data->ho < data->map_width)
	{
		if (data->map[data->ve][data->ho] != '1')
			return (1);
		data->ho++;
	}
	return (0);
}

int	sides(t_data *data)
{
	data->ho = 0;
	data->ve = 0;
	while (data->ve < data->map_height)
	{
		if (data->map[data->ve][data->ho] != '1')
			return (1);
		data->ve++;
	}
	data->ho = data->map_width - 1;
	data->ve = 0;
	while (data->ve < data->map_height)
	{
		if (data->map[data->ve][data->ho] != '1')
			return (1);
		data->ve++;
	}
	return (0);
}

void	img(t_data *data)
{
	int	a;

	a = 1;
	data->img.fr = mlx_xpm_file_to_image(data->mlx,
			"./textures/frees64.xpm", &a, &a);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/wall64.xpm", &a, &a);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			"./textures/player64.xpm", &a, &a);
	data->img.door = mlx_xpm_file_to_image(data->mlx,
			"./textures/door64.xpm", &a, &a);
	data->img.coin = mlx_xpm_file_to_image(data->mlx,
			"./textures/coin64.xpm", &a, &a);
	if (!data->img.fr || !data->img.wall || !data->img.player
		|| !data->img.door || !data->img.coin)
		exit(write(1, "Wrong img file/doesn't exist!", 29));
}
