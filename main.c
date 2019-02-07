/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/07 16:59:11 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double ray (int j, int i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	obj->oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	//t_vec3 oc;
	//oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));

	t_vec3 d;
	d = vec_plus(l, vec_mul(rt->cam, -1));
	
	k1 = vec_sc(d, d);
	k2 = 2 * vec_sc(obj->oc, d);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (k2 + sqrt(desc)) / (2 * k1);

	double res = -1.0;
	if (t1 >= 1.0 && t1 <= INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 1.0 && t2<= INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >=1 && t2<= INFINITY)
			res = t2;
	}
	return (res);
}

int		get_light(t_obj obj, int i, int j, t_rt rt)
{
	int color_r;
	int color_g;
	int color_b;

	t_vec3 c;
	c.x = (j * 1.0 - 300.0) / 600.0;
	c.y = (i * 1.0 - 300.0) / 600.0;
	c.z = 1.0;

	t_vec3 null;
	null.x = 0.0;
	null.y = 0.0;
	null.z = 0.0;
	t_vec3 d; //направление вектора луча
	d = vec_minus(c, rt.cam);

	// d = vec_div(d, vec_modul(d));
	// printf("%lf %lf %lf\n", rt.cam.x, rt.cam.y, rt.cam.z);

	t_vec3 p; //точка
	p = vec_plus(null, vec_mul(d, rt.res));
	// printf("P - %lf %lf %lf\n", p.x, p.y, p.z);

	t_vec3 n; //нормаль
	n = vec_div(vec_minus(p, obj.dot), vec_mod_div(p, obj.dot));
	// printf("N - %lf %lf %lf\n", n.x, n.y, n.z);

	t_vec3 l; //вектор луча света
	l = vec_minus(p, rt.light.dot);
	// printf("L - %lf %lf %lf\n", l.x, l.y, l.z);

	double sc; // cкаляр
	sc = vec_sc(n, l);
	double	ia; // i / a

	if (sc > 0)
	{
		ia = sc / (vec_modul(l) * vec_modul(n)); 

		color_b = ((int)rt.color & 255) * ia;
		color_g = ((int)((((int)rt.color & 65280) >> 8) * ia) << 8);
		color_r = ((int)((((int)rt.color & 16711680) >> 16) * ia) << 16);
		//((int)rt.color & 16711680) * ia;

		rt.color = color_b | color_g | color_r;
	}
	else 
	{
		sc = 0;
		ia = 0;
		rt.color = rt.color * ia;
	}
	return (rt.color);
}

void	rtv1(t_rt *rt)
{
	int i;
	int j;
	int r;
	double res;
	double res0;
	int k;

	t_obj s;
	s.dot.x = -2.0;
	s.dot.y = -2.0;
	s.dot.z = 10.0;
	s.radius = 1.0;
	s.color = 0x00ff00;
	//s.oc = vec_plus(s.dot, vec_mul(rt->cam, -1));

	t_obj s1;
	s1.dot.x = -0.0;
	s1.dot.y = -0.0;
	s1.dot.z = 10.0;
	s1.radius = 1.0;
	s1.color = 0xff0000;

	t_obj s2;
	s2.dot.x = 3.0;
	s2.dot.y = 3.0;
	s2.dot.z = 10.0;
	s2.radius = 1.0;
	s2.color = 0x0000ff;

	rt->light.dot.x = 0.0;
	rt->light.dot.y = 0.0;
	rt->light.dot.z = 5.0;
	rt->light.inten = 0.5;

	t_obj o;

	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			rt->res = 1000000;
			double col;
			k = 0;
			while (k < 3)
			{
				if (k == 0)
				{
					res0 = ray(j, i, &s1, rt);
					col = s1.color;
					o = s1;
				}
				 if (k == 1)
				 {
				 	res0 = ray(j, i, &s, rt);
				 	col = s.color;
					o = s;
				 }
				 if (k == 2)
				 {
					res0 = ray(j, i, &s2, rt);
					col = s2.color;
					o = s2;
				}
				if (res0 > 1.0 && res0 < rt->res)
				{
					rt->res = res0;
					rt->color = col;
					rt->obj = o;
				}
				k++;
			}
			if (rt->res > 1.0 && rt->res < 1000000.0)
			{
				rt->color = get_light(rt->obj, i, j, *rt);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

int		exit_x(int a)
{
	exit(a);
}

int		deal_key(int key, t_rt *rt)
{
	if (key == 126)
	{
		rt->move.x = 0.0;
		rt->move.y = 0.1;
		rt->move.z = 0.0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 125)
	{
		rt->move.x = 0.0;
		rt->move.y = -0.1;
		rt->move.z = 0.0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 123)
	{
		rt->move.x = 0.1;
		rt->move.y = 0.0;
		rt->move.z = 0.0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 124)
	{
		rt->move.x = -0.1;
		rt->move.y = 0.0;
		rt->move.z = 0.0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 69)
	{
		rt->move.x = 0.0;
		rt->move.y = 0.0;
		rt->move.z = -0.1;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 78)
	{
		rt->move.x = 0.0;
		rt->move.y = 0.0;
		rt->move.z = 0.1;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 53)
		exit_x(1);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	rtv1(rt);
	return (0);
}

int		main()
{
	t_rt *rt;

	if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
		exit_x(1);
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, W_W, W_H, "RTv1");

	rt->cam.x = 0.0;
	rt->cam.y = 0.0;
	rt->cam.z = 0.0;
	rtv1(rt);
	mlx_hook(rt->win_ptr, 2, 0, deal_key, rt);
	mlx_hook(rt->win_ptr, 17, 0, exit_x, rt);
	mlx_loop(rt->mlx_ptr);
	return (0);
}
