/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:53:47 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 13:53:51 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_mlx(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	argv_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] != '.')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (s[i])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	img_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*pixel_dst;

	pixel_dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
	*(int *)pixel_dst = color;
}
