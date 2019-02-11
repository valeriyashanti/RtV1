/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:35 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/11 11:26:35 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_plane_x(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;

	// поворт
	// t_vec3 temp_d;
	// temp_d = d;

	// d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	// d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);

	k1 = (rt->dir.x * rt->dir.x);
	k2 = 2 * (rt->dir.x * obj->oc.x);
	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);

	double res = INFINITY;
	if (t >= 0.000000 && t < INFINITY)
		res = t;
	obj->dot.x = rt->cam.x + rt->init.x * (res + 1);
	obj->dot.y = rt->cam.y + rt->init.y * res;
	obj->dot.z = rt->cam.z + rt->init.z * res;
	return (res);
}

double		ray_plane_y(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;

	k1 = (rt->dir.y * rt->dir.y);
	k2 = 2 * (rt->dir.y * obj->oc.y);
	k3 = (obj->oc.y * obj->oc.y);

	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);

	double res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		res = t;
	obj->dot.x = rt->cam.x + rt->init.x * res;
	obj->dot.y = rt->cam.y + rt->init.y * (res + 1);
	obj->dot.z = rt->cam.z + rt->init.z * res;
	return (res);
}

double		ray_plane_z(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t;

	k1 = (rt->dir.z * rt->dir.z);
	k2 = 2.0 * (rt->dir.z * obj->oc.z);
	k3 = (obj->oc.z * obj->oc.z);

	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
		return (-1.0);
	t = (-k2) / (2.000000 * k1);
	double res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		res = t;
	obj->dot.x = rt->cam.x + rt->init.x * res;
	obj->dot.y = rt->cam.y + rt->init.y * res;
	obj->dot.z = rt->cam.z + rt->init.z * (res + 1);
	return (res);
}
