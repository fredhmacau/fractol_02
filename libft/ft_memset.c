/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:22:07 by fmacau            #+#    #+#             */
/*   Updated: 2024/05/17 11:27:24 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned int	n;
	unsigned char	*byte_ptr;

	n = 0;
	byte_ptr = (unsigned char *)ptr;
	while (n < len)
	{
		byte_ptr[n] = (unsigned char)value;
		n++;
	}
	return (byte_ptr);
}
