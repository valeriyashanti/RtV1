/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:44:50 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/11 11:46:27 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static	int			is_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

static	int			is_base(int c, int base)
{
	char	*str;
	char	*str_up;
	int		i;

	str = "0123456789abcdef";
	str_up = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str_up[i])
			return (i);
		i++;
	}
	return (-1);
}

int					ft_atoi_base(char *str, int base)
{
	int i;
	int n;
	int ng;

	i = 0;
	n = 0;
	ng = 0;
	while (is_spaces(str[i]))
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (is_base(str[i], base) != -1)
	{
		n = n * base;
		n = n + is_base(str[i], base);
		i++;
	}
	if (ng)
		return (-n);
	return (n);
}
