/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:25:16 by jason             #+#    #+#             */
/*   Updated: 2023/10/04 12:06:46 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dptr;
	unsigned char *sptr;
	size_t i;

	if (!dest && !src)
		return (0);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dptr++ = *sptr++;
	return (dest);
}