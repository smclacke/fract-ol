/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:27:51 by smclacke      #+#    #+#                 */
/*   Updated: 2023/05/02 18:24:53 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol		data;

	handle_args(&data, argv, argc);
	check_data(&data, argv);
	data.mlx = mlx_init(WIDTH, HEIGHT, "FRACING", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) == -1)
		return (free(data.img), mlx_terminate(data.mlx), EXIT_FAILURE);
	init(&data);
	mlx_key_hook(data.mlx, (mlx_keyfunc) ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc) ft_scroll_hook, &data);
	mlx_loop(data.mlx);
	mlx_close_window(data.mlx);
	mlx_terminate(data.mlx);
}
