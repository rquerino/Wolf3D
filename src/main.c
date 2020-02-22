/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:38:50 by rquerino          #+#    #+#             */
/*   Updated: 2020/02/17 14:08:43 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** Functions to handle keyboard, mouse position and scroll
*/

int		ft_funcs(int key, t_wolf *w)
{
	if (key == UP)
		w->pos_x += 1;
	else if (key == DOWN)
		w->pos_x -= 1;
	else if (key == RIGHT)
		w->dir_x += 1;
	else if (key == LEFT)
		w->dir_x -= 1;
	else if (key == ESC)
		ft_free_all(w);
	return (0);
}

/*
** Initialize environment and hook the loop functions
*/

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
	mlx_hook(w->win, 2, 0, ft_funcs, w);
	mlx_loop_hook(w->mlx, ft_draw, w);
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
