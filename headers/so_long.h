/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llo-surd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:25:38 by llo-surd          #+#    #+#             */
/*   Updated: 2022/09/01 15:55:52 by llo-surd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include"libft.h"
# include "mlx.h"

typedef struct gameVariables
{
	char	**map;

	int		map_y_axis;
	int		map_x_axis;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		moves_count;
	int		pearls;
	int		positionx;
	int		positiony;

	void	*mx;
	void	*win;
	void	*b;
	void	*e;
	void	*pearl;
	void	*sub;
	void	*w;
}	t_game;

int			exit_game(t_game *aa);
int			read_map(t_game *aa, char *path);
int			player_input(int key, t_game *aa);
void		place_images(t_game *aa);
void		xpm_to_img(t_game *aa);
void		check_map(t_game *aa);

#endif