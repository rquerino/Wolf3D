/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:53:53 by rquerino          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:13 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Raycasting run in constant time, so you can use a massive world and the
** performance will be the same as a tiny one.
*/

void	ft_getfirstpos(t_wolf *w)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (w->map[y][x] != 0)
		while (y < w->mapsize_y)
		{
			x = 0;
			while (x < w->mapsize_x)
				x++;
			y++;
		}
	w->pos_x = x;
	w->pos_y = y;
}

/*
** Function that reads the map and stores its information in a 2D array.
** Also stores its size.
*/

void	ft_readmap(int fd, t_wolf *w)
{
	char	*buff;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (get_next_line(fd, &buff) > 0)
	{
		x = 0;
		i = 0;
		while (i < ft_strlen(buff))
		{
			if (buff[i] >= '0' && buff[i] <= '9')
			{
				w->map[y][x] = buff[i] - '0';
				x++;
			}
			i++;
		}
		y++;
	}
	w->mapsize_x = i + 1;
	w->mapsize_y = y + 1;
}

/*
** Function to initialize struct
*/

void	ft_init_struct(int fd, t_wolf *w)
{
	w = malloc(sizeof(t_wolf));
	ft_readmap(fd, w);
	ft_getfirstpos(w);
	w->dir_x = -1.0;
	w->dir_y = 0.0;
	w->time = 0;
	w->old_time = 0;
}
