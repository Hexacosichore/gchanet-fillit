/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:59:46 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/18 12:09:23 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	normalize_tetri(t_tetri *tetri, t_point *min)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		tetri->blocs[i].x -= min->x;
		tetri->blocs[i].y -= min->y;
		if (tetri->blocs[i].x + 1 > tetri->size.x)
			tetri->size.x = tetri->blocs[i].x + 1;
		if (tetri->blocs[i].y + 1 > tetri->size.y)
			tetri->size.y = tetri->blocs[i].y + 1;
		i++;
	}
	return (1);
}

static int	check_tetri(t_tetri *tetri)
{
	t_point	min;
	int		i;
	int		j;

	min.x = 4;
	min.y = 4;
	tetri->size.x = 0;
	tetri->size.y = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (j != i && (tetri->blocs[i].x == tetri->blocs[j].x
					|| tetri->blocs[i].y == tetri->blocs[j].y))
				break ;
			if (j == 3)
				return (-1);
			j++;
		}
		if (tetri->blocs[i].x < min.x)
			min.x = tetri->blocs[i].x;
		if (tetri->blocs[i].y < min.y)
			min.y = tetri->blocs[i].y;
		i++;
	}
	return (normalize_tetri(tetri, &min));
}

int	parse_entry(int fd, t_fillit **fillit)
{
	char				*line;
	int					y;
	int					x;
	int					tetri_i;
	t_tetri				*tetri;

	y = 0;
	tetri_i = 0;
	(*fillit)->tetri = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		if (y == 0 || (y % 5 == 0))
		{
			tetri = (t_tetri *)malloc(sizeof(t_tetri));
			if (!tetri)
				return (0);
			tetri->index = 0;
		}
		while (line[x] == '.' && x < 4)
			x++;
		while (line[x] == '#' && x < 4)
		{
			tetri->blocs[tetri->index].x = x;
			tetri->blocs[tetri->index].y = y % 5;
			tetri->index++;
			x++;
		}
		while (line[x] == '.' && x < 4)
			x++;
		if (y % 5 == 3 && check_tetri(tetri))
		{
			tetri->index = tetri_i++;
			tetri->i_pos = 0;
			ft_lstadd(&((*fillit)->tetri), ft_lstnew((void *)tetri));
		}
		y++;
	}
	(*fillit)->tetri_count = tetri_i;
	return (1);
}
