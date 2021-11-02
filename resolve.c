/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:00:55 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/15 18:03:36 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	settetritomap(t_fillit *f, t_tetri *t, int mode)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mode == -1)
			f->map[ptoi(t->blocs[i], t->i_pos, f->map_size)] = '.';
		else
			f->map[ptoi(t->blocs[i], t->i_pos, f->map_size)] = (t->index + 'A');
		i++;
	}
}

static int	check_pos(t_fillit *f, t_tetri *t, int size, int i_map)
{
	int	i;

	i = 0;
	if ((t->size.y + itoy(i_map, size) > size))
		return (0);
	if ((t->size.x + itox(i_map, size) > size))
		return (-1);
	while (i < 4)
	{
		if (f->map[ptoi(t->blocs[i], i_map, size)] != '.')
			return (-2);
		i++;
	}
	while (i < 4)
	{
		f->map[ptoi(t->blocs[i], i_map, size)] = t->index;
	}
	t->i_pos = i_map;
	settetritomap(f, t, 1);
	return (1);
}

static void	resolve_size(t_fillit *f, int *size, int i_map, t_list *tetri)
{
	int	out_val;

	while (!f->resolved)
	{
		out_val = check_pos(f, tetri->content, *size, i_map);
		if (out_val == 1)
		{
			if (tetri->next == NULL)
			{
				draw_map(f);
				f->resolved = 1;
			}
			else
			{
				resolve_size(f, size, 0, tetri->next);
				if (!f->resolved)
					settetritomap(f, tetri->content, -1);
				i_map++;
			}
		}
		else if (out_val < 0)
			i_map++;
		else if (out_val == 0)
			break ;
	}
}

void	resolve(t_fillit *f)
{
	int	sqrt;

	f->resolved = 0;
	f->map = NULL;
	sqrt = 1;
	while (sqrt * sqrt <= f->tetri_count * 4)
		sqrt ++;
	f->map_size = sqrt - 2;
	while (!f->resolved)
	{
		f->map_size++;
		f->map = malloc(ft_pow(f->map_size, 2) + 1);
		ft_memset(f->map, '.', ft_pow(f->map_size, 2));
		f->map[(f->map_size * f->map_size)] = '\0';
		resolve_size(f, &f->map_size, 0, f->tetri);
		free(f->map);
	}
}
