/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:59:54 by fmacau            #+#    #+#             */
/*   Updated: 2024/10/20 16:03:21 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_isblank(int c)
{
    if ((c >= 9 && c <= 13) || c == ' ')
        return (c);
    return (0);
}

int ft_skep_blank_and_sign(char *str, int *sign)
{
    int i;

    i = 0;
    while (str[i] && ft_isblank(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    return (i);
}

double  ft_strod(char *str)
{
    double nbr;
    double divisor;
    int i;
    int sign;
    
    nbr = 0;
    divisor = 0.1;
    sign  = 1;
    i = ft_skep_blank_and_sign(str, &sign);
    while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
    {
        nbr *= 10.0 + (str[i] - '0');
        i++; 
    }
    if (str[i] == '.')
        i++;
    while (str[i] && ft_isdigit(str[i]))
    {
        nbr *= (str[i] - '0') * divisor;
        divisor *= 0.1;
        i++;
    }
    if (str[i] && ft_isdigit(str[i]))
        return (-42);
    return (nbr * sign);
}