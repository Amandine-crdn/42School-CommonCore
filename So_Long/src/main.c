/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerdan <acerdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:32:58 by acerdan           #+#    #+#             */
/*   Updated: 2022/02/04 02:42:35 by acerdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_structure(t_game *game, char **argv)
{
	game->filename = argv[1];
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->collectible = 0;
	game->player = 0;
	game->end = 0;
	game->nb_move = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->sprite_player_1 = NULL;
	game->sprite_player_2 = NULL;
	game->sprite_collectible = NULL;
	game->sprite_end = NULL;
	game->sprite_air = NULL;
	game->sprite_rock = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, ERROR_MLX);
	game->window = NULL;
	game->img_size = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->sprite_sun = NULL;
	game->sprite_bat_danger = NULL;
}

static int	close_with_cross(t_game *game)
{
	ft_exit(game, END_OF_GAME);
	return (SUCCESS);
}

static void	ft_check_errors(t_game *game)
{
	int	err;

	err = ft_open_file(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_rectangle(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_symbol(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_wall(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_parse_xpm(game);
	if (err < 0)
		ft_exit(game, err);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_exit(NULL, ERROR_USAGE);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(game, ERROR_MALLOC);
	ft_init_structure(game, argv);
	if (ft_check_extension(game) == ERROR)
		ft_exit(game, ERROR_USAGE);
	ft_check_errors(game);
	ft_render_img(game);
	mlx_key_hook(game->window, ft_event_key, game);
	mlx_hook(game->window, 33, 1L << 22, close_with_cross, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}
