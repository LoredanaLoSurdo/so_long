/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:25:53 by llo-surd          #+#    #+#             */
/*   Updated: 2022/09/02 18:13:06 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_boundary(t_game *aa)
{
	int	x;
	int	y;

	x = 0;
	while (x < aa->map_x_axis)
	{
		if (!(aa->map[0][x] == '1' && aa->map[aa->map_y_axis - 1][x] == '1'))
		{
			ft_printf("\e[31m\e[1mError\nMap is not enclosed.\e[0m \n");
			exit_game(aa);
		}
		x++;
	}
	y = 0;
	while (y < aa->map_y_axis)
	{
		if (!(aa->map[y][0] == '1' && aa->map[y][aa->map_x_axis - 1] == '1'))
		{
			ft_printf("\e[31m\e[1mError\nMap is not enclosed.\e[0m \n");
			exit_game(aa);
		}
		y++;
	}
}

void	count_elements(t_game *aa, int x, int y)
{
	if (aa->map[y][x] == 'C')
		aa->collectible_count++;
	if (aa->map[y][x] == 'P')
		aa->player_count++;
	if (aa->map[y][x] == 'E')
		aa->exit_count++;
}

void	check_elements(t_game *aa)
{
	int	x;
	int	y;

	y = 0;
	while (y < aa->map_y_axis - 1)
	{
		x = 0;
		while (x <= aa->map_x_axis)
		{
			count_elements(aa, x, y);
			if (aa->map[y][x] != '1'
				&& aa->map[y][x] != '0'
				&& aa->map[y][x] != 'C'
				&& aa->map[y][x] != 'E'
				&& aa->map[y][x] != 'P'
				&& aa->map[y][x] != '\n')
			{
				ft_printf("\e[31m\e[1mError\nForbidden character in map.\e[0m  \n");
				exit_game(aa);
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_game *aa)
{
	map_boundary(aa);
	check_elements(aa);
	if (!(aa->collectible_count >= 1
			&& aa->player_count == 1
			&& aa-> exit_count == 1))
	{
		ft_printf("\e[31m\e[1mError\nMap needs 1 sub, 1 exit & >=1 pearl.\e[0m\n");
		exit_game(aa);
	}
}
