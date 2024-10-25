/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:38:07 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 19:25:20 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	ft_check_params(char *av)
{
	int	i;
	int	decimal_point_seen;

	i = 0;
	decimal_point_seen = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if (decimal_point_seen)
				ft_print_help();
			decimal_point_seen = 1;
		}
		else if (!ft_isdigit(av[i]))
		{
			ft_print_help();
		}
		i++;
	}
	if (i == 0 || (i == 1 && (av[0] == '+' || av[0] == '-')))
		ft_print_help();
}
