/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 09:56:54 by fmacau            #+#    #+#             */
/*   Updated: 2024/05/17 11:34:24 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *ptr, size_t len)
{
	unsigned int	n;
	unsigned char	*c_ptr;

	c_ptr = (unsigned char *) ptr;
	n = 0;
	while (n < len)
	{
		c_ptr[n] = '\0';
		n++;
	}
}
