/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 15:30:59 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/16 22:49:57 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	ft_zoom_in(t_fractol *data)
{
	double *var;
	double	zoom;
	double	xdelta;
	double	ydelta;

	var = &data->zoom;
	zoom = 1.03;
	*var /= zoom;
	xdelta = (data->x[1] - data->x[0]);
	ydelta = (data->y[1] - data->y[0]);
	data->x[0] = data->x[1] + (1.0 / zoom) * xdelta;
	data->y[0] = data->y[0] + (ydelta - (1.0 / zoom) * ydelta) / 2;
	data->iter++;
	fractal(data);
}

void	ft_zoom_out(t_fractol *data)
{
	double *var;
	double	zoom;
	double	xdelta;
	double	ydelta;

	var = &data->zoom;
	zoom = 1.03;
	*var *= zoom;
	xdelta = (data->x[0] - data->x[1]);
	ydelta = (data->y[0] - data->y[1]);
	data->x[1] = data->x[1] + (xdelta - zoom * xdelta) / 2;
	data->y[1] = data->y[0] + zoom * ydelta;
	data->iter++;
	fractal(data);
}


