/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:38 by smclacke      #+#    #+#                 */
/*   Updated: 2023/07/23 22:49:26 by smclacke      ########   odam.nl         */
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
	data->xscale = 0.1;
	data->yscale = 0.1;
	data->mouse[0] = 0;
	data->mouse[1] = 1;
	data->colour[r] = 8;
	data->colour[g] = 4;
	data->colour[b] = 2;
	data->x_res = 1000;
	data->y_res = 1000;
	fractal(data);
}

int	handle_args(t_fractol *data, char **argv, int argc)
{
	if (!(argc == 2 || argc == 4))
		return (ft_help(), EXIT_FAILURE);
	if (argc == 4)
		julia_args(data, argv);
	if (argc == 2)
		data->julia[0] = 0;
		data->julia[1] = 1;
	return (0);
}

void	check_data(t_fractol *data, char **argv)
{
	char	*lowered;

	lowered = ft_lower_str(argv[1]);
	if (ft_strcmp(lowered, "mandelbrot") == 0)
	{
		data->set = MANDELBROT;
		ft_controls();
	}
	else if (ft_strcmp(lowered, "julia") == 0)
	{
		data->set = JULIA;
		ft_controls();
	}
	else if (ft_strcmp(lowered, "burningship") == 0)
	{
		data->set = BURNINGSHIP;
		ft_controls();
	}
	else
		ft_help();
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
