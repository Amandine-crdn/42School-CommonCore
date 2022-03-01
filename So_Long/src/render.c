/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:32:36 by acerdan           #+#    #+#             */
/*   Updated: 2022/03/01 11:33:44 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_choice_player(t_game *game, int i, int j)
{
	if (game->map[i + 1][j] == 'X' || game->map[i - 1][j] == 'X'
	|| game->map[i][j + 1] == 'X' || game->map[i][j - 1] == 'X')
		return (1);
	return (0);
}

static void	ft_render_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_air, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P' && ft_choice_player(game, i, j) == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_bat_danger, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P' && (game->nb_move % 2 == 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_1, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P' && (game->nb_move % 2 != 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_2, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_rock, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_sun, IMG_SIZE * j, IMG_SIZE * i);
}

void	ft_render_img(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_render_sprites(game, i, j);
	}
}
