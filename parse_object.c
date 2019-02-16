/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:19:15 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 17:00:57 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			parse_current_obj(char *tmp, t_rt *rt, int index, int type)
{
	if (type == 0)
	{
		rt->objects[index].type = 0;
		rt->objects[index].func = &ray_sphere;
	}
	if (type == 1)
	{
		rt->objects[index].type = 0;
		rt->objects[index].a = ft_atoi(ft_strchr(tmp, 'a') + 1) / 10.0;
		rt->objects[index].func = &ray_roll;
	}
	if (type == 2)
	{
		rt->objects[index].type = 0;
		rt->objects[index].func = &ray_cone;
	}
}

void			parse_current_obj2(char *tmp, t_rt *rt, int index, int type)
{
	if (type == 3)
	{
		rt->objects[index].type = 1;
		rt->objects[index].func = &ray_plane_x;
	}
	if (type == 4)
	{
		rt->objects[index].type = 2;
		rt->objects[index].func = &ray_plane_y;
	}
	if (type == 5)
	{
		rt->objects[index].type = 3;
		rt->objects[index].func = &ray_plane_z;
	}
}

void			array_to_obj(t_rt *rt, int index, double num[7], char *tmp)
{
	rt->objects[index].dot.x = num[0] / 10.0;
	rt->objects[index].dot.y = num[1] / 10.0;
	rt->objects[index].dot.z = num[2] / 10.0;
	rt->objects[index].a_xy = num[3] / 10.0;
	rt->objects[index].a_xz = num[4] / 10.0;
	rt->objects[index].a_yz = num[5] / 10.0;
	rt->objects[index].radius = num[6] / 10.0;
	rt->objects[index].col.value = ft_atoi_base(tmp, 16);
}

int				parse_object(char *line, t_rt *rt, int index, int type)
{
	char		*tmp;
	double		num[7];
	int			i;

	i = 0;
	tmp = strchr(line, ':');
	while (i < 7 && *tmp)
	{
		if ((*tmp >= '0' && *tmp <= '9') || (*tmp == '-') || *tmp == '+')
		{
			num[i] = (double)ft_atoi(tmp);
			tmp += strlen(ft_itoa(num[i]));
			i++;
		}
		if (*tmp)
			tmp++;
	}
	array_to_obj(rt, index, num, tmp);
	parse_current_obj(tmp, rt, index, type);
	parse_current_obj2(tmp, rt, index, type);
	return (index + 1);
}

int				define_object(char *line, t_rt *rt)
{
	if (!(ft_strncmp(line, "sphere", strclen(line, ':'))))
		return (0);
	if (!(ft_strncmp(line, "roll", strclen(line, ':'))))
		return (1);
	if (!(ft_strncmp(line, "cone", strclen(line, ':'))))
		return (2);
	if (!(ft_strncmp(line, "plane_x", strclen(line, ':'))))
		return (3);
	if (!(ft_strncmp(line, "plane_y", strclen(line, ':'))))
		return (4);
	if (!(ft_strncmp(line, "plane_z", strclen(line, ':'))))
		return (5);
	return (-1);
}
