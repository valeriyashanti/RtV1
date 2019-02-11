/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:36:09 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 17:31:46 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words_count(const char *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		if (*str == c)
			str++;
		else
		{
			len++;
			while (*str && *str != c)
				str++;
		}
	}
	return (len);
}
