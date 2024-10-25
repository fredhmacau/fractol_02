/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:59:54 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/25 19:06:39 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	ft_strod(int i, double n, double t, char *str)
{
	int	decimal;

	decimal = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			t = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '.')
			decimal = 1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (decimal == 1)
				t /= 10.00;
			n = (n * 10.00) + (str[i] - '0');
		}
		i++;
	}
	return (t * n);
}
