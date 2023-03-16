/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:41:25 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 17:12:39 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	j;

	dst_len = ft_strlen(dst);
	j = 0;
	if (ft_strlen(dst) >= dstsize)
	{
		return (dstsize + ft_strlen(src));
	}
	while (src[j] && dst_len < (dstsize - 1))
	{
		dst[dst_len] = src[j];
		dst_len++;
		j++;
	}
	dst[dst_len] = '\0';
	return ((dst_len - j) + ft_strlen(src));
}
