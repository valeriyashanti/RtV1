/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:44:13 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 15:44:23 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		compute_specular(t_vec3 n, t_vec3 l, double ia, t_vec3 v, double s)
{
	t_vec3 r;
	t_vec3 l_n;
	t_vec3 l_p;

	l_n = vec_mul(n, vec_sc(n, l));
	l_p = vec_minus(l, l_n);
	r = vec_minus(l_n, l_p);

	if (vec_sc(r,v) > 0)
		ia = (pow((vec_sc(r, v) / (vec_modul(r) * vec_modul(v))), s) *  ia);
	return (ia);
}
