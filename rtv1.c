/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:08:22 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 17:39:16 by gkessler         ###   ########.fr       */
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
/* 
	t_obj s;
	s.dot.x = 0.0;
	s.dot.y = 0.0;
	s.dot.z = 100.0;
	s.radius = 95.0;
	s.col.value = 0x00ffff;
	s.func = &ray_sphere;
	s.specular = 1.0;
    s.type = 0;
 */
	t_obj s1;
	s1.dot.x = -0.4;
	s1.dot.y = -0.3;
	s1.dot.z = 2.0;
	s1.radius = 0.2;
	s1.func = &ray_sphere;
	s1.col.value = 0x0fff00;
	s1.specular = 1.0;
    s1.type = 0;

	t_obj s2;
	s2.dot.x = 0.0;
	s2.dot.y = 0.0;
	s2.dot.z = 3.0;
	s2.radius = 0.3;
	s2.func = &ray_sphere;
	s2.col.value = 0xff00ff;
	s2.specular = 20.0;
    s2.type = 0;

	t_obj cone;
	cone.dot.x = 0.0;    
	cone.dot.y = 0.0;
	cone.dot.z = 4.0;
	cone.col.value = 0x0000ff;
	cone.specular = 0.1;
	cone.reflective = 0.5;
	cone.func = &ray_cone;
	cone.a = 1;
	cone.b = 1.5;
	cone.c = 1;
    cone.type = 0;

	t_obj roll;
	roll.dot.x = 0.000000;    
	roll.dot.y = 0.000000;
	roll.dot.z = 4.000000;
	roll.col.value = 0x0000ff;
	roll.specular = 0.1;
	roll.reflective = 0.5;
	roll.func = &ray_roll;
	roll.a = 0.5;
	roll.b = 1;
    roll.type = 0;

	t_obj pl_left;
	pl_left.radius = -1.000000;
	pl_left.col.value = 0xff0000;
	pl_left.specular = 1.000000;
	pl_left.func = &ray_plane_x;
	pl_left.reflective = 0.500000;
    pl_left.type = 1;

	t_obj pl_right;
	pl_right.radius = 1.000000;
	pl_right.col.value = 0xff00ff;
	pl_right.specular = 0.900000;
	pl_right.func = &ray_plane_x;
    pl_right.type = 1;
	pl_right.reflective = 0.500000;

	t_obj pl_up;
	pl_up.radius = -1.000000;
	pl_up.col.value = 0x00ffff;
	pl_up.specular = 1.500000;
	pl_up.func = &ray_plane_y;
    pl_up.type = 2;
	pl_up.reflective = 0.500000;

	t_obj pl_down;
	pl_down.radius = 1.000000;
    pl_down.type = 2;
	pl_down.col.value = 0xffff00;
	pl_down.specular = 1.1;
	pl_down.func = &ray_plane_y;
	pl_down.reflective = 0.5;

	t_obj plane_z;
	plane_z.radius = 7.000000;
    plane_z.type = 3;
	plane_z.col.value = 0x0000ff;
	plane_z.specular = 1.100000;
	plane_z.func = &ray_plane_z;
	plane_z.reflective = 0.500000;

// light

	rt->light.dot.x = -0.300000;
	rt->light.dot.y = -0.300000;
	rt->light.dot.z = 1.200000;
	rt->light.inten = 0.900000;

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
			while (k < 7)
			{
				rt->init = init_tracing(rt, i, j);
				if (k == 5)
				{
                    rt->dir = init_direction(&pl_left, rt);
					res0 = pl_left.func(&pl_left, rt);
					col = pl_left.col.value;
					o = pl_left;
				}
				if (k == 1)
				{
                    rt->dir = init_direction(&pl_down, rt);
				 	res0 = pl_down.func(&pl_down, rt);
					col = pl_down.col.value;
					o = pl_down;
				}
				if (k == 2)
				{
                    rt->dir = init_direction(&s1, rt);
					res0 = s1.func(&s1, rt);
					col = s1.col.value;
					o = s1;
				}
				if (k == 6)
				{
                    rt->dir = init_direction(&s2, rt);
					res0 = s2.func(&s2, rt);
					col = s2.col.value;
					o = s2;
				}
				if (k == 3)
				{
                    rt->dir = init_direction(&pl_right, rt);
					res0 = pl_right.func(&pl_right, rt);
					col = pl_right.col.value;
					o = pl_right;
				}
				if (k == 4)
				{
                    rt->dir = init_direction(&pl_up, rt);
					res0 = pl_up.func(&pl_up, rt);
					col = pl_up.col.value;
					o = pl_up;
				}
				if (k == 0)
				{
                    rt->dir = init_direction(&plane_z, rt);
					res0 = plane_z.func(&plane_z, rt);
					col = plane_z.col.value;
					o = plane_z;
				}
				if (res0 > 1.0 && res0 < rt->res)
				{
					rt->res = res0;
					rt->color = col;
					rt->obj = o;
				}
				k++;
			}
			if (rt->res > 1.0 && rt->res < INFINITY)
			{
				rt->color = get_light(rt->obj, rt);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			j++;
		}
		i++;
	}
}
