/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:01:06 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/15 22:27:45 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void julia_set(t_comp *z, t_comp *c, t_fractal *fract)
{
    if (ft_cmp(fract->name, "julia") == 0)
    {
        c->r = fract->j_x;
        c->i = fract->j_y;
    }
   else
   {
        c->r = z->r;
        c->i = z->i;
   }
}

static  void put_pixls(int x, int y, int color, t_image *img)
{
    int j;

    j = (y * img->size_line) + (x * (img->bit_pix / 8));
    *(unsigned int *)(img->pixl + j) = color;
}

static void    ft_pixls(int x, int y, t_fractal *fract)
{
    int    i;
    t_comp z;
    t_comp c;
    int    color;

    // z.r = 0.0;
    // z.i = 0.0;

    z.r = (map(x, -2, 2, 0, WIDTH) * fract->zoom)  + fract->x_shift;
    z.i = (map(y, 2, -2, 0, HEIGHT) * fract->zoom) + fract->y_shift;

   julia_set(&z, &c, fract);

    i = 0;
    while (i < fract->iteration)
    {
        z = sum_comp(sr_comp(z), c);
        if ((z.r * z.r) + (z.i * z.i) > fract->esc)
        {
            color = map(i, BLACK, WHITE, 0, fract->iteration);
            put_pixls(x, y, color, &fract->image);
            return;
        }
        ++i;
    }
    put_pixls(x, y, BLACK, &fract->image);
}

void    ft_render(t_fractal *fract)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            ft_pixls(x, y, fract);
        }
    }
    mlx_put_image_to_window(fract->mlx, fract->mlx_window, fract->image.img, 0, 0);
}