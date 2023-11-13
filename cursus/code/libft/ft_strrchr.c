/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jason <jason@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:27:02 by jason             #+#    #+#             */
/*   Updated: 2023/10/04 12:13:45 by jason            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int i)
{
	char	*pstr;
	int		target;

	pstr = (char *)str;
	target = i;
	while (*pstr)
	{
		pstr++;
	}
	while (pstr != str && *pstr != target)
	{
		pstr--;
	}
	if (target == *pstr)
		return ((char *)(pstr));
	return (0);
}
