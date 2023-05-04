/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 03:27:13 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 05:19:28 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	move_up(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei - 1][win->map->wid] != '1')
		{
			if (win->map->map[win->map->hei - 1][win->map->wid] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei - 1][win->map->wid] = 'P';
				total_steps(win);
				ft_putstr_fd("WIN!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei - 1][win->map->wid] != 'E')
			{
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei - 1][win->map->wid] = 'P';
				win->map->hei -= 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_down(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei + 1][win->map->wid] != '1')
		{
			if (win->map->map[win->map->hei + 1][win->map->wid] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei + 1][win->map->wid] = 'P';
				total_steps(win);
				ft_putstr_fd("WİN!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei + 1][win->map->wid] != 'E')
			{
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei + 1][win->map->wid] = 'P';
				win->map->hei += 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_right(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei][win->map->wid + 1] != '1')
		{
			if (win->map->map[win->map->hei][win->map->wid + 1] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei][win->map->wid + 1] = 'P';
				total_steps(win);
				ft_putstr_fd("WİN!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei][win->map->wid + 1] != 'E')
			{
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei][win->map->wid + 1] = 'P';
				win->map->wid += 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

void	move_left(t_win *win)
{
	if (win->map->map[win->map->hei][win->map->wid] == 'P')
	{
		if (win->map->map[win->map->hei][win->map->wid - 1] != '1')
		{
			if (win->map->map[win->map->hei][win->map->wid - 1] == 'E' &&
			open_exit(win))
			{
				win->map->map[win->map->hei][win->map->wid - 1] = 'P';
				total_steps(win);
				ft_putstr_fd("WİN!!!", 1);
				exit(1);
			}
			else if (win->map->map[win->map->hei][win->map->wid - 1] != 'E')
			{
				win->map->map[win->map->hei][win->map->wid] = '0';
				win->map->map[win->map->hei][win->map->wid - 1] = 'P';
				win->map->wid -= 1;
			}
		}
	}
	mlx_clear_window(win->mlx, win->mlx_win);
	current_map(win);
}

int	move_char(int keycode, t_win *win)
{
	if (keycode == 13)
		move_up (win);
	if (keycode == 1)
		move_down (win);
	if (keycode == 0)
		move_left (win);
	if (keycode == 2)
		move_right (win);
	if (keycode == 53)
		ft_exit(win);
	return (0);
}
