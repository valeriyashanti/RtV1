/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:07:22 by gkessler          #+#    #+#             */
/*   Updated: 2018/10/30 21:53:31 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_foreach(void *tab, size_t length, void (*f)(int))
{
	int i;

	i = 0;
	if (!tab || !f)
	{
		return ;
	}
	while (i < (int)length)
	{
		f(((int *)tab)[i]);
		i++;
	}
}
