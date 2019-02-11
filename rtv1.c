/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:08:22 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/11 13:07:04 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rtv1(t_rt *rt)
{
	int i;
	int j;
	int r;
	double res;
	double res0;
	int k;

	t_obj o;

	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			rt->res = INFINITY;
			int col;
			k = 0;
			while (k < rt->obj_number)
			{
				rt->init = init_tracing(rt, i, j);
				rt->dir = init_direction(&rt->objects[k], rt);
				res0 = rt->objects[k].func(&rt->objects[k] , rt);
				col = rt->objects[k].col.value;
				o = rt->objects[k];
				if (res0 >= 0.0 && res0 < rt->res)
				{
					rt->res = res0;
					rt->color = col;
					rt->obj = o;
					rt->index = k;
				}
				k++;
			}
			if (rt->res >= 0.0 && rt->res < INFINITY)
			{
				rt->color = get_light(&rt->obj, rt);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			j++;
		}
		i++;
	}
}
