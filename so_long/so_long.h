/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:19:55 by zel-kach          #+#    #+#             */
/*   Updated: 2023/02/08 13:19:57 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_images
{
	void	*player;
	void	*coin;
	void	*fr;
	void	*wall;
	void	*door;
}	t_images;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*map[10000];
	char		*map2[10000];
	char		*map3[10000];
	int			map_height;
	int			map_width;
	int			coin;
	int			bagcoins;
	int			bagcoinss;
	int			playerx;
	int			playerxx;
	int			playery;
	int			playeryy;
	int			ve;
	int			ho;
	int			vermap;
	int			hormap;
	t_images	img;
}	t_data;

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*get_next_line(int fd);
char		*ft_strjoin(char *stash, char *buffer);
int			newline(const char *stash);
int			ft_strlen(const char *s);
char		*ft_strdup(char *s1);
int			rightnumassets(t_data *data);
int			topdown(t_data *data);
int			checkassets(t_data *data);
int			sides(t_data *data);
int			moveup(t_data *data, int move);
int			movedown(t_data *data, int move);
int			moveright(t_data *data, int move);
int			moveleft(t_data *data, int move);
int			key(int keyy, t_data *data);
void		drawmap1(t_data *data);
void		drawmap2(t_data *data);
void		img(t_data *data);
void		lines(t_data *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			cl(void);
int			playable1(int y, int x, t_data *data);
int			playable2(int y, int x, t_data *data);

#endif
