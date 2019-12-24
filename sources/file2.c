/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:28:09 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:39:59 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
** open en read from the stdin
*/

char		*get_std(void)
{
	char*buff;
	int	red;
	int first;
	char*ret;
	int	input;

	first = 1;
	input = 0;
	if (!(buff = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (NULL);
	while ((red = read(0, buff, BUF_SIZE)) != 0)
	{
		input++;
		buff[red] = '\0';
		if (first-- == 1)
			ret = ft_strdup(buff);
		else
			ret = ft_strcat(ret, buff);
	}
	free(buff);
	if (!input)
		return (NULL);
	return (ret);
}

char		**get_info_std(char **tab, t_info *info)
{
	char*buff;
	char*temp;
	int i;

	i = 0;
	if (tab != NULL)
		free_tab(tab, info);
	if (!(buff = get_std()))
		return (NULL);
	if (!(temp = get_first_line(buff)))
		return (NULL);
	i = ft_strlen(temp) - 1;
	info->plein = temp[i--];
	info->obstacle = temp[i--];
	info->vide = temp[i];
	temp[i] = '\0';
	info->lines = ft_atoi(temp);
	if (info->lines == 0 || info->obstacle == info->vide ||
		info->obstacle == info->plein || info->vide == info->plein)
		return (NULL);
	while (buff[i] != '\n')
		i++;
	tab = read_and_store((buff + i + 1), tab, info);
	free(buff);
	return (tab);
}

/*
**	rewrite the map with different values so that the algorithm in 
**	the solving step works for any type of entry
*/

int			**get_sim(char **tab, t_info *info)
{
	int	**ret;
	int	i;
	int j;
	int len;

	ret = (int **)malloc(sizeof(int *) * info->lines);
	len = ft_strlen(tab[0]);
	i = 0;
	while (++i < info->lines)
	{
		ret[i] = (int*)malloc(sizeof(int) * len);
		j = 0;
		while (++j < len)
		{
			if (tab[i][j] == info->obstacle)
				ret[i][j] = 4;
			else
				ret[i][j] = 0;
		}
	}
	ret = get_special(tab, info, ret);
	return (ret);
}

/*
**	gets the first line of the file
*/

char		*get_first_line(char *str)
{
	int i;
	char*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
