/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:07:35 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/28 18:07:41 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*current;
	int		size;

	size = 0;
	if (begin_list)
	{
		current = begin_list;
		while (current != 0)
		{
			current = current->next;
			size++;
		}
	}
	return (size);
}
