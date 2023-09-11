/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:44:42 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/09 22:25:25 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= (ft_strlen(s) - start))
		return (ft_strdup(s + start));
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	s += start;
	while (i < len)
	{
		p[i] = s[i];
		++i;
	}
	p[i] = '\0';
	return (p);
}
