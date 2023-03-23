/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 22:28:05 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/23 18:32:54 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	ft_putendl_fd("*!*!* FRACTALS! *!*!*\n", 1);
	ft_putendl_fd("Please Input: \n\n./fractol + <fractol>\n", 1);
	ft_putendl_fd("<fractol>: Mandelbrot OR Julia OR Burningship.\n", 1);
	ft_putendl_fd("** For Julia, you may include x and y starting values", 1);
	ft_putendl_fd("** between -2 and 2, with a decimal point.", 1);
	ft_exit();
}

void	ft_exit(void)
{
	exit(1);
}

void	ft_controls(void)
{
	ft_putendl_fd(" Zooming in/out: +/- keys or mouse scroll", 1);
	ft_putendl_fd(" Closing window: ESC or cross in window", 1);
	ft_putendl_fd(" Moving fractal: -> arrow keys", 1);
	ft_putendl_fd(" Press S for some colour shifting shenanigans!", 1);
	ft_putendl_fd(" Press D, B, R or G and have fun :)", 1);
}

int	check_sign(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	}
	return (sign);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;

	if (!str)
		return (0);
	i = 0;
	result = 0.0;
	decimal = 1.0;
	if (str[i])
	{
		sign = check_sign(str);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		decimal *= 10;
	}
	if (str[i] == '\0')
		return (sign * result / decimal);
	else
		return (ft_help(), EXIT_FAILURE);
}
