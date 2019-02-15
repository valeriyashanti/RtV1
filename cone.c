/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:41:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 15:41:09 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double      ray_cone(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	t_vec3 rotation;
	rotation = rt->dir;
	rt->dir.x = rotation.x * cos(0.5) - rotation.y * sin(0.5);
	rt->dir.y = rotation.x * sin(0.5) + rotation.y * cos(0.5);

	obj->a = 1;
	obj->b = 1;
	obj->c = 1;


    k1 = ((rt->dir.z * rt->dir.z * obj->a * obj->a * obj->b * obj->b) 
	+ (rt->dir.x * rt->dir.x * obj->c* obj->c * obj->b * obj->b)
	- (rt->dir.y * rt->dir.y * obj->a * obj->a * obj->c * obj->c));


	k2 = 2 * ((rt->dir.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)
	+ (rt->dir.x * obj->oc.x * obj->c * obj->c * obj->b * obj->b)
	- (rt->dir.y * obj->oc.y * obj->a * obj->a * obj->c * obj->c));


	k3 = (obj->oc.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)
	+ (obj->oc.x * obj->oc.x * obj->c * obj->c * obj->b * obj->b)
	- (obj->oc.y * obj->oc.y * obj->a * obj->a * obj->c * obj->c);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	double res = INFINITY;
	if (t1 >= 0.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 0.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >= 0.0  && t2 < INFINITY)
			res = t2;
	}
	//printf("%lf\n", res);
	return (res);
}
