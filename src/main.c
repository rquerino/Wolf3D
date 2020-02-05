/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:38:50 by rquerino          #+#    #+#             */
/*   Updated: 2020/02/05 14:49:41 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Raycasting run in constant time, so you can use a massive world and the
** performance will be the same as a tiny one.
*/

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

void	ft_init(t_wolf *w)
{

}

int		main(int ac, char **av)
{
	int		fd;
	t_wolf	*w;
	
	if (ac == 2)
	{
		if (fd = open(av[1], O_RDONLY))
		{
			ft_readmap(fd, w);
			ft_init(w);
		}
		else
			ft_putstr("Please enter a valid file.\n");
	}
	else
		ft_putstr("Usage: ./wolf3d <file>\n");
	return (0);
}