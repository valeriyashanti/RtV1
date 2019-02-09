/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:35 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/09 14:15:53 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_plane_x(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	obj->oc = vec_minus(rt->cam, obj->dot);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	// d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	// d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);


	k1 = (d.x * d.x);


	k2 = 2 * (d.x * obj->oc.x);


	k3 = (obj->oc.x * obj->oc.x);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	double res = INFINITY;
	if (t1 >= 1.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 1.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >=1 && t2 < INFINITY)
			res = t2;
	}
	return (res);
}

double		ray_plane_y(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	obj->oc = vec_minus(rt->cam, obj->dot);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	k1 = (d.y * d.y);


	k2 = 2 * (d.y * obj->oc.y);


	k3 = (obj->oc.y * obj->oc.y);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	double res = INFINITY;
	if (t1 >= 1.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 1.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >=1 && t2 < INFINITY)
			res = t2;
	}
	return (res);
}

double		ray_plane_z(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	obj->oc = vec_minus(rt->cam, obj->dot);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	// d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	// d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);


	k1 = (d.z * d.z);


	k2 = 2 * (d.z * obj->oc.z);


	k3 = (obj->oc.z * obj->oc.z);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	double res = INFINITY;
	if (t1 >= 1.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 1.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >=1 && t2 < INFINITY)
			res = t2;
	}
	return (res);
}
