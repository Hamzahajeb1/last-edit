/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:00:50 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/15 22:27:41 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fract;

    if ((argc == 4 && ft_cmp(argv[1], "julia") == 0) || (argc == 2 && ft_cmp(argv[1], "mandelbrot") == 0))
    {
        fract.name = argv[1];
        if(ft_cmp(argv[1], "julia") == 0)
        {
        fract.j_x = ft_atof(argv[2]);
        fract.j_y = ft_atof(argv[3]);
        }
        
        ft_init(&fract);
        ft_render(&fract);
        mlx_loop(fract.mlx);
    }
    else
    {
        write(1, "args error!", 11);
        return (1);
    }
}