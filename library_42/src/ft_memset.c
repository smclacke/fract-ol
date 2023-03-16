/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:27:22 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 17:12:04 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = ((unsigned char *)b);
	while (len-- > 0)
	{
		*(ptr++) = ((unsigned char)c);
	}
	return (b);
}
