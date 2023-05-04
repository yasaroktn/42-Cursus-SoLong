/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokten <yokten@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:13:20 by yokten            #+#    #+#             */
/*   Updated: 2023/05/04 04:14:58 by yokten           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	add_malloc(t_win *win)
{
	win->map = malloc(sizeof(t_map));
	win->image = malloc(sizeof(t_data));
	win->map->map = (char **)malloc(sizeof(char *) * 128);
}

void	free_copy(t_win *check)
{
	free(check->map->map);
	free(check->map);
	free(check->image);
	free(check);
}
