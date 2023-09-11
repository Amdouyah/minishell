/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:13:01 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/08 17:27:28 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		a;

	if ((!haystack || !needle) && len == 0)
		return (0);
	while (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		a = 0;
		while (haystack[i + a] == needle[a] && i + a < len)
		{
			if (needle[a + 1] == '\0')
			{
				return ((char *)&haystack[i]);
			}
			a++;
		}
		i++;
	}
	return (0);
}
