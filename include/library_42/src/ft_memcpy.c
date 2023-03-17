/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 12:13:01 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 17:11:59 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = ((unsigned char *)dst);
	ptr2 = ((unsigned char *)src);
	while (n-- > 0 && (ptr1 || ptr2))
	{
		*(ptr1++) = *(ptr2++);
	}
	return (dst);
}
