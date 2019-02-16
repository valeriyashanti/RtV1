/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:08:22 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 15:42:34 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			plus_color(int color1, int color2)
{
	t_color color_u1;
	t_color color_u2;

	color_u1.value = color1;
	color_u2.value = color2;
	if (((int)color_u1.rgb.b + (int)color_u2.rgb.b) > 255)
		color_u1.rgb.b = (char)255;
	else
		color_u1.rgb.b += color_u2.rgb.b;

	if (((int)color_u1.rgb.g + (int)color_u2.rgb.g) > 255)
		color_u1.rgb.g = (char)255;
	else
		color_u1.rgb.g += color_u2.rgb.g;

	if (((int)color_u1.rgb.r + (int)color_u2.rgb.r) > 255)
		color_u1.rgb.r = (char)255;
	else
		color_u1.rgb.r += color_u2.rgb.r;
	color1 = color_u1.value;
	return (color1);
}


void			put_objects_pixel(t_rt *rt, int j, int i)
{
	int z;

	z = 1;
	rt->obj.ia = get_light(&rt->obj, rt, rt->light[0]);
	while (rt->light[z].type == 1)
	{
		init_objects_oc(&rt->objects[z], rt, rt->light[z]);
		rt->dir = init_direction(&rt->objects[z], rt);
		rt->obj.ia += get_light(&rt->obj, rt, rt->light[z]);
		z++;
	}
	rt->color = get_color(rt->obj.ia, rt->obj);
	mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
}

void			check_distance(t_rt *rt, int j, int i)
{
	double	res;
	int		k;
	int		col;
	t_obj	o;

	k = 0;
	while (k < rt->obj_number)
	{
		rt->init = init_tracing(rt, i, j);
		init_objects_oc(&rt->objects[k], rt, rt->light[0]);
		rt->dir = init_direction(&rt->objects[k], rt);
		res = rt->objects[k].func(&rt->objects[k] , rt);
		col = rt->objects[k].col.value;
		o = rt->objects[k];
		if (res >= 0.0 && res < rt->res)
		{
			rt->res = res;
			rt->color = col;
			rt->obj = o;
			rt->index = k;
		}
		k++;
	}
	if (rt->res >= 0.0 && rt->res < INFINITY)
		put_objects_pixel(rt, j, i);
}

void			rtv1(t_rt *rt)
{
	int i;
	int j;
	int z;
	
	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			rt->res = INFINITY;
			check_distance(rt, j, i);
			j++;
		}
		i++;
	}
}
