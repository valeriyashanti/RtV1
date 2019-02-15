/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:41:51 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 15:41:07 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double 		ray_sphere(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	double t1;
	double t2;
	
	k1 = vec_sc(rt->dir, rt->dir);
	k2 = 2 * vec_sc(obj->oc, rt->dir);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);

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
		if (t2 >= 0.0 && t2 < INFINITY)
			res = t2;
	}
	return (res);
}
