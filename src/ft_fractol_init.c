/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:30:22 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 20:46:24 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_error(char *error)
{
	ft_putendl_fd(error, 1);
	exit(0);
}

void	ft_data_init(t_fractal *fractol)
{
	fractol->escape_value = 4;
	fractol->max_iteration = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractal *fractol)
{
	mlx_hook(fractol->mlx_window, KEY_PRESS, 1L << 0,
		key_handler, fractol);
	mlx_hook(fractol->mlx_window, 4, 1L << 2,
		mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, DESTROY_NOTIFY, 1L << 17,
		close_handler, fractol);
}

void	ft_fractol_init(t_fractal *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		ft_error("error establishing connection with mlx");
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH,
			HEIGHT, fractol->title);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		ft_error("error starting window");
	}
	fractol->img.img = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
		free(fractol->mlx_connection);
		ft_error("error drawing image");
	}
	fractol->img.img_addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
	events_init(fractol);
	ft_data_init(fractol);
}
