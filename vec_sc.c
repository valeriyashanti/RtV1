/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_sc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:44:46 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/06 21:26:46 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  vec_sc(t_vec3 a, t_vec3 b) // (a, b)
{
    double s;

    s = a.x * b.x + a.y * b.y + a.z * b.z;
    return (s);
}

t_vec3 vec_plus(t_vec3 a, t_vec3 b) // a + b
{
    t_vec3 c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return (c);
}

t_vec3 vec_mul(t_vec3 a, double n) // a * n
{
    t_vec3 c;

    c.x = a.x * n;
    c.y = a.y * n;
    c.z = a.z * n;
    return (c);
}

t_vec3 vec_div(t_vec3 a, double n) // a / n
{
    t_vec3 c;

    c.x = a.x / n;
    c.y = a.y / n;
    c.z = a.z / n;
    return (c);
}

t_vec3  vec_minus(t_vec3 a, t_vec3 b) //a - b
{
    t_vec3 c;

    c = vec_plus(a, vec_mul(b, -1));
    return (c);
}

double vec_modul(t_vec3 a) // |a - b|
{
    return(sqrt(vec_sc(a, a)));
}

double vec_mod_div(t_vec3 a, t_vec3 b) // |a - b|
{
    t_vec3 c;

    c = vec_minus(a, b);
    return(sqrt(vec_sc(c, c)));
}