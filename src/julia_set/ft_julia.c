/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:47:44 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/22 08:47:47 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_julia_check_args(char **av)
{
    double  c_re;
    double  c_im;

    if (av[2] == NULL || av[3] == NULL)
        ft_print_help();
    c_re = ft_strod(av[2]);
    c_im = ft_strod(av[3]);
    if (c_re < -2.0 || c_im > 2.0)
        ft_print_help();
}

void    ft_julia_init(t_fractol *julia, double c_re, double c_im)
{
    julia->mlx_init = mlx_init();
    julia->mlx_win = mlx_new_window(julia->mlx_init, WIDTH, HEIGHT, "Julia");
    julia->mlx_img = mlx_new_image(julia->mlx_init, WIDTH, HEIGHT);
    julia->img_addr = mlx_get_data_addr(julia->mlx_img, &julia->bpp, &julia->size_line, &julia->endian);
    if (julia->img_addr == NULL)
    {
        free(julia->mlx_img);
        free(julia->mlx_win);
        free(julia->mlx_init);
        free(julia);
        ft_putendl_fd("mlx_get_data_addr error", 2);
        exit(0);
    }
    julia->set = "julia";
    julia->c_re = c_re;
    julia->c_im = c_im;
}

void    ft_julia_set(char **av)
{
    t_fractol	*julia;
    double      c_re;
    double      c_im;
    
    julia = malloc(sizeof(t_fractol));
    c_re = ft_strod(av[2]);
    c_im = ft_strod(av[3]);
    ft_julia_init(&julia, c_re, c_im);
    ft_draw_julia(&julia);
    mlx_put_image_to_window(julia->mlx_init, julia->mlx_win, julia->mlx_img, 0, 0);
    // mlx_hook(julia->mlx_win, 2, 0, ft_key, julia);
    // mlx_hook(julia->mlx_win, 17, 0, ft_close, julia);
    mlx_loop(julia->mlx_init);
}

void    ft_draw_julia(t_fractol *julia)
{
    int         x;
    int         y;
    double      i;
    double      j;

    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            i = (double)x / WIDTH * 4 - 2;
            j = (double)y / HEIGHT * 4 - 2;
            julia->c_re = i;
            julia->c_im = j;
            i = 0;
            while (julia->c_re * julia->c_re + julia->c_im * julia->c_im < 4 && julia->i < julia->max_iter)
            {
                julia->tmp = julia->c_re;
                julia->c_re = julia->c_re * julia->c_re - julia->c_im * julia->c_im + julia->c_re;
                julia->c_im = 2 * julia->tmp * julia->c_im + julia->c_im;
                i++;
            }
            if (julia->i == julia->max_iter)
                my_mlx_pixel_put(julia, x, y, 0x000000);
            else
                my_mlx_pixel_put(julia, x, y, 0xFFFFFF);
            y++;
        }
        x++;
    }
}
void    ft_julia(char **av)
{
    ft_julia_check_args(av);
    ft_julia_set(av);
}
