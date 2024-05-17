/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:01:25 by hel-haji          #+#    #+#             */
/*   Updated: 2024/05/15 22:27:33 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h> 


#define WIDTH 800
#define HEIGHT 800

#define WHITE          0xFFFFFF
#define RED            0xFF0000
#define LIME           0x00FF00
#define BLUE           0x0000FF
#define YELLOW         0xFFFF00
#define CYAN           0x00FFFF
#define MAGENTA        0xFF00FF
#define SILVER         0xC0C0C0
#define GRAY           0x808080
#define MAROON         0x800000
#define OLIVE          0x808000
#define PURPLE         0x800080
#define TEAL           0x008080
#define NAVY           0x000080
#define BLACK          0x000000

typedef struct s_image
{
    char    *pixl;
    int     bit_pix;
    int     size_line;
    int     endian;
    void    *img;
} t_image;


typedef struct s_fractal
{
    void    *mlx_window;
    void    *mlx;
    char    *name;
    t_image image;
    double  esc;
    int     iteration;
    double  x_shift;
    double  y_shift;
    double  zoom;
    double  j_x;
    double  j_y;
} t_fractal;

typedef struct s_comp
{
    double  r;
    double  i;
} t_comp;




int     ft_cmp(const char *s1, const char *s2); 
int    mouse_track(int x, int y, t_fractal *fractal);
void    ft_init(t_fractal *fract);
void    ft_render(t_fractal *fract);
double  map(double num, double min1, double max1, double min2, double max2);
t_comp  sum_comp(t_comp z1, t_comp z2);
t_comp  sr_comp(t_comp z);
int     handle_Key(int keysym, t_fractal *fract);
int     handle_mouse(int b, int x, int y, t_fractal *fract);
int     handle_close(t_fractal *fract);
float   ft_atof(const char *str);

#endif