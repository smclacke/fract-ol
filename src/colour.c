/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colour.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:28 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/01 14:21:10 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	shifty(t_fractol *data)
{
	data->colour[0] += 4;
	data->colour[1] += 6;
	data->colour[2] += 8;
	fractal(data);
}

void	darkness(t_fractol *data)
{
	data->colour[0] -= 2;
	data->colour[1] -= 3;
	data->colour[2] -= 4;
	fractal(data);
}

void	blueness(t_fractol *data)
{
	data->colour[0] -= 1;
	data->colour[1] -= 1;
	data->colour[2] += 4;
	fractal(data);
}

void	greenness(t_fractol *data)
{
	data->colour[0] -= 1;
	data->colour[1] += 4;
	data->colour[2] -= 1;
	fractal(data);
}

void	redness(t_fractol *data)
{
	data->colour[0] += 4;
	data->colour[1] -= 1;
	data->colour[2] -= 1;
	fractal(data);
}
