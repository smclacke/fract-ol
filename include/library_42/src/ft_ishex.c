/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 16:01:48 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 16:01:54 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishex(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return(c);
	else
		return (0);
}
