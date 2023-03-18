/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:44 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/18 21:27:52 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z = z2 + c

double	init_julia(t_fractol *data, double iter, double x, double y)
{
	double	var;

	iter = 0;
	while ((x * x + y * y) < 4 && iter < MAX_ITER)
	{
		var = x;
		x = (x * x) - (y * y) + data->julia[X];
		y = 2 * y * var + data->julia[Y];
		iter++;
	}
	return (iter);
}

void	julia(t_fractol *data)
{
	double	iter;
	int		colour;
	double	x;
	double	y;
	double	pos[2];

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		pos[X] = (data->x[LT] + (x / WIDTH) * (data->x[RT] - data->x[LT])) * data->zoom;
		while (y < HEIGHT)
		{
			pos[Y] = (data->y[UP] + (y / HEIGHT) * (data->y[DN] - data->y[UP])) * data->zoom;
			iter = init_julia(data, data->iter, pos[X], pos[Y]);
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
