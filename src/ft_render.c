/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:02:22 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 20:11:19 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * img->size_line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_addr + offset) = color;
}

static void	select_type_fractal(t_complex *z, t_complex *c, t_fractal *fractol)
{
	if (!ft_strncmp(fractol->title, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	ft_draw_pixel(int x, int y, t_fractal *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (ft_scale(x, -2, +2, 799) * fractol->zoom) + fractol->shift_x;
	z.y = (ft_scale(y, -2, +2, 799) * fractol->zoom) + fractol->shift_y;
	select_type_fractal(&z, &c, fractol);
	while (i < fractol->max_iteration)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = ft_scale(i, BLACK, WHITE, fractol->max_iteration);
			ft_my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	ft_my_pixel_put(x, y, &fractol->img, TURQUOISE);
}

void	ft_render(t_fractal *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			ft_draw_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
		fractol->mlx_window, fractol->img.img, 0, 0);
}
