/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:35 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/09 16:00:15 by gkessler         ###   ########.fr       */
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


	t_vec3 r_n;
	r_n.x = obj->radius;
	r_n.y = 0.0;
	r_n.z = 0.0;


	obj->oc = vec_minus(rt->cam, r_n);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	k1 = (d.x * d.x);

	k2 = 2 * (d.x * obj->oc.x);
	k3 = (obj->oc.x * obj->oc.x);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
	{

		return (-1.0);
	}
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
	obj->dot.x = rt->cam.x + l.x * (res + 1);
	obj->dot.y = rt->cam.y + l.y * res;
	obj->dot.z = rt->cam.z + l.z * res;

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


	t_vec3 r_n;
	r_n.x = 0.0;
	r_n.y = obj->radius;
	r_n.z = 0.0;

	obj->oc = vec_minus(rt->cam, r_n);

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

	obj->dot.x = rt->cam.x + l.x * res;
	obj->dot.y = rt->cam.y + l.y * (res + 1);
	obj->dot.z = rt->cam.z + l.z * res;
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

	t_vec3 r_n;
	r_n.x = 0.0;
	r_n.y = 0.0;
	r_n.z = obj->radius;

	obj->oc = vec_minus(rt->cam, r_n);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

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
	obj->dot.x = rt->cam.x + l.x * res;
	obj->dot.y = rt->cam.y + l.y * res;
	obj->dot.z = rt->cam.z + l.z * (res + 1);
	return (res);
}
