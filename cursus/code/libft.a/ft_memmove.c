/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:25:22 by jason             #+#    #+#             */
/*   Updated: 2023/10/04 12:08:12 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dptr;
	unsigned char *sptr;

	if (dest == src || n == 0)
		return (dest);
	if (dest < src)
	{
		dptr = (unsigned char *)dest;
		sptr = (unsigned char *)src;
		while (n--)
			*dptr++ = *sptr++;
	}
	else
	{
		dptr = (unsigned char *)dest + (n - 1);
		sptr = (unsigned char *)src + (n - 1);
		while (n--)
			*dptr-- = *sptr--;
	}
	return (dest);
}