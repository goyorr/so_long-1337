/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:25:36 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/23 16:20:10 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*newstash;
	int		i;
	int		j;

	if (!stash && buffer)
		return (buffer);
	if (stash && !buffer)
		return (stash);
	if (stash && buffer)
	{
		newstash = (char *)malloc(((ft_strlen(stash) + ft_strlen(buffer)) + 1));
		if (!newstash)
			return (free(stash), free(buffer), NULL);
		i = -1;
		j = -1;
		while (stash[++i])
			newstash[i] = stash[i];
		while (buffer[++j])
			newstash[i + j] = buffer[j];
		newstash[i + j] = '\0';
		return (free(stash), free(buffer), newstash);
	}
	return (free(stash), free(buffer), NULL);
}

int	newline(const char *stash)
{
	int		i;

	i = -1;
	if (!stash)
		return (0);
	while (stash && stash[++i])
		if (stash[i] == '\n')
			return (1);
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1);
	s2 = malloc(i + 1);
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}

void	drawmap3(t_data *data)
{
	int	x;
	int	y;

	data->vermap = -1;
	y = 0;
	while (++data->vermap < data->map_height)
	{
		data->hormap = -1;
		x = -64;
		while (++data->hormap < data->map_width)
		{
			x += 64;
			mlx_put_image_to_window(data->mlx, data->win, data->img.fr, x, y);
			if (data->map[data->vermap][data->hormap] == 'E')
				mlx_put_image_to_window(data->mlx,
					data->win, data->img.door, x, y);
			else if (data->map[data->vermap][data->hormap] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.coin, x, y);
			else if (data->map[data->vermap][data->hormap] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.player, x, y);
		}
		y += 64;
	}
}

void	drawmap1(t_data *data)
{
	int	x;

	drawmap3(data);
	data->vermap = -1;
	data->ve = 0;
	while (++data->vermap < data->map_height)
	{
		data->hormap = -1;
		x = -64;
		while (++data->hormap < data->map_width)
		{
			x += 64;
			if (data->map[data->vermap][data->hormap] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.wall, x, data->ve);
			else if (data->map[data->vermap][data->hormap] == 'N')
			{
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.fr, x, data->ve);
				mlx_put_image_to_window(data->mlx, data->win,
					data->img.en, x, data->ve);
			}
		}
		data->ve += 64;
	}
}
