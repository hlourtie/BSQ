/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 06:43:57 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:35:46 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
**	gets the next line of the file
*/

char		*get_next_line(char *str, t_info *info)
{
	int i;
	char*ret;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	if (str[i] == '\n' || str[i] == '\0')
		info->count++;
	ret[i] = '\0';
	return (ret);
}

/*
**	read the entirety of the map en stores it
*/

char		**read_and_store(char *begin, char **tab, t_info *info)
{
	int	i;

	i = 0;
	if (!(tab = malloc(sizeof(char*) * (info->lines + 1))))
		return (NULL);
	while (i < info->lines)
	{
		tab[i] = NULL;
		i++;
	}
	i = 0;
	while (i < info->lines)
	{
		tab[i] = get_next_line(begin, info);
		begin += ft_strlen(tab[i]) + 1;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
**	recuperates the info of the from the map, first line first then reads and stores the rest of the map.
*/

char		**get_info(char *str, char **tab, t_info *info)
{
	char*buff;
	char*temp;
	int i;

	i = 0;
	if (tab != NULL)
		free_tab(tab, info);
	if (!(buff = get_file(str)))
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
	return (tab);
}

/*
**	creates the first and the last lines that does not follow the same rules
*/

int			**get_special(char **tab, t_info *info, int **ret)
{
	int len;
	int i;

	len = ft_strlen(tab[0]);
	ret[0] = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		if (tab[0][i] == info->obstacle)
			ret[0][i] = 0;
		else
			ret[0][i] = 1;
	}
	i = 1;
	while (i < info->lines)
	{
		if (tab[i][0] == info->obstacle)
			ret[i][0] = 0;
		else
			ret[i][0] = 1;
		i++;
	}
	return (ret);
}

/*
** get the file open and read it
*/

char		*get_file(char *str)
{
	int	fd;
	char*buff;
	int	red;
	int first;
	char*ret;

	first = 1;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	if (!(buff = malloc(sizeof(char) * (BUF_SIZE + 1))))
		return (NULL);
	while ((red = read(fd, buff, BUF_SIZE)) != 0)
	{
		buff[red] = '\0';
		if (first-- == 1)
			ret = ft_strdup(buff);
		else
			ret = ft_strcat(ret, buff);
	}
	free(buff);
	if (close(fd) == -1)
		return (NULL);
	return (ret);
}
