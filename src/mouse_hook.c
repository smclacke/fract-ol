/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_hook.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 15:23:53 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/16 18:15:43 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	to_mouse(t_fractol *data)
// {
// 	long double	xzoom;
// 	long double	yzoom;
// 	printf("reached zoom to\n");

// 	data->xscale = data->x[0] - data->x[1];
// 	data->yscale = data->y[1] - data->y[0];
// 	xzoom = 0.9 * data->xscale;
// 	yzoom = 0.9 * data->yscale;
// 	data->x[1] = data->x[1] + (data->xscale - xzoom) / 2;
// 	data->x[0] = data->x[1] + xzoom;
// 	data->y[0] = data->y[0] + (data->yscale - yzoom) / 2;
// 	data->y[1] = data->y[0] + yzoom;
// 	mlx_get_mouse_pos(data->mlx, &data->xcr, &data->ycr);
// 	data->xcr = data->xcr - (WIDTH / 2);
// 	data->ycr = data->ycr - (HEIGHT / 2);
// 	data->xscale = data->x[1] - data->x[0];
// 	data->yscale = data->y[1] = data->y[0];
// 	xzoom = 0.1111111111111111111111111111111111111111 * data->xscale;
// 	yzoom = 0.1111111111111111111111111111111111111111 * data->yscale;
// 	zoom_in(xzoom, yzoom, data);
// }

// void		from_mouse(t_fractol *data)
// {
// 	long double	xzoom;
// 	long double	yzoom;
// 	printf("reached zoom from\n");

// 	data->xscale = data->x[0] - data->x[1];
// 	data->yscale = data->y[1] - data->y[0];
// 	xzoom = 1.1 * data->xscale;
// 	yzoom = 1.1 * data->yscale;
// 	data->x[1] = data->x[1] + (data->xscale - xzoom) / 2;
// 	data->x[0] = data->x[1] + xzoom;
// 	data->y[0] = data->y[0] + (data->yscale - yzoom) / 2;
// 	data->y[1] = data->y[0] + yzoom;
// 	mlx_get_mouse_pos(data->mlx, &data->xcr, &data->ycr);
// 	data->xcr = data->xcr - WIDTH / 2;
// 	data->ycr = data->ycr - HEIGHT / 2;
// 	data->xscale = data->x[1] - data->x[0];
// 	data->yscale = data->y[1] - data->y[0];
// 	xzoom = 0.0909090909090909090909090909090909090909 * data->xscale;
// 	yzoom = 0.0909090909090909090909090909090909090909 * data->yscale;
// 	zoom_out(xzoom, yzoom, data);
// }


// // void	ft_mouse_hook(t_fractol *data)
// // {
// // 	int32_t	x;
// // 	int32_t	y;
// // 	printf("reached mouse hook");
// // 	if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_LEFT))
// // 	{
// // 		mlx_get_mouse_pos(data->mlx, &x, &y);
// // 		data->julia[0] = data->x[0] + (long double)x * (data->x[1] - data->x[0]) / WIDTH;
// // 		data->julia[1] = data->y[0] + (long double)y * (data->y[1] - data->y[0]) / HEIGHT;
// // 	}
// // }

// void	ft_scroll_hook(double xdelta, double ydelta, t_fractol *data)
// {
// 	xdelta++;
// 	printf("reached scroll hook\n");
// 	if (ydelta > 0)
// 	{
// 		if (data->xscale > 0.1)
// 			{
// 				if (data->yscale > 0.1)
// 				printf("reach 1\n");
// 					to_mouse(data);
// 				if (ydelta < 0 && data->xscale < 32)
// 				printf("reach 2\n");
// 					from_mouse(data);
// 			}
// 		fractal(data);
// 	}
// }
