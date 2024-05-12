/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:51 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/12 12:30:44 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_resize(int32_t width, int32_t height, void *param)
{
	t_fractol	*data;

	data = (t_fractol *)param;
	data->win_width = width;
	data->win_height = height;
	fractal(data);
}

void	set_window(t_fractol *data)
{
	data->win_width = 1000;
	data->win_height = 1000;
}

int	main(int argc, char **argv)
{
	t_fractol		data;

	set_window(&data);
	handle_args(&data, argv, argc);
	check_data(&data, argv);
	data.mlx = mlx_init(data.win_width, data.win_height, "FRACING", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	if (!data.img)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) == -1)
		return (free(data.img), mlx_terminate(data.mlx), EXIT_FAILURE);
	init(&data);
	mlx_key_hook(data.mlx, (mlx_keyfunc) ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc) ft_scroll_hook, &data);
	mlx_resize_hook(data.mlx, (mlx_resizefunc) ft_resize, &data);
	mlx_loop(data.mlx);
	mlx_close_window(data.mlx);
	mlx_terminate(data.mlx);
}
