/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:36:11 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:10:44 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
** free the square that has been used as a copy
*/

void	free_square(t_biggest *big, int **test, t_info *info)
{
	int i;

	i = 0;
	while (i < info->lines)
	{
		free(test[i]);
		i++;
	}
	free(test);
	free(big);
}

/*
**	this function checks if the border of the map are correctly formated
*/

char	**checkborder(char **tab, t_biggest *big, t_info *info)
{
	int i;

	i = -1;
	while (++i < ft_strlen(tab[0]))
	{
		if (tab[0][i] == info->vide)
		{
			tab[0][i] = info->plein;
			big->x_co = i;
			big->y_co = 0;
			return (tab);
		}
	}
	i = -1;
	while (++i < info->lines)
	{
		if (tab[i][0] == info->vide)
		{
			tab[i][0] = info->plein;
			big->y_co = i;
			big->x_co = 0;
			return (tab);
		}
	}
	return (tab);
}

/*
**	rewriting of strcat
*/

char	*ft_strcat(char *s1, char *s2)
{
	char*ret;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(ret = (char *)malloc(sizeof(char*) * (ft_strlen(s1)
			+ ft_strlen(s2) + 1))))
		return (ret);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}

/*
** free the table that is used when not needed anymore
*/

void	free_tab(char **tab, t_info *info)
{
	int i;

	i = -1;
	while (++i < info->lines)
		free(tab[i]);
	free(tab);
}
