/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:58:11 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/14 18:58:56 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	draw_map(t_fillit *f)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	ft_putchar('\n');
	while (y < f->map_size)
	{
		x = 0;
		while (x < f->map_size)
		{
			if (f->map[i] == 0)
				ft_putchar('.');
			else
				ft_putchar(f->map[i]);
			x++;
			i++;
		}
		y++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
