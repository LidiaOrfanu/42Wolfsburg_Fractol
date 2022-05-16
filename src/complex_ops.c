/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:53:56 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 19:26:46 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_complex *c, double a, double b)
{
	c->x = a;
	c->y = b;
}

void	add(t_complex *c, t_complex a, t_complex b)
{
	c->x = a.x + b.x;
	c->y = a.y + b.y;
}

void	sqr(t_complex *c, t_complex a)
{
	c->x = (a.x * a.x) - (a.y * a.y);
	c->y = 2 * a.x * a.y;
}

double	mod(t_complex a)
{
	return ((a.x * a.x + a.y * a.y));
}

void	mappoint(t_vars *vars, t_complex *c, int x, int y)
{
	c->x = (x / (double)PIXEL_SCALE + vars->side) / vars->mag;
	c->y = (y / (double)PIXEL_SCALE + vars->vert) / vars->mag;
}
