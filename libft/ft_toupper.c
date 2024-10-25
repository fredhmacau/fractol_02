/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:44:41 by fmacau            #+#    #+#             */
/*   Updated: 2024/05/17 11:46:02 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
	{
		return (ch - 32);
	}
	return (ch);
}
