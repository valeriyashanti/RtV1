/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:18:32 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/24 18:04:22 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_count(char *s)
{
	int		i;
	int		k;
	int		mem;

	i = 0;
	k = 0;
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
	{
		i++;
		k++;
	}
	while (s[i])
		i++;
	mem = i;
	if (k == i)
		return (0);
	i--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i--;
		k++;
	}
	return (mem - k);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*fresh;
	int		n;
	int		k;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	n = ft_count((char*)s);
	if (!(fresh = (char*)malloc(sizeof(char) * (n + 1))))
		return (0);
	while (s[i] && (s[i] == '\n' || s[i] == '\t' || s[i] == ' '))
		i++;
	while (k < n)
	{
		fresh[k++] = s[i++];
	}
	fresh[k] = '\0';
	return (fresh);
}
