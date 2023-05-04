/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:47:15 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 11:22:13 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_win	*map_error(int wid, int hei, t_win *check)
{
	if (check->map->map[hei][wid] != '1' &&
		check->map->map[hei][wid] != 'E')
	{
		check->map->map[hei][wid] = '*';
		if (check->map->map[hei][wid + 1] != '1' &&
		check->map->map[hei][wid + 1] != '*')
			map_error(wid + 1, hei, check);
		if (check->map->map[hei][wid - 1] != '1' &&
		check->map->map[hei][wid - 1] != '*')
			map_error(wid - 1, hei, check);
		if (check->map->map[hei + 1][wid] != '1' &&
		check->map->map[hei + 1][wid] != '*')
			map_error(wid, hei + 1, check);
		if (check->map->map[hei - 1][wid] != '1' &&
		check->map->map[hei - 1][wid] != '*' )
			map_error(wid, hei - 1, check);
	}
	else
		check->map->ex = 1;
	return (check);
}

t_win	*copy_map(char *map)
{
	int		i;
	int		fd;
	t_win	*check;

	i = 0;
	check = malloc(sizeof(t_win));
	add_malloc(check);
	fd = open(map, O_RDONLY);
	check->map->map[i] = get_next_line(fd);
	while (check->map->map[i] != NULL)
		check->map->map[++i] = get_next_line(fd);
	return (check);
}

void	map_control(t_win *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (check->map->map[i] != NULL)
	{
		while (check->map->map[i][j])
		{
			if (check->map->map[i][j] == 'C')
				show_error(10);
			j++;
		}
		j = 0;
		free(check->map->map[i]);
		i++;
	}
	if (check->map->ex != 1)
		show_error(10);
	free_copy(check);
}

void	*which_image(char c, t_win *win)
{
	if (c == '1')
		return (win->image->wall);
	else if (c == '0')
		return (win->image->bg);
	else if (c == 'P')
		return (win->image->player);
	else if (c == 'C')
		return (win->image->coin);
	else if (c == 'E')
		return (win->image->exit);
	else
		show_error(0);
	return (0);
}
