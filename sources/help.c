/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 06:59:38 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:19:38 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
**	This file contains a bunch of standard functions
*/

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_atoi(char *str)
{
	int n;
	int neg;

	n = 0;
	neg = 0;
	while (*str < 33)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if ((neg % 2))
		return (-n);
	return (n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;
	char	*origin;

	len = ft_strlen(src);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	origin = str;
	while (*src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (origin);
}
