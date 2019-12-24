/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrylourtie <henrylourtie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 06:33:03 by hlourtie          #+#    #+#             */
/*   Updated: 2019/12/24 11:39:41 by henrylourti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 50000

typedef struct	s_biggest{

	int		x_co;
	int		y_co;
	int		size;
}				t_biggest;
typedef	struct	s_info{
	int		lines;
	int		count;
	char	vide;
	char	obstacle;
	char	plein;
}				t_info;

int				ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
char			**get_info(char *str, char **tab, t_info *info);
int				**get_sim(char **tab, t_info *info);
void			ft_putchar(char a);
char			**find_square(char **tab, t_info *info);
void			print_map(char **tab, t_info *info);
int				**get_special(char **tab, t_info *info, int **ret);
char			*get_next_line(char *str, t_info *info);
char			**read_and_store(char *begin, char **tab, t_info *info);
char			*get_first_line(char *str);
char			**get_info(char *str, char **tab, t_info *info);
int				**get_sim(char **tab, t_info *info);
int				**get_special(char **tab, t_info *info, int **ret);
int				valid_map(char **tab, t_info *info);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strdup(char *src);
char			*get_file(char *str);
char			*ft_strcat2(char *s1, char *s2);
void			free_tab(char **tab, t_info *info);
char			*get_std(void);
char			**get_info_std(char **tab, t_info *info);
void			free_square(t_biggest *big, int **test, t_info *info);
char			**checkborder(char **tab, t_biggest *big, t_info *info);
char			**find_square(char **tab, t_info *info);
#endif
