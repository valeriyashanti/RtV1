/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 20:32:47 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/24 20:32:48 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int number;

	number = nb;
	if (number == -2147483648)
	{
		ft_putnbr_fd(-214748364, fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		while (number < 0)
		{
			number = number * -1;
			ft_putchar_fd('-', fd);
		}
		if (number > 9)
		{
			ft_putnbr_fd(number / 10, fd);
		}
		ft_putchar_fd(number % 10 + '0', fd);
	}
}
