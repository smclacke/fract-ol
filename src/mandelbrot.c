/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:57 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/01 14:21:27 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// z = z2 + c

double	init_mandelbrot(double iter, double x1, double y1)
{
	double	var;
	double	x;
	double	y;

	x = x1;
	y = y1;
	iter = 0;
	while ((x * x) + (y * y) < 4 && iter < MAX_ITER)
	{
		var = x;
		x = (x * x) - (y * y) + x1;
		y = 2 * y * var + y1;
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_fractol *data)
{
	double	iter;
	int		colour;
	double	x;
	double	y;
	double	pos[2];

	x = 0;
	y = 0;
	while (x < data->win_width)
	{
		pos[X] = (data->x[LT] + (x / data->win_width) * (data->x[RT] - data->x[LT]));
		while (y < data->win_height)
		{
			pos[Y] = (data->y[UP] + (y / data->win_height) * (data->y[DN] - data->y[UP]));
			iter = init_mandelbrot(data->iter, pos[X], pos[Y]);
			if (iter == MAX_ITER)
				colour = 0xFF;
			else
				colour = get_rgba(data, iter);
			mlx_put_pixel(data->img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}
