/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 03:27:07 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 09:50:26 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	wall_error(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map->map[0][x] != '\n' && win->map->map[0][x])
	{
		if (win->map->map[0][x] != '1')
			show_error(7);
		x++;
	}
	x--;
	while (win->map->map[y] != NULL)
	{
		if (win->map->map[y][x] != '1')
			show_error(7);
		y++;
	}		
	y--;
	x = 0;
	wall_error2(x, y, win);
}

void	wall_error2(int x, int y, t_win *win)
{
	while (win->map->map[y][x] != '\n' && win->map->map[y][x])
	{
		if (win->map->map[y][x] != '1')
			show_error(7);
		x++;
	}
	x--;
	y = 0;
	while (win->map->map[y] != NULL)
	{
		if (win->map->map[0][x] != '1')
			show_error(7);
		y++;
	}
}

void	ber_error(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i --;
	if (map[i] != 'r')
		show_error(9);
	i--;
	if (map[i] != 'e')
		show_error(9);
	i--;
	if (map[i] != 'b')
		show_error(9);
	i--;
	if (map[i] != '.')
		show_error(9);
	i--;
	if (i < 1 || map[i] == '/')
		show_error(9);
}

void	char_error(int piece, char c)
{
	if (piece != 1 && c == 'P')
		show_error(4);
	if (piece != 1 && c == 'E')
		show_error(5);
	if (piece < 1 && c == 'C')
		show_error(6);
}

void	show_error(int err)
{
	if (err == 0)
		ft_putstr_fd("wrong map character", 1);
	else if (err == 1)
		ft_putstr_fd("map does not open", 1);
	else if (err == 2)
		ft_putstr_fd("lines of the map are not equal", 1);
	else if (err == 3)
		ft_putstr_fd("stable limit exceeded", 1);
	else if (err == 4)
		ft_putstr_fd("wrong number of player", 1);
	else if (err == 5)
		ft_putstr_fd("wrong number of exit", 1);
	else if (err == 6)
		ft_putstr_fd("coin not found", 1);
	else if (err == 7)
		ft_putstr_fd("Walls do not surround the map", 1);
	else if (err == 8)
		ft_putstr_fd("wrong number of argument", 1);
	else if (err == 9)
		ft_putstr_fd("invalid argument name", 1);
	else if (err == 10)
		ft_putstr_fd("Unable to access coins or exit", 1);
	else if (err == 11)
		ft_putstr_fd("map file is empty", 1);
	exit(1);
}
