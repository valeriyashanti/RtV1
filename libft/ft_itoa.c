/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:07:41 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/25 14:57:01 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_numlen(int n)
{
	int		len;

	len = 0;
	if (n < 0 || n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	char	*ft_minint(char *src)
{
	char	*error;
	int		i;

	i = 0;
	error = "-2147483648";
	while (i < 11)
	{
		src[i] = error[i];
		i++;
	}
	return (src);
}

char			*ft_itoa(int n)
{
	char	*fresh;
	int		num;
	int		tmp;

	num = ft_numlen(n);
	fresh = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * (num + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_minint(fresh));
	if (n < 0)
	{
		fresh[0] = '-';
		n = -n;
	}
	fresh[num--] = '\0';
	if (n == 0)
		fresh[0] = '0';
	while (n)
	{
		tmp = n;
		fresh[num--] = tmp % 10 + 48;
		n /= 10;
	}
	return (fresh);
}
