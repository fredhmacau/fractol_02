/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:35:47 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 19:31:00 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandel", 6))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.title = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			ft_check_params(av[2]);
			ft_check_params(av[3]);
			fractal.julia_x = ft_strod(0.0, 0.0, 1.0, av[2]);
			fractal.julia_y = ft_strod(0.0, 0.0, 1.0, av[3]);
		}
		ft_fractol_init(&fractal);
		ft_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_print_help();
	}
}
