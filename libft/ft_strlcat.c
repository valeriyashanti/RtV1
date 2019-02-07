/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:10:11 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/22 13:29:05 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_tmp;
	const char	*s_tmp;
	size_t		n;
	size_t		dst_len;

	dst_tmp = dst;
	s_tmp = src;
	n = size;
	while (n-- != 0 && *dst_tmp != '\0')
		dst_tmp++;
	dst_len = dst_tmp - dst;
	n = size - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(s_tmp));
	while (*s_tmp != '\0')
	{
		if (n != 1)
		{
			*dst_tmp++ = *s_tmp;
			n--;
		}
		s_tmp++;
	}
	*dst_tmp = '\0';
	return (dst_len + (s_tmp - src));
}
