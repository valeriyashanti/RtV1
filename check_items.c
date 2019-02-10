/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:05:49 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/10 15:38:00 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int        check_items(t_rt *rt, int j, int  i, struct  s_obj *obj)
{
    int i;

    i = 0;
    while (i < 10)
    {
        if (rt->objects[i].func(obj, rt))
            return (-1);
        i++;
    }
}