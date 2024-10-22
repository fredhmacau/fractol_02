/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:35:47 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/22 08:35:51 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    ft_select_fractal(char **av)
{
    if (!ft_strncmp("julia", av[1], 5))
        ft_julia(av);
}

int     main(int ac, char **av)
{
    if (ac < 2)
        ft_print_help();
    else
        ft_select_fractal(av);
}