/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lower_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/18 22:17:06 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/18 22:20:13 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lower_str(char *str)
{
	char	*lowercase_str;
	int		len;
	int		i;

	i = 0;
	lowercase_str = ft_strdup(&str[i]);
	len = ft_strlen(lowercase_str);
	while (i < len)
	{
		lowercase_str[i] = ft_tolower(lowercase_str[i]);
		i++;
	}
	return (lowercase_str);
}
