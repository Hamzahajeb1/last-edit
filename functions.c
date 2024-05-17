/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:01:03 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/15 22:26:42 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double  map(double num, double min1, double max1, double min2, double max2)
{
    return (max1 - min1) * (num - min2) / (max2 - min2) + min1;
}

t_comp  sum_comp(t_comp z1, t_comp z2)
{
    t_comp  j;

    j.r = z1.r + z2.r;
    j.i = z1.i + z2.i;
    return (j);
}

t_comp  sr_comp(t_comp z)
{
    t_comp  j;

    j.r = (z.r * z.r) - (z.i * z.i);
    j.i = 2 * z.r * z.i;
    return (j);
}