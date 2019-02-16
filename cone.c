/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:41:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 16:46:35 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		ray_cone(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;
	t_vec3 rotation;

	rotation = rt->dir;
	rt->dir.x = rotation.x * cos(obj->a_xy * 0.5) -\
	rotation.y * sin(obj->a_xy * 0.5);
	rt->dir.y = rotation.x * sin(obj->a_xy * 0.5) +\
	rotation.y * cos(obj->a_xy * 0.5);
	obj->a = 1.0;
	obj->b = 1.0;
	obj->c = 1.0;
	k1 = ((rt->dir.z * rt->dir.z * obj->a * obj->a * obj->b * obj->b)
	+ (rt->dir.x * rt->dir.x * obj->c * obj->c * obj->b * obj->b)
	- (rt->dir.y * rt->dir.y * obj->a * obj->a * obj->c * obj->c));
	k2 = 2 * ((rt->dir.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)
	+ (rt->dir.x * obj->oc.x * obj->c * obj->c * obj->b * obj->b)
	- (rt->dir.y * obj->oc.y * obj->a * obj->a * obj->c * obj->c));
	k3 = (obj->oc.z * obj->oc.z * obj->a * obj->a * obj->b * obj->b)
	+ (obj->oc.x * obj->oc.x * obj->c * obj->c * obj->b * obj->b)
	- (obj->oc.y * obj->oc.y * obj->a * obj->a * obj->c * obj->c);
	return (calc_res(k1, k2, k3));
}
