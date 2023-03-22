/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:13 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/22 14:45:03 by smclacke      ########   odam.nl         */
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

// void	ft_move(t_fractol *data, char direction)
// {
// 	if (direction == 'L')
// 	{
// 		data->x[LT] = data->x[LT] + data->xscale / 25;
// 		data->x[RT] = data->x[RT] + data->xscale / 25;
// 	}
// 	if (direction == 'R')
// 	{
// 		data->x[LT] = data->x[LT] - data->xscale / 25;
// 		data->x[RT] = data->x[RT] - data->xscale / 25;
// 	}
// 	if (direction == 'U')
// 	{
// 		data->y[LT] = data->y[LT] - data->yscale / 25;
// 		data->y[RT] = data->y[RT] - data->yscale / 25;
// 	}
// 	if (direction == 'D')
// 	{
// 		data->y[LT] = data->y[LT] + data->yscale / 25;
// 		data->y[RT] = data->y[RT] + data->yscale / 25;
// 	}
// }

void	ft_zoom_in(t_fractol *data)
{	
	double	proX;
	double	proY;
	double	rangeX;
	double rangeY;
	double chopX;
	double	chopY;
	double	newrangeX;
	double	newrangeY;
	
	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	printf("mouseX: %d\n", data->mouse[X]);
	printf("mouseY: %d\n", data->mouse[Y]);
	proX = data->mouse[X] / WIDTH;
	proY = data->mouse[Y] / HEIGHT;
	rangeX = data->x[RT] - data->x[LT];
	rangeY = data->y[UP] - data->y[DN];
	chopX = rangeX * 0.1;
	newrangeX = rangeX - chopX;
	chopY = rangeY * 0.1;
	newrangeY = rangeY - chopY;
	
	printf("chopX %f | chopY %f\n", chopX, chopY);
	// data->x[RT] += ((data->mouse[X] / WIDTH)-0.5) * data->zoom;
	// data->x[LT] -= ((data->mouse[X] / WIDTH)-0.5) * data->zoom;
	// data->y[DN] -= ((data->mouse[Y] / HEIGHT)-0.5) * data->zoom;
	// data->y[UP] += ((data->mouse[Y] / HEIGHT)-0.5) * data->zoom;
	data->x[LT] += chopX * proX;
	data->x[RT] = data->x[LT] + newrangeX;
	data->y[UP] -= chopY * proY;
	data->y[DN] = data->y[UP] - newrangeY;
}

void	ft_zoom_out(t_fractol *data)
{
	data->zoom *= 0.8;
	mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
	printf("mouseX: %d\n", data->mouse[X]);
	printf("mouseY: %d\n", data->mouse[Y]);
	// data->x[LT] += ((data->mouse[X] / WIDTH)-0.5) * data->zoom;
	// data->x[RT] -= ((data->mouse[X] / WIDTH)-0.5) * data->zoom;
	// data->y[UP] -= ((data->mouse[Y] / HEIGHT)-0.5) * data->zoom;
	// data->y[DN] += ((data->mouse[Y] / HEIGHT)-0.5) * data->zoom;
	data->x[LT] -= 0.1;
	data->x[RT] += 0.1;
	data->y[UP] += 0.1;
	data->y[DN] -= 0.1;
}

// do I need x[LT] or x[0] etc... ?

// -2   0   2
// zoom = 0.5
// coordinates * zoom
// -1   0   1

void	ft_key_hook(mlx_key_data_t keydata, t_fractol *data)
{
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	// 	ft_move(data, 'U');
	// if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	// 	ft_move(data, 'D');
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	// 	ft_move(data, 'L');
	// if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	// 	ft_move(data, 'R');
	// if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	// 	ft_zoom_in(data);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	// 	ft_zoom_out(data);
	colour_hook(data);
	fractal(data);
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
