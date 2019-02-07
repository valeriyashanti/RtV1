/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:11:26 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/30 13:11:39 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_remalloc(void *ptr, size_t prev_size, size_t size_need)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(size_need)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, prev_size < size_need ? prev_size : size_need);
	free(ptr);
	return (new);
}
