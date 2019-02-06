/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:44:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/06 17:49:52 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  vec_sc(t_vec3 a, t_vec3 b)
{
    double s;

    s = a.x * b.x + a.y * b.y + a.z * b.z;
    return (s);
}

t_vec3 vec_plus(t_vec3 a, t_vec3 b)
{
    t_vec3 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return (c);
}

t_vec3 vec_mul(t_vec3 a, double n)
{
    t_vec3 c;

    c.x = a.x * n;
    c.y = a.y * n;
    c.z = a.z * n;
    return (c);
}