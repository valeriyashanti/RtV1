/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:41:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 21:33:38 by drestles         ###   ########.fr       */
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

	// это поворот
	// t_vec3 temp_d;
	// temp_d = d;

	// d.x = temp_d.x * cos(0.5) - temp_d.y * sin(0.5);
	// d.y = temp_d.x * sin(0.5) + temp_d.y * cos(0.5);


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
	return (res);
}
