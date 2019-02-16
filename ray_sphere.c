/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:41:51 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 21:27:48 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ray_sphere(t_obj *obj, t_rt *rt)
{
	double k1;
	double k2;
	double k3;

	k1 = vec_sc(rt->dir, rt->dir);
	k2 = 2.0 * vec_sc(obj->oc, rt->dir);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);
	return (calc_res(k1, k2, k3));
}
