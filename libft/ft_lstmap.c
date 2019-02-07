/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:33:02 by gkessler          #+#    #+#             */
/*   Updated: 2018/12/17 17:35:00 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list		*ft_check(t_list *lst)
{
	t_list *new;

	new = NULL;
	if (lst != NULL)
		new = ft_lstnew(lst->content, lst->content_size);
	return (new);
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;

	fresh = NULL;
	if (!f)
		return (NULL);
	while (lst)
	{
		if (!(ft_push_back(&fresh, ft_check(f(lst)))))
		{
			ft_lstdel(&fresh, &ft_clean);
			return (fresh);
		}
		lst = lst->next;
	}
	return (fresh);
}
