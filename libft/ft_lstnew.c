/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:14:21 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 17:31:21 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *fresh;

	if (!(fresh = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content || !content_size)
	{
		(*fresh).content = NULL;
		(*fresh).content_size = 0;
	}
	else
	{
		if (!((*fresh).content = malloc(sizeof(content_size))))
		{
			free(fresh);
			return (0);
		}
		(*fresh).content = ft_strdup(content);
		(*fresh).content_size = content_size;
	}
	(*fresh).next = NULL;
	return (fresh);
}
