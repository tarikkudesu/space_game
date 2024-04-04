/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/04/02 18:23:29 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_ship(t_fdf *fdf, int x, int y, int fire)
{
	if (fire)
	{
		for (int j = x - 5; j < x + 5; j++) {
			for (int i = y; i >= 0; i--)
				mlx_pixel_put(fdf->mlx, fdf->win, j, i, 0x20fafa);
		}
		for (int i = 1; i < 12; i++)
		{
			if (x > 160 * i - 60 && x < 160 * i + 60 && y > 160)
				fdf->enemy->live[i - 1] = 0;
		}
		
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->player->ball, x - 80, y - 80);
}

int	update(void *f)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)f;
	if (fdf->intro == 1)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->intro, 0, 0);
	else
	{
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->back, fdf->b_x, fdf->b_y);
		fdf->b_y += 5;
		if (fdf->b_y == 0)
			fdf->b_y = -1080;
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->player->ball, fdf->x - 80, fdf->y - 80);
		for (int i = 1; i < 12; i++)
		{
			if (fdf->enemy->live[i - 1] == 1)
				mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->enemy->enemy_ship, 160 * i - 80, 160 - 80);
		}
	}
	return (0);
}

int	handle_key(int key, void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	fdf->intro = 0;
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->back, fdf->b_x, fdf->b_y);
	for (int i = 1; i < 12; i++)
	{
		if (fdf->enemy->live[i - 1] == 1)
			mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->enemy->enemy_ship, 160 * i - 80, 160 - 80);
	}
	fdf->b_y += 5;
	if (fdf->b_y == 0)
		fdf->b_y = -1080;
	if (key == 53)
		exit_program(fdf);
	if (key == RIGHT && fdf->x < 1920)
		fdf->x += 30;
	else if (key == LEFT && fdf->x > 0)
		fdf->x -= 30;
	else if (key == UP && fdf->y > 0)
		fdf->y -= 30;
	else if (key == DOWN && fdf->y < 1080)
		fdf->y += 30;
	else if (key == 49)
		put_ship(fdf, fdf->x, fdf->y, 1);
	put_ship(fdf, fdf->x, fdf->y, 0);
	// printf("%d\n", key);
	return (0);
}
