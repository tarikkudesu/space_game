/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:17:27 by tamehri           #+#    #+#             */
/*   Updated: 2024/04/02 16:41:57 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define MLX_XPM	"Error : mlx_xpm_file_to_image error"
# define ERR_ARG	"Error : Wrong number of arguments"
# define MLX_ADD	"Error : mlx_get_data_addr error"
# define ERR_OPEN	"Error : Error opening the file"
# define ERR_READ	"Error : Error reading the file"
# define MLX_WIN	"Error : mlx_new_window error"
# define MLX_IMG	"Error : mlx_new_image error"
# define ERR_FILE	"Error : Wrong file format"
# define MLX_INIT	"Error : mlx_init error"
# define ERR_MAL	"Error : malloc error"
# define ERR_EMTY	"Error : empty file"
# define WIDTH		1920
# define HEIGHT		1080

# define UP			126
# define DOWN		125
# define RIGHT		124
# define LEFT		123
# define ESC		53

typedef struct s_fdf	t_fdf;
typedef struct s_ui		t_ui;
typedef struct s_p		t_p;
typedef struct s_player	t_player;
typedef struct s_enemy	t_enemy;

struct s_fdf
{
	void		*mlx;
	void		*win;
	t_ui		*ui;
	int			x;
	int			y;
	int			b_x;
	int			b_y;
	int			intro;
	t_player	*player;
	t_enemy		*enemy;
};

struct s_ui
{
	void	*intro;
	void	*back;
};

struct s_enemy
{
	void	*enemy_ship;
	void	*explosion;
	int		live[12];
};

struct s_player
{
	void	*ball;
	void	*laser;
};

struct s_p
{
	int		w;
	int		h;
};


/* FUNCTIONS */
int	update(void *f);

#endif
