/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:46:06 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 15:39:14 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	init_tracing(t_rt *rt, int i, int j)
{
	t_vec3 init_vec;
	init_vec.x = (j * 1.0 - 300.0) / 600.0 + rt->cam.x;
	init_vec.y = (i * 1.0 - 300.0) / 600.0 + rt->cam.y;
	init_vec.z = 1.0 + rt->cam.z;

	t_vec3 temp_d;
	temp_d = init_vec;

	init_vec.x = temp_d.x * cos(rt->rot_xy) - temp_d.y * sin(rt->rot_xy);
	init_vec.y = temp_d.x * sin(rt->rot_xy) + temp_d.y * cos(rt->rot_xy);

	init_vec.y = temp_d.y * cos(rt->rot_yz) - temp_d.z * sin(rt->rot_yz);
	init_vec.z = temp_d.y * sin(rt->rot_yz) + temp_d.z * cos(rt->rot_yz);

	init_vec.x = temp_d.x * cos(rt->rot_xz) - temp_d.z * sin(rt->rot_xz);
	init_vec.z = temp_d.x * sin(rt->rot_xz) + temp_d.z * cos(rt->rot_xz);

	return (init_vec);
}

t_vec3 init_direction(t_obj *obj, t_rt *rt)
{
	t_vec3 dir;

	if (obj->type == 0)
		obj->oc = vec_minus(rt->cam, obj->dot);
	else if (obj->type == 1)
	{
		obj->r_n.x = obj->radius;
		obj->r_n.y = rt->light.dot.y;
		obj->r_n.z = rt->light.dot.z;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	else if (obj->type == 2)
	{
		obj->r_n.x = rt->light.dot.x;
		obj->r_n.y = obj->radius;
		obj->r_n.z = rt->light.dot.z;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	else
	{
		obj->r_n.x = rt->light.dot.x;
		obj->r_n.y = rt->light.dot.y;
		obj->r_n.z = obj->radius;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	dir = vec_minus(rt->init, rt->cam); 
	dir = vec_div(dir, vec_modul(dir));
	return (dir);
}
