/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:46:06 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 17:39:29 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	init_tracing(t_rt *rt, int i, int j)
{
	t_vec3 init_vec;
	init_vec.x = (j * 1.0 - 300.0) / 600.0 + rt->cam.x;
	init_vec.y = (i * 1.0 - 300.0) / 600.0 + rt->cam.y;
	init_vec.z = 1.0 + rt->cam.z;
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
		obj->r_n.y = 0.000000;
		obj->r_n.z = 0.000000;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	else if (obj->type == 2)
	{
		obj->r_n.x = 0.000000;
		obj->r_n.y = obj->radius;
		obj->r_n.z = 0.000000;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	else
	{
		obj->r_n.x = 0.000000;
		obj->r_n.y = 0.000000;
		obj->r_n.z = obj->radius;
		obj->oc = vec_minus(rt->cam, obj->r_n);
	}
	dir = vec_minus(rt->init, rt->cam); 
	dir = vec_div(dir, vec_modul(dir));
	return (dir);
}
