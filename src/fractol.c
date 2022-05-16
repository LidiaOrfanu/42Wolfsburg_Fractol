/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:46 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 19:51:48 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_vars *vars, int ix, int iy)
{
	t_complex	c;
	t_complex	z0;
	t_complex	z1;
	int			i;

	mappoint(vars, &c, ix, iy);
	init(&z0, 0.0, 0.0);
	init(&z1, 0.0, 0.0);
	i = 0;
	while (++i < vars->i_max)
	{
		sqr(&z0, z0);
		add(&z1, z0, c);
		if (mod(z1) > 4)
			break ;
		z0 = z1;
	}
	return (create_trgb(vars, i));
}

int	julia(t_vars *vars, int ix, int iy)
{
	t_complex	c;
	t_complex	z0;
	t_complex	z1;
	int			i;

	init(&c, vars->x_param, vars->y_param);
	mappoint(vars, &z0, ix, iy);
	i = 0;
	while (++i < vars->i_max)
	{
		sqr(&z0, z0);
		add(&z1, z0, c);
		if (mod(z1) > 4)
			break ;
		z0 = z1;
	}
	return (create_trgb(vars, i));
}

int	burningship(t_vars *vars, int ix, int iy)
{
	t_complex	c;
	t_complex	z0;
	t_complex	z1;
	int			i;

	mappoint(vars, &c, ix, iy);
	init(&z0, 0.0, 0.0);
	init(&z1, 0.0, 0.0);
	i = 0;
	while (++i < vars->i_max)
	{
		sqr(&z0, z0);
		add(&z1, z0, c);
		if (mod(z1) > 4)
			break ;
		z0.x = fabs(z1.x);
		z0.y = fabs(z1.y);
	}
	return (create_trgb(vars, i));
}

void	fractal(t_vars *vars)
{
	int		ix;
	int		iy;
	int		color;

	iy = -1;
	while (++iy < HEIGHT)
	{
		ix = -1;
		while (++ix < WIDTH)
		{
			if (vars->type == MANDELBROT)
				color = mandelbrot(vars, ix, iy);
			else if (vars->type == JULIA_PARAM)
				color = julia(vars, ix, iy);
			else if (vars->type == BURNINGSHIP)
				color = burningship(vars, ix, iy);
			img_pixel_put(vars, ix, iy, color);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int	create_trgb(t_vars *vars, int i)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	if (i == vars->i_max)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		r = sin(0.6 * i + 0) * 127 + 128 + vars->color;
		g = sin(0.6 * i + 2 * M_PI / 3) * 127 + 128 + vars->color;
		b = sin(3.66 * i + 4 * M_PI / 3) * 127 + 128 + vars->color;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}
