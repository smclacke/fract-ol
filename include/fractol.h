/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:28:21 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/24 21:08:42 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 250

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
	double				iter;
	double				max_iter;
	double				x[2];
	double				y[2];
	double				julia[2];
	int					mouse[2];
	double				xscale;
	double				yscale;
}	t_fractol;

//----------Hook----------//
void		colour_hook(t_fractol *data);
void		ft_move(t_fractol *data, char direction);
void		ft_key_hook(mlx_key_data_t keydata, t_fractol *data);

//--------Scroll Hook--------//
void		ft_zoom_in(t_fractol *data);
void		ft_zoom_out(t_fractol *data);
void		ft_scroll_hook(double xdelta, double ydelta, t_fractol *data);

//----------Utils----------//
void		ft_controls(void);
void		ft_exit(void);
void		ft_help(void);
double		ft_atof(char *str);
int			check_sign(char *str, int *sign);

//----------Init----------//
void		init(t_fractol *data);
void		check_data(t_fractol *data, char **argv);
int			fractal(t_fractol *data);
int			handle_args(t_fractol *data, char **argv, int argc);
uint32_t	get_rgba(t_fractol *data, float iter);

//----------Julia----------//
double		init_julia(t_fractol *data, double iter, double x, double y);
void		julia(t_fractol *data);
int			julia_args(t_fractol *data, char **argv);

//----------Mandelbrot----------//
double		init_mandelbrot(double iter, double x1, double y1);
void		mandelbrot(t_fractol *data);

//----------Burningship----------//
double		init_burning(double iter, double x1, double y1);
void		burningship(t_fractol *data);

//----------Colour----------//
void		shifty(t_fractol *data);
void		darkness(t_fractol *data);
void		blueness(t_fractol *data);
void		greenness(t_fractol *data);
void		redness(t_fractol *data);

#endif
