/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:18:42 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 16:54:01 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_cam(char *line, t_rt *rt)
{
	char	*tmp;
	double	num[6];
	int		i;

	i = 0;
	tmp = strchr(line, ':');
	while (*tmp)
	{
		if (*tmp >= '0' && *tmp <= '9')
		{
			num[i] = (double)ft_atoi(tmp);
			tmp += strlen(ft_itoa(num[i]));
			i++;
		}
		if (*tmp)
			tmp++;
	}
	rt->cam.x = num[0] / 10.0;
	rt->cam.y = num[1] / 10.0;
	rt->cam.z = num[2] / 10.0;
	rt->rot_xy = num[3] / 10.0;
	rt->rot_yz = num[4] / 10.0;
	rt->rot_xz = num[5] / 10.0;
}

int			parse_light(char *line, t_rt *rt, int light_index)
{
	char	*tmp;
	double	num[4];
	int		i;

	i = 0;
	tmp = strchr(line, ':');
	while (*tmp)
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
	rt->light[light_index].dot.x = num[0] / 10.0;
	rt->light[light_index].dot.y = num[1] / 10.0;
	rt->light[light_index].dot.z = num[2] / 10.0;
	rt->light[light_index].inten = num[3] / 10.0;
	rt->light[light_index].type = 1;
	rt->light[light_index + 1].type = 0;
	return (light_index + 1);
}

void		parse_ambient(char *line, t_rt *rt)
{
	line = ft_strchr(line, ':');
	rt->amb = ft_atoi(line + 1) / 100.0;
}

int			parse_string(char *line, t_rt *rt)
{
	static int	index = 0;
	static int	light_index = 0;
	int			type;

	type = -1;
	if (!(ft_strncmp(line, "cam", strclen(line, ':'))))
		parse_cam(line, rt);
	if (!(ft_strncmp(line, "light", strclen(line, ':'))))
		light_index = parse_light(line, rt, light_index);
	if (!(ft_strncmp(line, "ambient", strclen(line, ':'))))
		parse_ambient(line, rt);
	if ((type = define_object(line, rt)) >= 0)
		index = parse_object(line, rt, index, type);
	rt->obj_number = index;
	return (0);
}

int			parser(char *file, t_rt *rt)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
		parse_string(line, rt);
	close(fd);
	return (0);
}
