/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:28:21 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/18 19:34:15 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 50

# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3
# define X 0
# define Y 1
# define LT 0
# define RT 1
# define UP 0
# define DN 1

# include "libft.h"
# include "MLX42/MLX42.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

enum e_colours {r, g, b};

typedef struct s_fractol {
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					set;
	enum e_colours		colour[3];
	int					iter;
	int					max_iter;
	float				x[2];
	float				y[2];
	float				julia[2];
	int					mouse[2];
	float				xscale;
	float				yscale;
	float				scale;
	double				zoom;
}	t_fractol;

//----------Hook----------//

void		colour_hook(t_fractol *data);
void		ft_move(t_fractol *data, char direction);
void		ft_zoom_in(t_fractol *data);
void		ft_zoom_out(t_fractol *data);
void		ft_key_hook(mlx_key_data_t keydata, t_fractol *data);
void		ft_scroll_hook(double xdelta, double ydelta, t_fractol *data);

//----------Utils----------//

void		ft_controls(void);
void		ft_exit(void);
void		ft_help(void);

//----------Init----------//

void		init(t_fractol *data);
void		check_data(t_fractol *data, char **argv);
int			fractal(t_fractol *data);
void		julia_args(t_fractol *data, char **argv);
uint32_t	get_rgba(t_fractol *data, float iter);

//----------Julia----------//

float		init_julia(t_fractol *data, float iter, float x, float y);
void		julia(t_fractol *data);

//----------Mandelbrot----------//

float		init_mandelbrot(float iter, float x1, float y1);
void		mandelbrot(t_fractol *data);

//----------Burningship----------//

float		init_burning(float iter, float x1, float y1);
void		burningship(t_fractol *data);

//----------Colour----------//

void		shifty(t_fractol *data);
void		darkness(t_fractol *data);
void		blueness(t_fractol *data);
void		greenness(t_fractol *data);
void		redness(t_fractol *data);

#endif
