/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:45:05 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 19:16:57 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_color(double ia_left, double ia, t_obj obj)
{
		unsigned int c_b = (unsigned int)obj.col.rgb.b >> 24;
		double c_b_d;
		c_b_d = (((double)(c_b) * (ia)));
		c_b = (unsigned int)c_b_d;
		if  (c_b > 255)
			c_b = 255;
		if ((255 - c_b) > (int)ia_left)
			c_b += ia_left;
		else
			c_b = (char)255;
		obj.col.rgb.b = (char)c_b;


		unsigned int c_r = (unsigned int)obj.col.rgb.r >> 24;
		double c_r_d;
		c_r_d = (((double)(c_r) * ia));
		c_r = (unsigned int)c_r_d;
		if  (c_r > 255)
			c_r = 255;
		if ((255 - c_r) > (int)ia_left)
			c_r += ia_left;
		else
			c_r = (char)255;
		obj.col.rgb.r = (char)c_r;


		unsigned int c_g = (unsigned int)obj.col.rgb.g >> 24;
		double c_g_d;
		c_g_d = (((double)(c_g) * ia));
		c_g = (unsigned int)c_g_d;
		if  (c_g > 255)
			c_g = 255;
		if ((255 - c_g) > (int)ia_left)
			c_g += ia_left;
		else
			c_g = (char)255;
		obj.col.rgb.g = (char)c_g;
	return (obj.col.value);
}




int		get_light(t_obj *obj, t_rt *rt)
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
	l = vec_minus(p, rt->light.dot);

	t_vec3 l_n;
	l_n = vec_div(l, vec_modul(l));


	double sc; // cкаляр
	sc = vec_sc(n_n, l_n);
	double	ia ; // i / a
	double ia_left = 0.0000000;




	//obj->oc = vec_minus(p, c_z);

	rt->dir = vec_minus(rt->light.dot, p);
	rt->dir = vec_div(rt->dir, vec_modul(rt->dir));
	int i = 0;
	while (i < 7)
	{
		if (i != rt->index && rt->objects[i].type == 0)
		{
			rt->objects[i].oc = vec_minus(p, rt->objects[i].dot);
			if (rt->objects[i].func(&rt->objects[i], rt) != -1)
				sc = -1.000;
		}
		i++;
	}


/* 	if (obj->radius == 0.3)
	{
		rt->dir = vec_minus(rt->light.dot, p);
		rt->dir = vec_div(rt->dir, vec_modul(rt->dir));
		rt->objects[0].oc = vec_minus(p, c_z);
		if (ray_sphere(&rt->objects[0], rt) != -1)
			sc = -1.000;
	}
 */










	if (sc > -0.00001)
	{
		ia = rt->light.inten * (sc / (vec_modul(l) * vec_modul(n_n)));
		t_vec3 v;
		v = vec_minus(p, rt->cam);
		//ia = compute_specular(n_n, l, ia, v, obj->specular);
		ia += rt->amb;
		if (ia > 1)
		{
			ia_left = (ia - 1.00000) / 3.0000;
			ia_left *= 255;
			ia = 1.00000;
		}
	}
	else
		ia += rt->amb;
	return (get_color(ia_left, ia, *obj));
}
