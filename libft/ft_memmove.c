/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:08:35 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/22 15:35:35 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *fresh;
	unsigned char *string;

	fresh = (unsigned char *)dst;
	string = (unsigned char *)src;
	if (fresh <= string || fresh >= (string + n))
	{
		while (n--)
			*fresh++ = *string++;
	}
	else
	{
		fresh += n - 1;
		string += n - 1;
		while (n--)
			*fresh-- = *string--;
	}
	return (dst);
}
