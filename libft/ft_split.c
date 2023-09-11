/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:08:41 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/19 18:08:31 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_num(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			n++;
		}
	}
	return (n);
}

static int	word_len(char const *s, char c, int i)
{
	int	a;

	a = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		a++;
	}
	return (a);
}

static char	**alloc(char **p, const char *s, int i, char c)
{
	int	j;
	int	k;

	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = malloc(sizeof(char) * (word_len(s, c, i) + 1));
			if (!p[j])
				return (NULL);
			while (s[i] && s[i] != c)
				p[j][k++] = s[i++];
			p[j++][k] = '\0';
		}
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;

	p = malloc(sizeof(char *) * (word_num(s, c) + 1));
	if (!p)
		return (NULL);
	i = 0;
	alloc(p, s, i, c);
	return (p);
}
/*#include <stdio.h>
int main ()
{
	char *s = " hello world 42 ";
	char c = ' ';
	char **res = ft_split(s, c);
	for(int i = 0; i < 3; i++)
		printf("%s\n", res[i]);
}*/
