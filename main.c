/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/09 16:00:09 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


double char_to_double(char c)
{
	double n = 0.0;
	int tmp;
	int i = 0;
	while (i < 8)
	{
		tmp = pow(2, i);
		tmp = (c & (1 << i)) * tmp;
		n+= (double)tmp;
		i++;
	}
	return (n);
}

double 		ray_sphere(int j, int i, t_obj *obj, t_rt *rt)
{
	t_vec3 l;
	l.x = (j * 1.0 - 300.0) / 600.0;
	l.y = (i * 1.0 - 300.0) / 600.0;
	l.z = 1;

	//obj->oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));
	obj->oc = vec_minus(rt->cam, obj->dot);
	double k1;
	double k2;
	double k3;

	double t1;
	double t2;

	//t_vec3 oc;
	//oc = vec_plus(obj->dot, vec_mul(rt->cam, -1));

	t_vec3 d;
	d = vec_minus(l, rt->cam); 
	//printf("%lf %lf %lf\n", d.x, d.y, d.z);
	d = vec_div(d, vec_modul(d));



	k1 = vec_sc(d, d);
	k2 = 2 * vec_sc(obj->oc, d);
	k3 = vec_sc(obj->oc, obj->oc) - (obj->radius * obj->radius);

	double desc = k2 * k2 - 4 * k1 * k3;
	if(desc < 0.0)
		return (-1.0);
	t1 = (-k2 + sqrt(desc)) / (2 * k1);
	t2 = (-k2 - sqrt(desc)) / (2 * k1);

	/* t1 = fabs(t1);
	t2 = fabs(t2); */

	double res = INFINITY;
	if (t1 >= 1.0 && t1 < INFINITY)
		res = t1;
	if (res >= 0.0)
	{
		if (t2 >= 1.0 && t2 < INFINITY && t2 < res)
			res = t2;
	}
	else
	{
		if (t2 >=1 && t2 < INFINITY)
			res = t2;
	}
// printf("t1: %lf, t2: %lf , res: %lf \n", t1, t2, res);
	return (res);
}


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

	printf("ia - %lf\n", ia);
	return (ia);
}

