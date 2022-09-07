/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:23:01 by llo-surd          #+#    #+#             */
/*   Updated: 2022/09/01 15:49:13 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_game *aa)
{
	int	x;
	int	y;

	aa->b = mlx_xpm_file_to_image(aa->mx, "sprite_srcs/background.xpm", &x, &y);
	aa->e = mlx_xpm_file_to_image(aa->mx, "sprite_srcs/exit.xpm", &x, &y);
	aa->pearl = mlx_xpm_file_to_image(aa->mx, "sprite_srcs/pearl.xpm", &x, &y);
	aa->sub = mlx_xpm_file_to_image(aa->mx, "sprite_srcs/sub.xpm", &x, &y);
	aa->w = mlx_xpm_file_to_image(aa->mx, "sprite_srcs/wall.xpm", &x, &y);
}

void	place_sub(t_game *aa, int y, int x)
{
	mlx_put_image_to_window(aa->mx, aa->win, aa->sub, x * 49, y * 49);
	aa->positiony = y;
	aa->positionx = x;
}

void	pearl_count(t_game *aa, int y, int x)
{
	mlx_put_image_to_window(aa->mx, aa->win, aa->pearl, x * 49, y * 49);
	aa->pearls++;
}

void	place_images(t_game *aa)
{
	int	x;
	int	y;

	y = 0;
	aa->pearls = 0;
	while (y < aa->map_y_axis)
	{
		x = 0;
		while (aa->map[y][x])
		{
			if (aa->map[y][x] == '1')
				mlx_put_image_to_window(aa->mx, aa->win, aa->w, x * 49, y * 49);
			if (aa->map[y][x] == '0')
				mlx_put_image_to_window(aa->mx, aa->win, aa->b, x * 49, y * 49);
			if (aa->map[y][x] == 'C')
				pearl_count(aa, y, x);
			if (aa->map[y][x] == 'E')
				mlx_put_image_to_window(aa->mx, aa->win, aa->e, x * 49, y * 49);
			if (aa->map[y][x] == 'P')
				place_sub(aa, y, x);
			x++;
		}
		y++;
	}
}
