/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:36:24 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/07 16:09:07 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cast_s;

	i = ft_strlen(s);
	cast_s = (char *)s;
	while (i && cast_s[i] != (char)c)
		i--;
	if (cast_s[i] == (char)c)
		return (&cast_s[i]);
	return (0);
}
