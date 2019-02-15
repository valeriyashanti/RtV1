/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:18:42 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/15 15:06:41 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse_cam(char *line, t_rt *rt)
{
	char *tmp;
	double num[6];
	int     i; 
    
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

void	parse_light(char *line, t_rt *rt)
{
	char *tmp;
	double num[4];
	int i;
    
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
	rt->light.dot.x = num[0] / 10.0;
	rt->light.dot.y = num[1] / 10.0;
	rt->light.dot.z = num[2] / 10.0;
	rt->light.inten = num[3] / 10.0;
}

void	parse_ambient(char *line, t_rt *rt)
{
	if (line)
		rt->amb = ft_atoi(line);
}

int		parse_string(char *line, t_rt *rt)
{
	static int index = 0;
	int type;

	type = -1;
	if (!(ft_strncmp(line, "cam", strclen(line, ':'))))
		parse_cam(line, rt);
	if (!(ft_strncmp(line, "light", strclen(line, ':'))))
		parse_light(line, rt);
	if (!(ft_strncmp(line, "ambient", strclen(line, ':'))))
		parse_ambient(line, rt);
	if ((type = define_object(line, rt)) >= 0)
		index = parse_object(line, rt, index, type);
	rt->obj_number = index;
	return (0);
}

int		parser(char *file, t_rt *rt)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	
	while ((get_next_line(fd, &line) > 0))
	{
		parse_string(line, rt);
	}
	close(fd);
	return (0);
}
