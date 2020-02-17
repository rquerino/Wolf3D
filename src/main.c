/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:38:50 by rquerino          #+#    #+#             */
/*   Updated: 2020/02/17 12:43:54 by rquerino         ###   ########.fr       */
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

void	ft_init_struct(int fd, t_wolf *w)
{
	w = malloc(sizeof(t_wolf));
	ft_readmap(fd, w);
	ft_getfirstpos(w);
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

void	ft_init_env(t_wolf *w)
{
	int		bpp;
	int		size;
	int		endian;

	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, WIDTH, HEIGHT, "Wolf3D");
	w->img_ptr = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->img = (uint32_t*)mlx_get_data_addr(w->img_ptr,
		&bpp, &size, &endian);
	// mlx_hook(w->win, 2, 0, ft_funcs, w);
	// mlx_hook(w->win, 4, 0, ft_scroll, w);
	// mlx_hook(w->win, 6, 0, ft_movement, w);
	// mlx_loop_hook(w->mlx, ft_draw_julia, w);
	mlx_loop(w->mlx);
}

/*
** Free memory, called when ESC is pressed.
*/

void	ft_free_all(t_wolf *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_destroy_window(w->mlx, w->win);
	free(w);
	exit(0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_wolf	*w;

	if (ac == 2)
	{
		if (fd = open(av[1], O_RDONLY))
		{
			ft_initstruct(fd, w);
			ft_init_env(w);
		}
		else
			ft_putstr("Please enter a valid file.\n");
	}
	else
		ft_putstr("Usage: ./wolf3d <file>\n");
	return (0);
}