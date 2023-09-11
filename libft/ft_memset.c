/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:19:24 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/06 12:59:06 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*cast_str;
	size_t			i;

	i = 0;
	cast_str = (unsigned char *) str;
	while (i < len)
	{
		cast_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
