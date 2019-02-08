/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:41:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/08 13:47:00 by gkessler         ###   ########.fr       */
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
	obj->oc = vec_minus(rt->cam, obj->dot);
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	//t_vec3 oc;
	//oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	//printf("%lf %lf %lf\n", d.x, d.y, d.z);

	k1 = vec_sc(d, d);
	k2 = 2 * vec_sc(obj->oc, d);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);

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
