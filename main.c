/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:07:57 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:19:34 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
**	Print the map at the end
*/

void	print_map(char **tab, t_info *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->lines)
	{
		j = ft_strlen(tab[i]);
		write(1, tab[i], j);
		if (i++ < info->lines)
			write(1, "\n", 1);
	}
}

/*
**	Solves for the biggest square if a file or files have been given as argument
*/

void	solve_it_file(int argc, t_info *info, char **argv)
{
	char**tab;
	int i;

	i = 1;
	while (i < argc)
	{
		info->count = 0;
		tab = NULL;
		if (!(tab = get_info(argv[i], tab, info)) || !valid_map(tab, info))
		{
			ft_putstr("map error\n");
			if (++i != argc)
				ft_putchar('\n');
			continue ;
		}
		tab = find_square(tab, info);
		print_map(tab, info);
		if (++i != argc)
			ft_putchar('\n');
	}
	if (tab != NULL)
		free_tab(tab, info);
}

/*
**	solves the map is no argument was passed and thus will read the std in
*/

void	solve_it_shell(t_info *info)
{
	char **tab;

	info->count = 0;
	tab = NULL;
	if (!(tab = get_info_std(tab, info)) || (!valid_map(tab, info)))
	{
		ft_putstr("map error\n");
		return ;
	}
	tab = find_square(tab, info);
	print_map(tab, info);
	free_tab(tab, info);
}

/*
**	main executable fct
*/

int		main(int argc, char **argv)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	if (argc == 1)
		solve_it_shell(info);
	else
		solve_it_file(argc, info, argv);
	free(info);
	return (0);
}
