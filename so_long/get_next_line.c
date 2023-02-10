/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:25:20 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/23 16:20:04 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	*read_stash(int fd, char *stash)
{
	char	*buffer;
	int		i;

	i = 1;
	while (i && !newline(stash))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(stash), NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), free(stash), stash = NULL, NULL);
		buffer[i] = '\0';
		if (i == 0)
		{
			free(buffer);
			break ;
		}
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlen(stash))
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*rest(char *stash)
{
	char	*rest;
	int		i;

	i = 0;
	if (!stash[i])
		return (free(stash), NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	rest = ft_strdup(&stash[i]);
	return (free(stash), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash[fd] = read_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line && stash[fd])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = rest(stash[fd]);
	return (line);
}

int	cl(void)
{
	exit (write(1, "you quit!\n", 9));
}
