/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:26:35 by jason             #+#    #+#             */
/*   Updated: 2023/10/04 12:12:49 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t maxlen)
{
	size_t	src_len;
	size_t	count;

	count = 0;
	src_len = ft_strlen(src);
	if (maxlen == 0)
		return (src_len);
	while (src[count] != '\0' && count < (maxlen - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (src_len);
}
