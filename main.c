/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/06 18:25:08 by gkessler         ###   ########.fr       */
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

	//t_vec3 d;
	//d = vec_plus(l, rt->cam);
	
	k1 = vec_sc(l, l);
	k2 = 2 * vec_sc(obj->oc, l);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0)
		return (0);

	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (k2 + sqrt(desc)) / (2 * k1);

	double res = -1;
	
	if(t1>=1 && t1<= INFINITY)
		res = t1;
	if (res >= 0)
	{
		if(t2 >=1 && t2<= INFINITY && t2 <res)
			res = t2;
	}
	else
	{
		if(t2 >=1 && t2<= INFINITY)
			res = t2;
	}
	if (res != -1)
		return (1);
	return (0);
}

void	rtv1(t_rt *rt)
{
	int i;
	int j;
	int r;

	t_obj s;
	s.dot.x = 0;
	s.dot.y = 0;
	s.dot.z = 10;
	s.radius = 1;
	//s.oc = vec_plus(s.dot, vec_mul(rt->cam, -1));

	t_obj s1;
	s1.dot.x = 1;
	s1.dot.y = 1;
	s1.dot.z = 20;
	s1.radius = 1;

	t_obj s2;
	s2.dot.x = 2;
	s2.dot.y = 3;
	s2.dot.z = 15;
	s2.radius = 1;

	i = 0;

	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			r = 0;
			if (ray(j, i, &s, rt))
			{
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0x0000ff);
				r = 1;
			}
			if (ray(j, i, &s1, rt))
			{
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0xff0000);
				r = 1;
			}
			if (ray(j, i, &s2, rt))
			{
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0x00ff00);
				r = 1;
			}
			else if (r == 0)
			{
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0xffffff);
			}
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
	/* if (key == 126)
	{
		rt->move.x = 20;
		rt->move.y = 0;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
		printf("%lf %lf %lf \n", rt->cam.x, rt->cam.y, rt->cam.z);
	}
	if (key == 125)
	{
		rt->move.x = -20;
		rt->move.y = 0;
		rt->move.z = 0;
		rt->cam = vec_plus(rt->cam, rt->move);
		printf("%lf %lf %lf \n", rt->cam.x, rt->cam.y, rt->cam.z);
	}
	if (key == 123)
	{
		rt->move.x = 0;
		rt->move.y = 0;
		rt->move.z = 20;
		rt->cam = vec_plus(rt->cam, rt->move);
		printf("%lf %lf %lf \n", rt->cam.x, rt->cam.y, rt->cam.z);
	}
	if (key == 124)
	{
		rt->move.x = 0;
		rt->move.y = 0;
		rt->move.z = -20;
		rt->cam = vec_plus(rt->cam, rt->move);
		printf("%lf %lf %lf \n", rt->cam.x, rt->cam.y, rt->cam.z);
	} */
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
