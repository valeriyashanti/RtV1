/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:41:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 10:00:19 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double      ray_cone(int j, int  i, t_obj *obj, t_rt *rt)
{
    t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	//obj->oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	obj->oc = vec_minus(rt->null, obj->dot);

	t_vec3 d;
	d = vec_minus(l, rt->null); 
    d = vec_div(d, vec_modul(d));


	t_vec3 temp_d;
	temp_d = d;

	d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);


    k1 = ((d.z * d.z * obj->a * obj->a * obj->b * obj->b) 

	+ (d.x * d.x * obj->c* obj->c * obj->b * obj->b)

	- (d.y * d.y * obj->a * obj->a * obj->c * obj->c));


	k2 = 2 * ((d.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)

	+ (d.x * obj->oc.x * obj->c * obj->c * obj->b * obj->b)

	- (d.y * obj->oc.y * obj->a * obj->a * obj->c * obj->c));


	k3 = (obj->oc.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)

	+ (obj->oc.x * obj->oc.x * obj->c * obj->c
	* obj->b * obj->b)

	- (obj->oc.y * obj->oc.y
	* obj->a * obj->a
	* obj->c * obj->c);
	//k2 = 2 * (rt->cam.x * d.x + rt->cam.y * d.y - rt->cam.z * d.z);
    //k2 = rt->cam.x * rt->cam.x + rt->cam.y * rt->cam.y - rt->cam.z * rt->cam.z;


/* 
	k1 = vec_sc(d, d);
	k2 = 2 * vec_sc(obj->oc, d);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius); */

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	/* t1 = fabs(t1);
	t2 = fabs(t2); */

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
