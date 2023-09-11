/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdouyah <amdouyah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:39:54 by amdouyah          #+#    #+#             */
/*   Updated: 2022/10/18 15:28:40 by amdouyah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	funcnum(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
			i++;
			n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*p;
	long int	n;

	n = nb;
	len = funcnum(n);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n == 0)
		p[0] = '0';
	else if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		len--;
		p[len] = (n % 10) + '0';
		n /= 10;
	}
	return (p);
}
