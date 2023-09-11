/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:10:22 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/11 10:38:34 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	r;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	j = 0;
	r = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (len_d < dstsize)
		r = len_d + len_s;
	else
		return (len_s + dstsize);
	while (dest[i])
		++i;
	while (src[j] && i < dstsize - 1)
	{
		dest[i] = src[j];
		++j;
		++i;
	}
	dest[i] = '\0';
	return (r);
}
