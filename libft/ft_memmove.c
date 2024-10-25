/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmacau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:03:11 by fmacau            #+#    #+#             */
/*   Updated: 2024/05/17 11:44:42 by fmacau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	i;

	i = 0;
	temp_dest = (char *)dest;
	temp_src = (char *)src;
	if (!dest && !src)
		return (dest);
	if (temp_dest > temp_src)
	{
		while (len-- > 0)
		{
			*(temp_dest + len) = *(temp_src + len);
		}
	}
	else
	{
		while (i < len)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}
