/* ************************************************************************** */
/*                                                                            */
/*  	                                                  :::      ::::::::   */
/*   playable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:54:18 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/28 21:54:19 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] || str2[i]) && n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}

void	lines(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_height == data->map_width)
		exit(write(1, "ERROR:\nMap not rectangular!", 27));
	while (i < data->map_height - 1)
	{	
		if (ft_strlen(data->map[0]) == ft_strlen(data->map[i]))
			i++;
		else
			exit(write(1, "ERROR:\nDifferent map lines!", 28));
	}
	if (ft_strlen(data->map[0]) != ((ft_strlen(data->map[i])) + 1))
		exit(write(1, "ERROR:\nDifferent map lines!", 28));
}

int	playable1(int y, int x, t_data *data)
{
	static int	coins;

	if (data->map[y][x] == 'C')
		coins++;
	data->map2[y][x] = '1';
	if (data->map2[y][x - 1] != '1' && data->map2[y][x - 1] != 'E')
		playable1(y, x - 1, data);
	if (data->map2[y + 1][x] != '1' && data->map2[y + 1][x] != 'E')
		playable1(y + 1, x, data);
	if (data->map2[y][x + 1] != '1' && data->map2[y][x + 1] != 'E')
		playable1(y, x + 1, data);
	if (data->map2[y - 1][x] != '1' && data->map2[y - 1][x] != 'E')
		playable1(y - 1, x, data);
	if (coins == data->bagcoinss)
		return (0);
	return (1);
}

int	playable2(int y, int x, t_data *data)
{
	static int	exit;

	if (data->map3[y][x] == 'E')
		exit++;
	data->map3[y][x] = '1';
	if (data->map3[y][x - 1] != '1')
		playable2(y, x - 1, data);
	if (data->map3[y + 1][x] != '1')
		playable2(y + 1, x, data);
	if (data->map3[y][x + 1] != '1')
		playable2(y, x + 1, data);
	if (data->map3[y - 1][x] != '1')
		playable2(y - 1, x, data);
	if (exit == 1)
		return (0);
	return (1);
}
