/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:54:54 by rquerino          #+#    #+#             */
/*   Updated: 2020/02/05 15:14:25 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define WIDTH	640
# define HEIGHT	480
# define LEFT	123
# define RIGHT	124
# define DOWN	125
# define UP		126
# define ESC	53

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	uint32_t	*img;
	int			player_x;
	int			player_y;
	int			direction;
	int			mapsize_x;
	int			mapsize_y;
	int			**map;
}				t_wolf;

#endif
