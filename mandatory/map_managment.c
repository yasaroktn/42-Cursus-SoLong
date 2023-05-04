/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_managment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 03:27:04 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 11:18:53 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_images(t_win *win)
{
	win->image->wall = mlx_xpm_file_to_image(win->mlx, "../textures/wall.xpm",
			&win->image->img_wid, &win->image->img_hei);
	win->image->bg = mlx_xpm_file_to_image(win->mlx, "../textures/bg.xpm",
			&win->image->img_wid, &win->image->img_hei);
	win->image->player
		= mlx_xpm_file_to_image(win->mlx, "../textures/player.xpm",
			&win->image->img_wid, &win->image->img_hei);
	win->image->coin = mlx_xpm_file_to_image(win->mlx, "../textures/coin.xpm",
			&win->image->img_wid, &win->image->img_hei);
	win->image->exit = mlx_xpm_file_to_image(win->mlx, "../textures/exit.xpm",
			&win->image->img_wid, &win->image->img_hei);
}

void	not_fd(char *map, t_win *win)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		show_error(1);
	map_wid_hei(fd, win);
}

void	map_wid_hei(int fd, t_win *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	win->map->map[0] = get_next_line(fd);
	if (win->map->map[0] == NULL)
		show_error(11);
	while (win->map->map[0][j] && win->map->map[0][j] != '\n')
		j++;
	win->map->wid = j;
	j = 0;
	while (win->map->map[i] != NULL)
	{
		while (win->map->map[i][j] && win->map->map[i][j] != '\n')
			j++;
		if (win->map->wid != j)
			show_error(2);
		win->map->map[++i] = get_next_line(fd);
		j = 0;
	}
	if (i > 128 || j > 128)
		show_error(3);
	win->map->hei = i;
	close (fd);
}

void	image_on_window(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map_images(win);
	while (win->map->map[y] != NULL)
	{
		while (win->map->map[y][x] && win->map->map[y][x] != '\n')
		{
			mlx_put_image_to_window(win->mlx, win->mlx_win,
				which_image(win->map->map[y][x], win), x * 64, y * 64);
			x++;
		}
		y++;
		x = 0;
	}
}

void	where_is_char(char c, t_win *win)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (win->map->map[y] != NULL)
	{
		while (win->map->map[y][x])
		{
			if (win->map->map[y][x] == c)
			{
				win->map->wid = x;
				win->map->hei = y;
				i++;
			}
			x++;
		}
		y++;
		x = 0;
	}
	char_error(i, c);
}
