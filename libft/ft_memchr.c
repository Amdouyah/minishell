/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:49:15 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/07 17:34:15 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*c_str;

	i = 0;
	c_str = (unsigned char *)str;
	while (i < n)
	{
		if (c_str[i] == (unsigned char)c)
			return (&c_str[i]);
		i++;
	}
	return (0);
}
