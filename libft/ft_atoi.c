/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:22:38 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/21 18:28:13 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int						neg;
	int						i;
	long long int			num;
	long long int			temp;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\f') \
	|| (str[i] == '\t') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (str[i] == 45)
		neg = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		temp = num;
		num *= 10;
		num += ((int)str[i] - 48);
		if (num < temp)
			return (neg == 1 ? 0 : -1);
		i++;
	}
	return (neg == 1 ? -num : num);
}
