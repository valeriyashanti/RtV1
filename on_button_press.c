/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:51:58 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 17:22:38 by gkessler         ###   ########.fr       */
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
}

int    on_button_press_2(int key, t_rt *rt)
{
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
	if (key == 24 && rt->amb < 1.0000)
		rt->amb += 0.05;
	if (key == 27 && rt->amb > 0.05)
		rt->amb -= 0.05;
	if (key == 53)
		exit(1);
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
