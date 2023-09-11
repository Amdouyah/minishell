/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:02:53 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/14 16:31:42 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	finder(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	start(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (finder(str[i], set) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int	end(const char *str, const char *set)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[j])
	{
		if (finder(str[j], set) == 1)
		{
			i++;
			j--;
		}
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		r;
	int		s;
	int		e;

	s = start(s1, set);
	e = end(s1, set);
	r = ft_strlen(s1);
	return (ft_substr(s1, s, r - (s + e)));
}
