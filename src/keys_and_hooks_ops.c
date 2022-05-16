/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_and_hooks_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:38:02 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 16:05:19 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int x, int y, t_vars *vars)
{
	vars->x_mouse = x;
	vars->y_mouse = y;
	fractal(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		free_mlx(vars);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_DOWN)
		vars->vert -= MOVE_DIST;
	else if (keycode == KEY_UP)
		vars->vert += MOVE_DIST;
	else if (keycode == KEY_RIGHT)
		vars->side -= MOVE_DIST;
	else if (keycode == KEY_LEFT)
		vars->side += MOVE_DIST;
	else if (keycode == KEY_A && vars->color >= COLOR_CHANGE)
		vars->color -= COLOR_CHANGE;
	else if (keycode == KEY_D && vars->color <= COLOR_MAX)
		vars->color += COLOR_CHANGE;
	fractal(vars);
	return (0);
}

int	mouse_click(int button, int x, int y, t_vars *vars)
{
	t_complex	c;
	double		n;

	mappoint(vars, &c, x, y);
	n = 0.0;
	if (button == KEY_SCROLLDOWN)
	{
		n = vars->mag * ZOOM;
		vars->mag += n;
		vars->side -= n * c.x / ((double)WIDTH * vars->mag) - n * c.x;
		vars->vert -= n * c.y / ((double)HEIGHT * vars->mag) - n * c.y;
	}
	else if (button == KEY_SCROLLUP)
	{
		if (vars->mag > 0.1)
			n = vars->mag * ZOOM;
		vars->mag -= n;
		vars->side += n * c.x / ((double)WIDTH * vars->mag) - n * c.x;
		vars->vert += n * c.y / ((double)HEIGHT * vars->mag) - n * c.y;
	}
	fractal(vars);
	return (0);
}

int	x_button(t_vars *vars)
{
	free_mlx(vars);
	exit(EXIT_SUCCESS);
	return (0);
}
