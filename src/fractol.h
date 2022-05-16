/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:49:47 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/16 03:12:25 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"

/* window */
# define WIDTH	600
# define HEIGHT	600

// side / vert = real min / real max
/* calc */
# define PIXEL_SCALE		100.0 /* Scale */
# define INIT_X_POSITION	-3.0 /* x initial position */
# define INIT_Y_POSITION	-3.0 /* y initial pos */
# define MOVE_DIST			0.5 /* Move distance for the arrow keys */
# define INIT_MAG			1.0 /* Initial magnification */
# define ZOOM				0.5 /* Zoom initialization */
# define INIT_IMAX			25 /* Initialization of max iterations - adjustable*/

/* color */

# define INIT_COLOR			0
# define COLOR_CHANGE		16
# define COLOR_MAX			1600

/* keycodes for linux*/

# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define KEY_UP				65362
# define KEY_A				97
# define KEY_D				100
# define KEY_SCROLLUP		5
# define KEY_SCROLLDOWN		4
# define KEY_SCROLLLEFT		6
# define KEY_SCROLLRIGHT	7
# define KEY_ESC			65307
# define X_BUTTON			33

/* fractal number */

# define MANDELBROT		1
# define JULIA_PARAM	2
# define BURNINGSHIP	3

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		type;
	double	x_param;
	double	y_param;
	int		x_mouse;
	int		y_mouse;
	int		color;
	double	side;
	double	vert;
	double	mag;
	int		i_max;
}	t_vars;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

/* main */
void		error_msg(void);
int			args_check(t_vars *vars, int argc, char **argv);
int			vars_init(t_vars *vars);
int			make_image(t_vars *vars);

/* complex ops */
void		init(t_complex *c, double a, double b);
void		add(t_complex *c, t_complex a, t_complex b);
void		sqr(t_complex *c, t_complex a);
double		mod(t_complex a);
void		mappoint(t_vars *vars, t_complex *c, int x, int y);

/* key and hooks ops */
int			mouse_hook(int x, int y, t_vars *vars);
int			mouse_click(int button, int x, int y, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
int			x_button(t_vars *vars);

/* fractal */
int			create_trgb(t_vars *vars, int i);
int			mandelbrot(t_vars *vars, int ix, int iy);
int			julia(t_vars *vars, int ix, int iy);
int			burningship(t_vars *vars, int ix, int iy);
void		fractal(t_vars *vars);

/* libft utils */

double		ft_atof(char *s);
int			ft_strcmp_f(const char *s1, const char *s2);
int			ft_isdigit(int c);

/* utils */
void		free_mlx(t_vars *vars);
int			argv_check(char *s);
void		img_pixel_put(t_vars *vars, int x, int y, int color);

#endif
