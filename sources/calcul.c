/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:55:01 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:34:42 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
**	returns the minimum of the 3 numbers
*/

int		minimum(int a, int b, int c)
{
	if (a <= b && a <= c)
	{
		return (a);
	}
	else if (b <= a && b <= c)
	{
		return (b);
	}
	else
		return (c);
}

/*
**	updates the map for the minimum number and also update the emplacement 
**	and the value of the biggest square
*/

int		**update(int i, int j, int **test, t_biggest *big)
{
	if (test[i][j] == 0)
		test[i][j] = minimum(test[i - 1][j],
			test[i][j - 1], test[i - 1][j - 1]) + 1;
	else
	{
		test[i][j] = 0;
		return (test);
	}
	if (big->size < test[i][j])
	{
		big->size = test[i][j];
		big->x_co = j;
		big->y_co = i;
	}
	return (test);
}

/*
**	fills the tab at the right emplacement for the square
*/

char	**convert_tab(char **tab, t_biggest *big, t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < big->size)
	{
		j = 0;
		while (j < big->size)
		{
			tab[big->y_co - i][big->x_co - j] = info->plein;
			j++;
		}
		i++;
	}
	return (tab);
}

/*
**	initialise the big struct that contains the coordinates and the size of the biggest square
*/

void	initialise_big(t_biggest *big)
{
	big->size = 0;
	big->y_co = 0;
	big->x_co = 0;
}

/*
**	main algorithm of the solution getting a copy of the map
**	and finding the BSQ in it
*/
char	**find_square(char **tab, t_info *info)
{
	int			**test;
	t_biggest	*big;
	int			i;
	int			j;

	test = get_sim(tab, info);
	big = (t_biggest *)malloc(sizeof(t_biggest));
	initialise_big(big);
	i = 1;
	while (i < info->lines)
	{
		j = 1;
		while (j < ft_strlen(tab[i]))
		{
			test = update(i, j, test, big);
			j++;
		}
		i++;
	}
	if ((big->y_co == 0 && big->x_co == 0) || big->size == 1)
		tab = checkborder(tab, big, info);
	tab = convert_tab(tab, big, info);
	free_square(big, test, info);
	return (tab);
}
