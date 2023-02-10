/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:43:36 by zel-kach          #+#    #+#             */
/*   Updated: 2022/12/22 15:30:20 by zel-kach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_count_num(int c)
{
	long	count;
	long	nb;

	nb = c;
	count = 0;
	if (nb <= 0)
	{
		nb *= -1;
		while (nb > 0)
		{
			nb = (nb / 10);
			count++;
		}
		return (count + 1);
	}
	else
	{	
		while (nb > 0)
		{
			nb = (nb / 10);
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int c)
{
	char	*s;
	long	i;
	long	a;
	long	nb;

	nb = c;
	a = 0;
	i = ft_count_num(c);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (nb < 0)
	{
		a = 1;
		s[0] = '-';
		nb *= -1;
	}
	while (i-- > a)
	{
		s[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}

int	ft_strlen(const char *ss)
{
	int	i;

	i = 0;
	while (ss[i] != '\0')
		i++;
	return (i);
}
