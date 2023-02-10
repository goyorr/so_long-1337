/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:11:10 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/27 18:11:12 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	moveup(t_data *data, int move)
{
	if (data->map[(data->playery / 64) - 1][data->playerx / 64] != '1'
	&& data->map[(data->playery / 64) - 1][data->playerx / 64] != 'E')
	{
		if (data->map[(data->playery / 64) - 1][data->playerx / 64] == 'C')
		{
			data->map[(data->playery / 64) - 1][data->playerx / 64] = '0';
			data->coin++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.fr,
			data->playerx, data->playery);
		data->playery -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			data->playerx, data->playery);
		ft_putstr_fd("MOVES:", 1);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
	else if (data->map[(data->playery / 64) - 1][data->playerx / 64] == 'E'
		&& data->coin == data->bagcoins)
		exit(write(1, "you won!", 8));
	else
		move--;
	return (move);
}

int	movedown(t_data *data, int move)
{
	if (data->map[(data->playery / 64) + 1][data->playerx / 64] != '1'
	&& data->map[(data->playery / 64) + 1][data->playerx / 64] != 'E')
	{
		if (data->map[(data->playery / 64) + 1][data->playerx / 64] == 'C')
		{
			data->map[(data->playery / 64) + 1][data->playerx / 64] = '0';
			data->coin++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.fr,
			data->playerx, data->playery);
		data->playery += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			data->playerx, data->playery);
		ft_putstr_fd("MOVES:", 1);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
	else if (data->map[(data->playery / 64) + 1][data->playerx / 64] == 'E'
	&& data->bagcoins == data->coin)
		exit(write(1, "you won!", 8));
	else
		move--;
	return (move);
}

int	moveleft(t_data *data, int move)
{
	if (data->map[data->playery / 64][(data->playerx / 64) - 1] != '1'
	&& data->map[data->playery / 64][(data->playerx / 64) - 1] != 'E')
	{
		if (data->map[data->playery / 64][(data->playerx / 64) - 1] == 'C')
		{
			data->map[data->playery / 64][(data->playerx / 64) - 1] = '0';
			data->coin++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.fr,
			data->playerx, data->playery);
		data->playerx -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			data->playerx, data->playery);
		ft_putstr_fd("MOVES:", 1);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
	else if (data->map[data->playery / 64][(data->playerx / 64) - 1] == 'E'
	&& data->bagcoins == data->coin)
		exit(write(1, "you won!", 8));
	else
		move--;
	return (move);
}

int	moveright(t_data *data, int move)
{
	if (data->map[data->playery / 64][(data->playerx / 64) + 1] != '1'
	&& data->map[data->playery / 64][(data->playerx / 64) + 1] != 'E')
	{
		if (data->map[data->playery / 64][(data->playerx / 64) + 1] == 'C')
		{
			data->map[data->playery / 64][(data->playerx / 64) + 1] = '0';
			data->coin++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.fr,
			data->playerx, data->playery);
		data->playerx += 64;
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			data->playerx, data->playery);
		ft_putstr_fd("MOVES:", 1);
		ft_putnbr_fd(move, 1);
		write(1, "\n", 1);
	}
	else if (data->map[data->playery / 64][(data->playerx / 64) + 1] == 'E'
	&& data->bagcoins == data->coin)
		exit(write(1, "you won!", 8));
	else
		move--;
	return (move);
}

void	drawmap2(t_data *data)
{
	int	x;
	int	y;

	img(data);
	drawmap1(data);
	data->vermap = -1;
	y = 0;
	while (++data->vermap < data->map_height)
	{
		data->hormap = -1;
		x = -64;
		while (++data->hormap < data->map_width)
		{
			x += 64;
			if (data->map[data->vermap][data->hormap] == 'P')
			{
				data->playery = y;
				data->playerx = x;
			}
			else if (data->map[data->vermap][data->hormap] == 'C')
				data->bagcoins++;
		}
		y += 64;
	}
}