int		get_light(t_obj obj, int i, int j, t_rt rt)
{
	/* int color_r;
	int color_g;
	int color_b; */
	t_vec3 c;
	c.x = (j * 1.0 - 300.0) / 600.0;
	c.y = (i * 1.0 - 300.0) / 600.0;
	c.z = 1.0;

	t_vec3 null;
	null.x = 0.0;
	null.y = 0.0;
	null.z = 0.0;

	t_vec3 d; //направление вектора луча
	d = vec_minus(c, rt.cam); // O - C

	//printf("%lf %lf %lf\n", d.x, d.y, d.z);

	t_vec3 p; //точка
	p = vec_plus(rt.cam, vec_mul(d, rt.res));
	//printf("%lf %lf %lf\n", p.x, p.y, p.z);

	t_vec3 n; //нормаль
	n = vec_minus(obj.dot, p);
	t_vec3 n_n;
	n_n = vec_div(n, vec_modul(n));
	//printf("%lf %lf %lf\n", n.x, n.y, n.z);

	t_vec3 l; //вектор луча света
	l = vec_minus(p, rt.light.dot);

	t_vec3 l_n;
	l_n = vec_div(l, vec_modul(l));


	double sc; // cкаляр
	sc = vec_sc(n, l);
	//printf("sc -- %lf\n", sc);
	double	ia ; // i / a
	
	if (sc > 0)
	{
		ia = (sc / (vec_modul(l) * vec_modul(n)));
		t_vec3 v;
		v = vec_minus(p, rt.cam);
		// s1.col.rgb.r = 0xff;
		// printf("ia -- %lf\n", ia);
		//ia = compute_specular(n, l, ia, v, obj.specular);
 
		/* unsigned int c_b = (unsigned int)obj.col.rgb.b >> 24;
		double c_b_d;
		c_b_d = (((double)(c_b) * (ia)));
		c_b = (unsigned int)c_b_d;
		obj.col.rgb.b = (char)c_b;

		unsigned int c_r = (unsigned int)obj.col.rgb.r >> 24;
		double c_r_d;
		c_r_d = (((double)(c_r) * ia));
		c_r = (unsigned int)c_r_d;
		obj.col.rgb.r = (char)c_r;


		unsigned int c_g = (unsigned int)obj.col.rgb.g >> 24;
		double c_g_d;
		c_g_d = (((double)(c_g) * ia));
		c_g = (unsigned int)c_g_d;
		obj.col.rgb.g = (char)c_g;

		rt.color = obj.col.value; */

		// obj.col.rgb.g = (((int)(obj.col.rgb.g) * ia));

		// obj.col.rgb.r = (((int)(obj.col.rgb.r) * c));

		// obj.col.value = obj.col.value / 10000;

		// printf("%fl\n", (((double)(int)(obj.col.rgb.b) * ia)));
		// printf("%p\n", obj.col.rgb.g);
		// printf("%p\n", obj.col.rgb.r);
		// printf("%p %p %p\n",obj.col.rgb.b, obj.col.rgb.g, obj.col.rgb.r );
		// color_b = (rt.color & 255) * ia;
		// color_g = ((int)(((rt.color & 65280) >> 8) * ia) << 8);
		// color_r = ((int)(((rt.color & 16711680) >> 16) * ia) << 16);
		// rt.color = (color_b | color_g | color_r);
		
	}
	else
	{
		ia = 0;
	}	//rt.color = 0;

		//ia += 0.2; 
	
		unsigned int c_b = (unsigned int)obj.col.rgb.b >> 24;
		double c_b_d;
		c_b_d = (((double)(c_b) * (ia)));
		c_b = (unsigned int)c_b_d;
		obj.col.rgb.b = (char)c_b;

		unsigned int c_r = (unsigned int)obj.col.rgb.r >> 24;
		double c_r_d;
		c_r_d = (((double)(c_r) * ia));
		c_r = (unsigned int)c_r_d;
		obj.col.rgb.r = (char)c_r;


		unsigned int c_g = (unsigned int)obj.col.rgb.g >> 24;
		double c_g_d;
		c_g_d = (((double)(c_g) * ia));
		c_g = (unsigned int)c_g_d;
		obj.col.rgb.g = (char)c_g;

		rt.color = obj.col.value;
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
	s.dot.x = -3.0;
	s.dot.y = -3.0;
	s.dot.z = 13.0;
	s.radius = 1.0;
	s.col.value = 0x00ff00;
	s.specular = 1.0;

	t_obj s1;
	s1.dot.x = 0.0;
	s1.dot.y = 0.0;
	s1.dot.z = 3.0;
	s1.radius = 0.3;
	s1.col.value = 0x0fff00;
	s1.specular = 1.0;

	t_obj cone;
	cone.dot.x = 0.0;    
	cone.dot.y = 0.0;
	cone.dot.z = 4.0;
	cone.col.value = 0x0000ff;
	cone.specular = 0.1;
	cone.reflective = 0.5;
	cone.a = 1;
	cone.b = 1.5;
	cone.c = 1;

	t_obj roll;
	roll.dot.x = 0.0;    
	roll.dot.y = 0.0;
	roll.dot.z = 4.0;
	roll.col.value = 0x0000ff;
	roll.specular = 0.1;
	roll.reflective = 0.5;
	roll.a = 0.5;
	roll.b = 1;

	t_obj pl_left;
	pl_left.radius = -1.0;
	pl_left.col.value = 0xff0000;
	pl_left.specular = 0.1;
	pl_left.reflective = 0.5;

	t_obj pl_right;
	pl_right.radius = 1.0;
	pl_right.col.value = 0x0000ff;
	pl_right.specular = 0.1;
	pl_right.reflective = 0.5;

	t_obj pl_up;
	pl_up.radius = -1.0;
	pl_up.col.value = 0x00ffff;
	pl_up.specular = 0.1;
	pl_up.reflective = 0.5;

	t_obj pl_down;
	pl_down.radius = 1.0;
	pl_down.col.value = 0xffff00;
	pl_down.specular = 0.1;
	pl_down.reflective = 0.5;

	t_obj wall;
	wall.radius = 7.0;
	wall.col.value = 0xff00ff;
	wall.specular = 0.1;
	wall.reflective = 0.5;

// light

	rt->light.dot.x = 0.0;
	rt->light.dot.y = 0.0;
	rt->light.dot.z = 1.0;
	rt->light.inten = 0.8;

	t_obj o;

	i = 0;
	while (i < W_H)
	{
		j = 0;
		while (j < W_W)
		{
			rt->res = INFINITY;
			int col;
			k = 0;
			while (k <= 5)
			{
				if (k == 0)
				{
					res0 = ray_plane_x(j, i, &pl_left, rt);
					col = pl_left.col.value;
					o = pl_left;
					// res0 = ray(j, i, &s, rt);
					// col = s.col.value;
					// o = s;
				}
				if (k == 1)
				{
				 	res0 = ray_plane_y(j, i, &pl_down, rt);
					col = pl_down.col.value;
					o = pl_down;
				}
				if (k == 2)
				 {
					res0 = ray_sphere(j, i, &s1, rt);
					col = s1.col.value;
					o = s1;
				}
				if (k == 3)
				{
					res0 = ray_plane_x(j, i, &pl_right, rt);
					col = pl_right.col.value;
					o = pl_right;
				}
				if (k == 4)
				{
					res0 = ray_plane_y(j, i, &pl_up, rt);
					col = pl_up.col.value;
					o = pl_up;
				}
				if (k == 5)
				{
					res0 = ray_plane_z(j, i, &wall, rt);
					col = wall.col.value;
					o = wall;
				}
				if (res0 > 1.0 && res0 < rt->res)
				{
					rt->res = res0;
					rt->color = col;
					rt->obj = o;
				}
				
				k++;
			}
			// if (rt->res != INFINITY)
			// 	printf("res: %lf \n", rt->res);
			if (rt->res > 1.0 && rt->res < INFINITY)
			{
				rt->color = get_light(rt->obj, i, j, *rt);
				//printf("rt->color : %lf\n", rt->color);
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, rt->color);
			}
			/* else
				mlx_pixel_put(rt->mlx_ptr, rt->win_ptr, j, i, 0xffffff); */
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
