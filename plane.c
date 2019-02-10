/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:48:35 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 11:34:42 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_plane_x(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.000000 - 300.000000) / 600.000000 + rt->cam.x;
	l.y = (i * 1.000000 - 300.000000) / 600.000000  + rt->cam.y;
	l.z = 1.00000  + rt->cam.z;

	double k1;
	double k2;
	double k3;
	double t;

	t_vec3 r_n;
	r_n.x = obj->radius;
	r_n.y = 0.000000;
	r_n.z = 0.000000;

	

	obj->oc = vec_minus(rt->cam, r_n);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));

	// t_vec3 temp_d;
	// temp_d = d;

	// d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	// d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);


	k1 = (d.x * d.x);
	k2 = 2 * (d.x * obj->oc.x);
	k3 = (obj->oc.x * obj->oc.x);

	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
	{
		// if (i > 100 && i < 500 && j > 100 && j < 500)
		// 	printf("%lf\n", desc);
		return (-1.0);
	}
	t = (-k2) / (2.000000 * k1);

	double res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		res = t;

	obj->dot.x = rt->cam.x + l.x * (res + 1);
	obj->dot.y = rt->cam.y + l.y * res;
	obj->dot.z = rt->cam.z + l.z * res;
	return (res);
}

double		ray_plane_y(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.00000 - 300.00000) / 600.00000 + rt->cam.x;
	l.y = (i * 1.00000 - 300.00000) / 600.00000 + rt->cam.y;
	l.z = 1 + rt->cam.z;

	double k1;
	double k2;
	double k3;

	double t;


	t_vec3 r_n;
	r_n.x = 0.000000;
	r_n.y = obj->radius;
	r_n.z = 0.000000;

	obj->oc = vec_minus(rt->cam, r_n);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	k1 = (d.y * d.y);
	k2 = 2 * (d.y * obj->oc.y);
	k3 = (obj->oc.y * obj->oc.y);

	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
	{
		// if (i > 100 && i < 500 && j > 100 && j < 500)
		// 	printf("%lf\n", desc);
		return (-1.0);
	}
	t = (-k2) / (2.000000 * k1);

	double res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		res = t;
	obj->dot.x = rt->cam.x + l.x * res;
	obj->dot.y = rt->cam.y + l.y * (res + 1);
	obj->dot.z = rt->cam.z + l.z * res;
	return (res);
}

double		ray_plane_z(int j, int  i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.00000 - 300.000000) / 600.000000;
	l.y = (i * 1.00000 - 300.000000) / 600.000000;
	l.z = 1.000000;

	double k1;
	double k2;
	double k3;
	double t;

	t_vec3 r_n;
	r_n.x = 0.000000;
	r_n.y = 0.000000;
	r_n.z = obj->radius;

	obj->oc = vec_minus(rt->cam, r_n);

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	d = vec_div(d, vec_modul(d));

	k1 = (d.z * d.z);
	k2 = 2.0 * (d.z * obj->oc.z);
	k3 = (obj->oc.z * obj->oc.z);

	double desc = k2 * k2 - 4.000000 * k1 * k3;
	if(desc <= -0.000001)
	{
		// if (i > 100 && i < 500 && j > 100 && j < 500)
		// 	printf("%lf\n", desc);
		return (-1.0);
	}
	t = (-k2) / (2.000000 * k1);

	/* if (i > 200 && i < 400 && j > 200 && j < 400)
		printf("t1 = %lf t2 = %lf sqrt = %lf chis = %lf znam = %lf\n", t1, t2, sqrt(desc), (-k2 + sqrt(desc) + 0.0001), (2.000000 * k1 + 0.0001));
 */
	double res = INFINITY;
	if (t > 0.000000 && t < INFINITY)
		res = t;
/* 	if (i > 250 && i < 350 && j > 250 && j < 350)
		printf("%lf\n", res); */

	obj->dot.x = rt->cam.x + l.x * res;
	obj->dot.y = rt->cam.y + l.y * res;
	obj->dot.z = rt->cam.z + l.z * (res + 1.000000);
	return (res);
}
