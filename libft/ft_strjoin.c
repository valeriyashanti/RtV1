/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:03:40 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/24 17:16:18 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(fresh = (char*)malloc(sizeof(char) * (ft_strlen(s1)\
	+ ft_strlen(s2) + 1))))
		return (0);
	while (ft_strlen(s1) > i)
		fresh[k++] = s1[i++];
	i = 0;
	while (ft_strlen(s2) > i)
		fresh[k++] = s2[i++];
	fresh[k] = '\0';
	return (fresh);
}
