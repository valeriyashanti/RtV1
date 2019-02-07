/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:41:57 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/21 13:47:37 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *new;

	if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(src) + 1))))
		return (0);
	new = ft_strcpy(new, src);
	return (new);
}
