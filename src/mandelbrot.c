/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:57 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/18 19:03:55 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Zn+1 = Zn2 + C

float	init_mandelbrot(float iter, float x1, float y1)
{
	float	var;
	float	x;
	float	y;

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
	float	iter;
	int		colour;
	float	x;
	float	y;
	float	pos[2];

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		pos[X] = (data->x[LT] + (x / WIDTH) * (data->x[RT] - data->x[LT])) * data->zoom;
		while (y < HEIGHT)
		{
			pos[Y] = (data->y[UP] + (y / HEIGHT) * (data->y[DN] - data->y[UP])) * data->zoom;
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

// zoom = 0.8;
// width      		((x / (width * zoom)) * 4 -2) 
// width      		((x / (width / zoom)) * 4 -2) 