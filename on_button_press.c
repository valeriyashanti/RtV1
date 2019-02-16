/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:51:58 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 19:10:34 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		exit_x(int a)
{
	exit(a);
}

void    on_button_press(int key, t_rt *rt)
{
	if (key == 126)
	{
		rt->move.x = 0.0000000;
		rt->move.y = 0.10000000;
		rt->move.z = 0.0000000;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 125)
	{
		rt->move.x = 0.0000000;
		rt->move.y = -0.1000000;
		rt->move.z = 0.000000;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 123)
	{
		rt->move.x = 0.100000000;
		rt->move.y = 0.000000000;
		rt->move.z = 0.0000000000;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 124)
	{
		rt->move.x = -0.100000000;
		rt->move.y = 0.0000000000;
		rt->move.z = 0.000000000;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 13)
		rt->light.dot.y += 0.1;
	if (key == 1)
		rt->light.dot.y -= 0.1;
	if (key == 2)
		rt->light.dot.x += 0.1;
	if (key == 0)
		rt->light.dot.x -= 0.1;
	if (key == 15)
		rt->light.dot.z += 0.2;
	if (key == 3)
		rt->light.dot.z -= 0.2;
	//	printf("%lf %lf %lf\n", rt->light.dot.x, rt->light.dot.y, rt->light.dot.z);
}

int    on_button_press_2(int key, t_rt *rt)
{
	if (key == 69)
	{
		rt->move.x = 0.0;
		rt->move.y = 0.0;
		rt->move.z = 0.1;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 78 && rt->cam.z >= 0.1)
	{
		rt->move.x = 0.0;
		rt->move.y = 0.0;
		rt->move.z = -0.1;
		rt->cam = vec_plus(rt->cam, rt->move);
	}
	if (key == 24 && rt->amb < 1.0000)
		rt->amb += 0.05;
	if (key == 27 && rt->amb > 0.05)
		rt->amb -= 0.05;
	if (key == 47)
		rt->rot_xy += 0.1;
	if (key == 43)
		rt->rot_xy -= 0.1;
	if (key == 37)
		rt->rot_yz += 0.1;
	if (key == 40)
		rt->rot_yz -= 0.1;
	if (key == 31)
		rt->rot_xz += 0.1;
	if (key == 34)
		rt->rot_xz -= 0.1;
	if (key == 53)
		exit(1);
	// if (key == 18)
	// 	rt->objects[1].dot.x += 0.1;
	// if (key == 19)
	// 	rt->objects[1].dot.x -= 0.1;
	// if (key == 20)
	// 	rt->objects[1].dot.y += 0.1;
	// if (key == 21)
	// 	rt->objects[1].dot.y -= 0.1;
	// if (key == 23)
	// 	rt->objects[1].dot.z += 0.1;
	// if (key == 22)
	// 	rt->objects[1].dot.z -= 0.1;	
	return (0);
}

int		deal_key(int key, t_rt *rt)
{
	on_button_press(key, rt);
	on_button_press_2(key, rt);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
	rtv1(rt);
	return (0);
}
