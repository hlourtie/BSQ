/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlourtie <hlourtie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:59:12 by hbuisser          #+#    #+#             */
/*   Updated: 2019/08/28 19:59:43 by hlourtie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	line_lenght(char **tab, t_info *info)
{
	int i;

	i = 0;
	while (i < info->lines)
	{
		if (ft_strlen(tab[0]) != ft_strlen(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	box_size(char **tab, t_info *info)
{
	if (info->lines < 1)
		return (0);
	if (ft_strlen(tab[0]) < 1)
		return (0);
	return (1);
}

int	line_break_and_characters(char **tab, t_info *info)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < info->lines)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '\n')
				count++;
			if (tab[i][j] != info->vide && tab[i][j] != info->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	if (info->count != info->lines)
		return (0);
	return (1);
}

int	valid_map(char **tab, t_info *info)
{
	if (line_lenght(tab, info) && box_size(tab, info) &&
			line_break_and_characters(tab, info))
		return (1);
	else
		return (0);
}
