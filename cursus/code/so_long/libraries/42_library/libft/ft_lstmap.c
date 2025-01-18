/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klinn <klinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:33:51 by klinn             #+#    #+#             */
/*   Updated: 2023/10/04 21:35:37 by klinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*save;
	void	*tmp;

	new_list = NULL;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		tmp = f(lst->content);
		save = ft_lstnew(tmp);
		if (!save)
		{
			if (tmp)
				del(tmp);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, save);
		lst = lst->next;
	}
	return (new_list);
}
