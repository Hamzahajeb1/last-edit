/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:01:10 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/15 22:27:07 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int handle_Key(int keysym, t_fractal *fract)
{
    if (keysym == XK_Escape)
        handle_close(fract);
    if (keysym == XK_Up)
    {
        fract->y_shift -= (0.5 * fract->zoom);
    }
    else if (keysym == XK_Down)
    {
        fract->y_shift += (0.5 * fract->zoom);
    }
    else if(keysym == XK_Right)
    {
        fract->x_shift -= (0.5 * fract->zoom);
    }
    else if (keysym == XK_Left)
    {
        fract->x_shift += (0.5 * fract->zoom);
    }
    else if (keysym == XK_backslash)
    {
        fract->iteration += 1;
    }
    else if (keysym == XK_minus)
    {
        fract->iteration -= 1;
    }
    ft_render(fract);
    return (0);
}

int handle_mouse(int b, int x, int y, t_fractal *fract)
{
    (void)x;
    (void)y;
    if (b == Button5)
    {
        fract->zoom *= 0.95;
    }
    else if (b == Button4)
    {
        fract->zoom *= 1.02;
    }
    ft_render(fract);
    return (0);
}

int    mouse_track(int x, int y, t_fractal *fractal)
{
    if (!ft_cmp(fractal->name, "julia"))
    {
        fractal->j_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->x_shift;
        fractal->j_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->y_shift;
        ft_render(fractal);
    }
    return 0;
}


int handle_close(t_fractal *fract)
{
    mlx_destroy_image(fract->mlx, fract->image.img);
    mlx_destroy_window(fract->mlx, fract->mlx_window);
    mlx_destroy_display(fract->mlx);
    free(fract->mlx);
    exit(1);
}