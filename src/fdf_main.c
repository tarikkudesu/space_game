/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:14:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/04/02 16:42:42 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ball(t_fdf *fdf)
{
	t_p	ball;
	t_p	en;

	fdf->player->ball = mlx_xpm_file_to_image(fdf->mlx, \
	"assets/ship.xpm", &ball.h, &ball.w);
	if (!fdf->player->ball)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));
	fdf->enemy->enemy_ship = mlx_xpm_file_to_image(fdf->mlx, \
	"assets/enemy.xpm", &en.h, &en.w);
	if (!fdf->enemy->enemy_ship)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));
	for (int i = 0; i < 12; i++)
	{
		fdf->enemy->live[i] = 1;
	}
}

void	panel(t_fdf *fdf)
{
	t_p	intro;
	t_p	back;

	fdf->ui->intro = mlx_xpm_file_to_image(fdf->mlx, \
	"assets/fdf.xpm", &intro.h, &intro.w);
	if (!fdf->ui->intro)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));
	fdf->ui->back = mlx_xpm_file_to_image(fdf->mlx, \
	"assets/background.xpm", &back.h, &back.w);
	if (!fdf->ui->back)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));
}

void	make_it_3d(t_fdf *fdf)
{
	t_ui		ui;
	t_player	player;
	t_enemy		enemy;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "game");
	if (!fdf->win)
		(ft_putendl_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
	ui.intro = NULL;
	fdf->ui = &ui;
	fdf->player = &player;
	fdf->enemy = &enemy;
	panel(fdf);
	ball(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->intro, 0, 0);
	mlx_loop_hook(fdf->mlx, &update, fdf);
	mlx_hook(fdf->win, 2, 0, &handle_key, fdf);
	mlx_hook(fdf->win, 17, 0, &exit_program, fdf);
	mlx_loop(fdf->mlx);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf.x = 960;
	fdf.y = 900;
	fdf.b_x = 0;
	fdf.b_y = -1080;
	fdf.intro = 1;
	(void)av;
	if (ac != 1)
		(ft_putendl_fd(ERR_ARG, 2), exit(1));
	make_it_3d(&fdf);
}
