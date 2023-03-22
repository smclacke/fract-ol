/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scroll_hook.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 18:42:56 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/22 18:44:59 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_in(t_fractol *data)
{	
	double	proX;
	double	proY;
	double	rangeX;
	double	rangeY;
	double	chopX;
	double	chopY;
	double	newrangeX;
	double	newrangeY;
	
	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	proX = (double)data->mouse[X] / WIDTH;
	proY = (double)data->mouse[Y] / HEIGHT;
	rangeX = data->x[RT] - data->x[LT];
	rangeY = data->y[UP] - data->y[DN];
	chopX = rangeX * 0.1;
	newrangeX = rangeX - chopX;
	chopY = rangeY * 0.1;
	newrangeY = rangeY - chopY;
	data->x[LT] += chopX * proX;
	data->x[RT] = data->x[LT] + newrangeX;
	data->y[UP] -= chopY * proY;
	data->y[DN] = data->y[UP] - newrangeY;
}

void	ft_zoom_out(t_fractol *data)
{
	double	proX;
	double	proY;
	double	rangeX;
	double	rangeY;
	double	chopX;
	double	chopY;
	double	newrangeX;
	double	newrangeY;

	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	proX = (double)data->mouse[X] / WIDTH;
	proY = (double)data->mouse[Y] / HEIGHT;
	rangeX = data->x[RT] - data->x[LT];
	rangeY = data->y[UP] - data->y[DN];
	chopX = rangeX * 0.1;
	newrangeX = rangeX + chopX;
	chopY = rangeY * 0.1;
	newrangeY = rangeY + chopY;
	data->x[LT] -= chopX * proX;
	data->x[RT] = data->x[LT] + newrangeX;
	data->y[UP] += chopY * proY;
	data->y[DN] = data->y[UP] - newrangeY;
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
