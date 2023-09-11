/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:52:11 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/08 16:54:13 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}
/*int main()
{
	int	c = 2;
	int size = 4;
	char	*s;

	s = ft_calloc(c, size);
	int	i = 0;
	while (i < (c * size))
		printf("%d", s[i++]);
	
	return 0;
}*/
