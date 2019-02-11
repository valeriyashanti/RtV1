/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 22:28:29 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/24 22:32:58 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (size == (size_t)-1)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_memset(fresh, '\0', size + 1);
	return (fresh);
}
