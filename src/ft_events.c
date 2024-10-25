/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:13:11 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 19:57:14 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handler(t_fractal *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(1);
}

int	key_handler(int keycode, t_fractal *fractol)
{
	if (keycode == ESC)
		close_handler(fractol);
	else if (keycode == 113)
		close_handler(fractol);
	else if (keycode == SET_LEFT)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keycode == SET_RIGHT)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keycode == SET_UP)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keycode == SET_DOWN)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keycode == ZOOM_PLUS)
		fractol->max_iteration += 10;
	else if (keycode == ZOOM_SUB)
		fractol->max_iteration -= 10;
	ft_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractol)
{
	(void)x;
	(void)y;
	if (button == MOUSE_WHEEL_DOWN)
		fractol->zoom *= 0.95;
	else if (button == MOUSE_WHEEL_UP)
		fractol->zoom *= 1.05;
	ft_render(fractol);
	return (0);
}
