/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:45:05 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 19:39:34 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char			get_rgb_color(double ia, char color, double ia_left)
{
	unsigned int	color_rgb;
	double			c_rgb;

	color_rgb = (unsigned int)color >> 24;
	c_rgb = (((double)(color_rgb) * (ia)));
	color_rgb = (unsigned int)c_rgb;
	if (color_rgb > 255)
		color_rgb = 255;
	if ((255 - color_rgb) > (int)ia_left)
		color_rgb += ia_left;
	else
		color_rgb = (char)255;
	color = (char)color_rgb;
	return (color);
}

int				get_color(double ia, t_obj obj)
{
	double ia_left;

	ia_left = 0;
	if (ia > 1)
	{
		ia_left = (ia - 1.00000) / 3.0000;
		ia_left *= 255;
		ia = 1.00000;
	}
	obj.col.rgb.r = get_rgb_color(ia, obj.col.rgb.r, ia_left);
	obj.col.rgb.g = get_rgb_color(ia, obj.col.rgb.g, ia_left);
	obj.col.rgb.b = get_rgb_color(ia, obj.col.rgb.b, ia_left);
	return (obj.col.value);
}

double			compute_shadows(t_rt *rt, t_obj *obj, double sc, t_vec3 p)
{
	int		i;
	double	temp;

	i = 0;
	while (i < rt->obj_number)
	{
		if (i != rt->index && rt->objects[i].type == 0)
		{
			rt->objects[i].oc = vec_minus(rt->objects[i].dot, p);
			temp = rt->objects[i].func(&rt->objects[i], rt);
			if (temp != -1 && (fabs(temp) < vec_modul(rt->dir)))
				sc = -1.000;
		}
		i++;
	}
	return (sc);
}

double			get_light(t_obj *obj, t_rt *rt, t_obj light)
{
	double sc;
	double ia;
	double ia_left;
	t_vec3 n_n;
	t_vec3 l_n;

	ia = 0.000000;
	ia_left = 0.000000;
	obj->p = vec_plus(rt->cam, vec_mul(rt->dir, rt->res));
	obj->n = vec_minus(obj->dot, obj->p);
	n_n = vec_div(obj->n, vec_modul(obj->n));
	obj->l = vec_minus(obj->p, light.dot);
	l_n = vec_div(obj->l, vec_modul(obj->l));
	sc = vec_sc(n_n, l_n);
	ia_left = 0.0000000;
	rt->dir = vec_minus(obj->p, light.dot);
	sc = compute_shadows(rt, obj, sc, obj->p);
	if (sc > -0.000001)
	{
		ia = light.inten * (sc / (vec_modul(obj->l) * vec_modul(n_n)));
		obj->v = vec_minus(obj->p, rt->cam);
	}
	ia += rt->amb;
	return (ia);
}
