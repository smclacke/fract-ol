/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:13 by smclacke      #+#    #+#                 */
/*   Updated: 2023/05/10 02:57:11 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colour_hook(t_fractol *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		shifty(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		darkness(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		redness(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_G))
		greenness(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_B))
		blueness(data);
	fractal(data);
}

void	ft_move(t_fractol *data, char direction)
{
	if (direction == 'L')
	{
		data->x[LT] = data->x[LT] - data->xscale / 5;
		data->x[RT] = data->x[RT] - data->xscale / 5;
	}
	if (direction == 'R')
	{
		data->x[LT] = data->x[LT] + data->xscale / 5;
		data->x[RT] = data->x[RT] + data->xscale / 5;
	}
	if (direction == 'U')
	{
		data->y[LT] = data->y[LT] + data->yscale / 5;
		data->y[RT] = data->y[RT] + data->yscale / 5;
	}
	if (direction == 'D')
	{
		data->y[LT] = data->y[LT] - data->yscale / 5;
		data->y[RT] = data->y[RT] - data->yscale / 5;
	}
}

void	extra_hooking(t_fractol *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_J))
	{
		mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
		data->julia[X] = data->x[LT] + ((double)data->mouse[X] / WIDTH)
			* (data->x[RT] - data->x[LT]);
		data->julia[Y] = data->y[UP] + ((double)data->mouse[Y] / HEIGHT)
			* (data->y[DN] - data->y[UP]);
		fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_F))
	{
		fractal(data);
		if (data->set == 3)
			data->set = 1;
		else
			data->set += 1;
	}
}

void	ft_key_hook(mlx_key_data_t keydata, t_fractol *data)
{
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		ft_move(data, 'U');
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		ft_move(data, 'D');
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_move(data, 'L');
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_move(data, 'R');
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
		ft_zoom_in(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
		ft_zoom_out(data);
	extra_hooking(data);
	colour_hook(data);
	fractal(data);
}
