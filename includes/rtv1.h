/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:13:44 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/06 21:33:52 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define W_W 600
# define W_H 600
# define M_W 300
# define M_H 300

typedef struct  s_vec3
{
	double      x;
	double      y;
	double      z;
}               t_vec3;

typedef struct  s_vec2
{
	double      x;
	double      y;
}               t_vec2;

typedef struct  s_obj
{
	t_vec3      dot;
	t_vec3		oc;
	double		radius;
	int			color;
	double		inten;
}				t_obj;

typedef struct  s_rt
{
	void		*mlx_ptr;
	void		*win_ptr;

	t_vec3		cam;
	t_vec3		move;
	t_obj		light;
	double		res;
	int			color;
}               t_rt;

double  vec_sc(t_vec3 a, t_vec3 b);
t_vec3 vec_mul(t_vec3 a, double n);
t_vec3 vec_plus(t_vec3 a, t_vec3 b);
t_vec3  vec_minus(t_vec3 a, t_vec3 b);
t_vec3 vec_div(t_vec3 a, double n);
double vec_mod_div(t_vec3 a, t_vec3 b);
double vec_modul(t_vec3 a);

#endif