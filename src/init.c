/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:38 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/18 19:23:27 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -2;
	data->x[1] = 2;
	data->y[1] = -2;
	data->y[0] = data->y[1] + (data->x[1] - data->x[0]) * HEIGHT / WIDTH;
	data->xscale = 1;
	data->yscale = 1;
	data->scale = 1;
	data->mouse[0] = 0;
	data->mouse[1] = 1;
	data->julia[0] = 0;
	data->julia[1] = 1;
	data->colour[r] = 4;
	data->colour[g] = 8;
	data->colour[b] = 12;
	data->zoom = 1;
	fractal(data);
}

void	check_data(t_fractol *data, char **argv)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		data->set = MANDELBROT;
		ft_controls();
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		data->set = JULIA;
		ft_controls();
	}
	else if (ft_strcmp(argv[1], "Burningship") == 0)
	{
		data->set = BURNINGSHIP;
		ft_controls();
	}
	else
		ft_help();
}

void	julia_args(t_fractol *data, char **argv)
{
	data->julia[0] = ft_atof(argv[2]);
	data->julia[1] = ft_atof(argv[3]);
	julia(data);
}

int	fractal(t_fractol *data)
{
	if (data->set == MANDELBROT)
		mandelbrot(data);
	else if (data->set == JULIA)
		julia(data);
	else if (data->set == BURNINGSHIP)
		burningship(data);
	return (0);
}

uint32_t	get_rgba(t_fractol *data, float iter)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;

	alpha = 255;
	red = (data->colour[r] * iter);
	green = (data->colour[g] * iter);
	blue = (data->colour[b] * iter);
	return ((red << 24 | green << 16 | blue << 8) | alpha);
}
