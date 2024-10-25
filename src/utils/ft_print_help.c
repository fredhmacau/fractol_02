/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:41:11 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 19:22:10 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_print_help(void)
{
	ft_putendl_fd("Fractal allowed: [Julia, Mandelbrot]", 1);
	ft_putendl_fd("Julia Fractal exemple:", 1);
	ft_putendl_fd("Exemple: ./fractol julia 0.285[>= -2.0] 0.01[<= 2.0]", 1);
	ft_putendl_fd("Mandelbrot Fractal exemple : ./fractol mandel", 1);
	exit(0);
}
