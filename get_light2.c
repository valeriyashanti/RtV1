/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:22:16 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 15:06:49 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		get_light2(t_obj *obj, t_rt *rt)
{
	// t_vec3 d; //направление вектора луча
	// d = vec_minus(rt->init, rt->cam);

	// d = vec_div(d, vec_modul(d));
	t_vec3 p; //точка
	p = vec_plus(rt->cam, vec_mul(rt->dir, rt->res));

	t_vec3 n; //нормаль
	n = vec_minus(obj->dot, p); 

	t_vec3 n_n;
	n_n = vec_div(n, vec_modul(n));

	t_vec3 l; //вектор луча света
	l = vec_minus(p, rt->light1.dot);

	t_vec3 l_n;
	l_n = vec_div(l, vec_modul(l));

	double sc; // cкаляр
	sc = vec_sc(n_n, l_n);
	double	ia ; // i / a
	double ia_left = 0.0000000;
	//obj->oc = vec_minus(p, c_z);

	rt->dir = vec_minus(p, rt->light1.dot);
	rt->dir = vec_div(rt->dir, vec_modul(rt->dir));

	int i = 0;
	while (i < rt->obj_number)
	{
		if (i != rt->index && rt->objects[i].type == 0)
		{
			rt->objects[i].oc = vec_minus(p, rt->objects[i].dot);
			if (rt->objects[i].func(&rt->objects[i], rt) != -1)
				sc = -1.000;
		}
		i++;
	}
	if (sc > -0.00001)
	{
		ia = rt->light1.inten * (sc / (vec_modul(l) * vec_modul(n_n)));
		t_vec3 v;
		v = vec_minus(p, rt->cam);
		ia += compute_specular(n_n, l, ia, v, obj->specular);
	}
	ia += rt->amb;

	//ia += get_light_2(obj, rt);
	return (ia);
}
