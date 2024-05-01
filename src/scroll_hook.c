/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 18:42:56 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/01 14:21:29 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_zoom_in(t_fractol *data)
{	
	double	pro[2];
	double	range[2];
	double	chop[2];
	double	newrange[2];

	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	pro[X] = (double)data->mouse[X] / data->win_width;
	pro[Y] = (double)data->mouse[Y] / data->win_height;
	range[X] = data->x[RT] - data->x[LT];
	range[Y] = data->y[UP] - data->y[DN];
	chop[X] = range[X] * 0.1;
	newrange[X] = range[X] - chop[X];
	chop[Y] = range[Y] * 0.1;
	newrange[Y] = range[Y] - chop[Y];
	data->x[LT] += chop[X] * pro[X];
	data->x[RT] = data->x[LT] + newrange[X];
	data->y[UP] -= chop[Y] * pro[Y];
	data->y[DN] = data->y[UP] - newrange[Y];
}

void	ft_zoom_out(t_fractol *data)
{
	double	pro[2];
	double	range[2];
	double	chop[2];
	double	newrange[2];

	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	pro[X] = (double)data->mouse[X] / data->win_width;
	pro[Y] = (double)data->mouse[Y] / data->win_height;
	range[X] = data->x[RT] - data->x[LT];
	range[Y] = data->y[UP] - data->y[DN];
	chop[X] = range[X] * 0.1;
	newrange[X] = range[X] + chop[X];
	chop[Y] = range[Y] * 0.1;
	newrange[Y] = range[Y] + chop[Y];
	data->x[LT] -= chop[X] * pro[X];
	data->x[RT] = data->x[LT] + newrange[X];
	data->y[UP] += chop[Y] * pro[Y];
	data->y[DN] = data->y[UP] - newrange[Y];
}

void	ft_scroll_hook(double xdelta, double ydelta, t_fractol *data)
{
	(void) xdelta;
	(void) ydelta;
	if (ydelta > 0)
		ft_zoom_in(data);
	else
		ft_zoom_out(data);
	fractal(data);
}
