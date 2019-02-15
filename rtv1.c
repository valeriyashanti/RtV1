/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:08:22 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 14:15:28 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int plus_color(int color1, int color2)
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
/* 		
	color_u1.rgb.g += color_u2.rgb.g;
	color_u1.rgb.r += color_u2.rgb.r; */

	color1 = color_u1.value;
	return (color1);
}



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
				// rt->color = get_light(&rt->obj, rt);
				// rt->dir = init_direction(&rt->objects[k], rt);
				// rt->color1 = get_light2(&rt->obj, rt);
				// rt->color = plus_color(get_light(&rt->obj, rt), get_light2(&rt->obj, rt));
					double o = 0.0;
				//if (j == 291 && i == 294)
					o = get_light(&rt->obj, rt);
				// if (j == 519 && i == -20)
				// 	o = get_light(&rt->obj, rt);
				double z = 0.0;
				rt->dir = init_direction(&rt->objects[k], rt);
				//z = get_light2(&rt->obj, rt);
				double ia = o + z;
				// if (j == 291 && i == 294)
				// 	printf("black %lf\n", ia);
				// if (j == 288 && i == 301)
				// 	printf("norm %lf\n", ia);
				rt->color = get_color(ia, rt->obj);
				// rt->color = (i + j);
				// printf("%lf %lf\n%d %d\n", rt->light.inten, rt->light1.inten, i, j);

				// rt->color = get_light2(rt->obj, *rt);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			j++;
		}
		i++;
	}
}
