/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lower_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: SarahLouise <SarahLouise@student.42.fr>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/18 22:17:06 by smclacke      #+#    #+#                 */
/*   Updated: 2023/04/10 16:46:21 by SarahLouise   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lower_str(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
