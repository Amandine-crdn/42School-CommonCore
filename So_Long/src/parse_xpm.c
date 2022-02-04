/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:58:07 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/04 02:37:29 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_extra_sprites(t_game *game)
{
	game->sprite_sun = mlx_xpm_file_to_image(game->mlx,
			"xpm/sunny.xpm", &game->img_size, &game->img_size);
	if (!game->sprite_sun)
		ft_exit(game, ERROR_OPEN);
	return (SUCCESS);
}

int	ft_parse_xpm(t_game *game)
{
	game->img_size = IMG_SIZE;
	game->win_height = game->img_size * game->map_height;
	game->win_width = game->img_size * game->map_width;
	game->window = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
	game->sprite_end = mlx_xpm_file_to_image(game->mlx,
			"xpm/sleeping_bat.xpm", &game->img_size, &game->img_size);
	game->sprite_air = mlx_xpm_file_to_image(game->mlx,
			"xpm/air.xpm", &game->img_size, &game->img_size);
	game->sprite_player_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/bat_1.xpm", &game->img_size, &game->img_size);
	game->sprite_player_2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/bat_2.xpm", &game->img_size, &game->img_size);
	game->sprite_rock = mlx_xpm_file_to_image(game->mlx,
			"xpm/rock.xpm", &game->img_size, &game->img_size);
	game->sprite_collectible = mlx_xpm_file_to_image(game->mlx,
			"xpm/blood.xpm", &game->img_size, &game->img_size);
	game->sprite_bat_danger = mlx_xpm_file_to_image(game->mlx,
			"xpm/bat_danger.xpm", &game->img_size, &game->img_size);
	ft_extra_sprites(game);
	if (!game->sprite_end || !game->sprite_air || !game->sprite_player_1
		|| !game->sprite_player_2 || !game->sprite_bat_danger || !game->sprite_rock
		|| !game->sprite_collectible)
		ft_exit(game, ERROR_OPEN);
	return (SUCCESS);
}
