/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:47:49 by lorfanu           #+#    #+#             */
/*   Updated: 2022/05/12 16:04:12 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(void)
{
	write(1, "\nSelect a fractal: 1, 2 or 3\n\
\n\
 1 for Mandelbrot\n\
 2 for Julia with params\n\
 3 for Burning Ship\n\
 \n\
 ex: $ ./fractol 1\n\
     $ ./fractol 2 -0.8 0.156\n\
     $ ./fractol 3\n\
-----------------------------------\n\n", 201);
}

int	args_check(t_vars *vars, int argc, char **argv)
{
	if (argc == 2 && (!ft_strcmp_f(argv[1], "1") || \
	!ft_strcmp_f(argv[1], "3")))
		vars->type = argv[1][0] - '0';
	else if (argc == 4 && !ft_strcmp_f(argv[1], "2") && \
	argv_check(argv[2]) && argv_check(argv[3]))
	{
		vars->type = argv[1][0] - '0';
		vars->x_param = ft_atof(argv[2]);
		vars->y_param = ft_atof(argv[3]);
	}
	else
		return (-1);
	return (0);
}

int	vars_init(t_vars *vars)
{
	vars->color = INIT_COLOR;
	vars->side = INIT_X_POSITION;
	vars->vert = INIT_Y_POSITION;
	vars->mag = INIT_MAG;
	vars->i_max = INIT_IMAX;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (1);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (vars->win == NULL)
		return (-1);
	return (0);
}

int	make_image(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (vars->img == NULL)
	{
		write(1, "Memory allocation failed in mlx_new_image.\n", 44);
		return (-1);
	}
	vars->addr = mlx_get_data_addr(vars->img, \
	&vars->bpp, &vars->line_length, &vars->endian);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (args_check(&vars, argc, argv))
	{
		error_msg();
		return (-1);
	}
	if (vars_init(&vars) || make_image(&vars))
	{
		free_mlx(&vars);
		return (-1);
	}
	fractal(&vars);
	mlx_mouse_hook(vars.win, mouse_click, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, X_BUTTON, 1L << 17, x_button, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
