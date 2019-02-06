/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/06 21:33:20 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int ray (int j, int i, t_obj *obj, t_rt *rt)
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
	if(desc < 0)
		return (0);

	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (k2 + sqrt(desc)) / (2 * k1);

	double res = -1;
	if (t1 >= 1 && t1 <= INFINITY)
		res = t1;
	if (res >= 0)
	{
		if (t2 >=1 && t2<= INFINITY && t2 < res)
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
	int color;

	t_vec3 c;
	c.x = (j * 1.0 - 300.0) / 600.0;
	c.y = (i * 1.0 - 300.0) / 600.0;
	c.z = 1;

	t_vec3 d; //направление вектора луча
	d = vec_minus(c, rt.cam);

	t_vec3 p; //точка
	p = vec_plus(rt.cam, vec_mul(d, rt.res));

	t_vec3 n; //нормаль
	n = vec_div(vec_minus(p, obj.dot), vec_mod_div(p, obj.dot));

	t_vec3 l; //направляющий вектор луча света
	l = vec_minus(rt.light.dot, p);

	double sc; // cкаляр
	sc = vec_sc(n, l);

	double	ia; // i / a
	if (sc > 0)
	{
		ia = sc / (vec_modul(l) * vec_modul(n));
		rt.color = (double)rt.color * ia;
	}
	return (rt.color);
}

void	rtv1(t_rt *rt)
{
	int i;
	int j;
	int r;
	int res;
	int res0;
	int k;

	t_obj s;
	s.dot.x = 0;
	s.dot.y = 0;
	s.dot.z = 10;
	s.radius = 1;
	s.color = 0x0000ff;
	//s.oc = vec_plus(s.dot, vec_mul(rt->cam, -1));

	/* t_obj s1;
	s1.dot.x = 1;
	s1.dot.y = 1;
	s1.dot.z = 20;
	s1.radius = 1;
	s1.color = 0xff0000;

	t_obj s2;
	s2.dot.x = 0;
	s2.dot.y = 0;
	s2.dot.z = 30;
	s2.radius = 10;
	s2.color = 0x00ff00; */

	rt->light.dot.x = -0.5;
	rt->light.dot.y = 0.5;
	rt->light.dot.z = 10;
	rt->light.inten = 0.2;

	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			rt->res = 1000000;
			int col;
			k = 0;
			while (k < 1)
			{
				if (k == 0)
				{
					res0 = ray(j, i, &s, rt);
					col = s.color;
				}
				// if (k == 1)
				// {
				// 	res0 = ray(j, i, &s1, rt);
				// 	col = s1.color;
				// }
				// if (k == 2)
				// {
				// 	res0 = ray(j, i, &s2, rt);
				// 	col = s2.color;	
				// }
				if (res0 > 1 && res0 < rt->res)
				{
					rt->res = res0;
					rt->color = col;
				}
				k++;
			}
			if (rt->res > 1 && rt->res < 1000000)
			{
				rt->color = get_light(s, i, j, *rt);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0xffffff);
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
		rt->move.x = 0;
		rt->move.y = 0.1;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 125)
	{
		rt->move.x = 0;
		rt->move.y = -0.1;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 123)
	{
		rt->move.x = 0.1;
		rt->move.y = 0;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 124)
	{
		rt->move.x = -0.1;
		rt->move.y = 0;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
		//printf("%lf %lf %lf \n", rt->cam.x, rt->cam.y, rt->cam.z);
	}
	if (key == 69)
	{
		rt->move.x = 0;
		rt->move.y = 0;
		rt->move.z = -0.1;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 78)
	{
		rt->move.x = 0;
		rt->move.y = 0;
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
