/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strclen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:17:31 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/11 12:18:12 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

size_t		strclen(char *line, char c)
{
	size_t len;

	len = 0;
	while (line[len] != c && line[len])
	{
		len++;
	}
	return (len);
}
