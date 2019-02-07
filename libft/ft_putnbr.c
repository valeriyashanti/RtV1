/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:56:28 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/26 17:56:45 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int number;

	number = nb;
	if (number == -2147483648)
	{
		ft_putnbr(-214748364);
		ft_putchar('8');
	}
	else
	{
		while (number < 0)
		{
			number = number * -1;
			ft_putchar('-');
		}
		if (number > 9)
		{
			ft_putnbr(number / 10);
		}
		ft_putchar(number % 10 + '0');
	}
}
