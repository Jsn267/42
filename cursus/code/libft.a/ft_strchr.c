/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:25:56 by jason             #+#    #+#             */
/*   Updated: 2023/10/04 12:15:14 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

char	*ft_strchr(const char *str, int character)
{
	const char	*ptr;
	int			target;

	ptr = str;
	target = character;
	while (*ptr != '\0' && *ptr != target)
	{
		ptr++;
	}
	if (*ptr == target)
		return ((char *)ptr);
	return (0);
}
