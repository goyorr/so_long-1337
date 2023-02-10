/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:19:47 by zel-kach          #+#    #+#             */
/*   Updated: 2023/02/08 13:19:52 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key(int keyy, t_data *data)
{
	static int	move = 0;

	move++;
	if (keyy == 13)
		move = moveup(data, move);
	else if (keyy == 1)
		move = movedown(data, move);
	else if (keyy == 0)
		move = moveleft(data, move);
	else if (keyy == 2)
		move = moveright(data, move);
	else if (keyy == 53)
		exit (write(1, "you quit!", 9));
	else
		move--;
	return (0);
}

void	player_pos(t_data *data)
{
	int	x;
	int	y;
	int	vermap;
	int	hormap;

	vermap = -1;
	y = 0;
	while (++vermap < data->map_height)
	{
		hormap = -1;
		x = -1;
		while (++hormap < data->map_width)
		{
			x++;
			if (data->map[vermap][hormap] == 'P')
			{
				data->playeryy = y;
				data->playerxx = x;
			}
			else if (data->map[vermap][hormap] == 'C')
				data->bagcoinss++;
		}
		y++;
	}
}

void	read_map(t_data *data, char **argv)
{
	int		filed;
	char	*gnl;

	filed = open(argv[1], O_RDONLY);
	if (filed == -1)
		exit(write(1, "ERROR:\nmap doesn't exist!\n", 26));
	gnl = get_next_line(filed);
	data->map_width = ft_strlen(gnl) - 1;
	while (gnl)
	{
		data->map[data->map_height] = ft_strdup(gnl);
		data->map2[data->map_height] = ft_strdup(gnl);
		data->map3[data->map_height] = ft_strdup(gnl);
		data->map_height++;
		free(gnl);
		gnl = get_next_line(filed);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		exit(write(1, "Error: Wrong arg num\n", 25));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		exit(write(1, "Error Check Extention !\n", 25));
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx = mlx_init();
	read_map(data, argv);
	if (checkassets(data) || rightnumassets(data)
		|| topdown(data) || sides(data))
		exit(write(1, "ERROR:\ninvalid map!\n", 21));
	lines(data);
	data->win = mlx_new_window(data->mlx, data->map_width * 64,
			data->map_height * 64, "so_long");
	player_pos(data);
	if (playable2(data->playeryy, data->playerxx, data)
		|| playable1(data->playeryy, data->playerxx, data))
		exit(write(1, "ERROR:\nmap unbeatable!", 22));
	drawmap2(data);
	mlx_hook(data->win, 2, 0, key, data);
	mlx_hook(data->win, 17, 0, cl, (void *)0);
	mlx_loop(data->mlx);
}
