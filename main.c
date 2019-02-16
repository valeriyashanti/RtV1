/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:26 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/16 21:46:58 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_main(t_rt *rt)
{
	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, W_W, W_H, "RTv1");
}

int		ft_error(char *line)
{
	ft_putendl(line);
	exit(0);
}

int		main(int ac, char **av)
{
	t_rt *rt;

	if (ac == 2)
	{
		if (!(rt = (t_rt*)malloc(sizeof(t_rt))))
			exit(1);
		parser(av[1], rt);
		if (rt->light[0].type == 0)
			ft_error("No light is scene :(");
		init_main(rt);
		rtv1(rt);
		mlx_hook(rt->win_ptr, 2, 0, deal_key, rt);
		mlx_hook(rt->win_ptr, 17, 0, exit_x, rt);
		mlx_loop(rt->mlx_ptr);
	}
	else
		ft_error("No file appeared :(");
	return (0);
}
