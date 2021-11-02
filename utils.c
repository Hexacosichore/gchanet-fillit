/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:56:20 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/18 12:08:51 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	itox(int index, int size)
{
	return (index % size);
}

int	itoy(int index, int size)
{
	return (index / size);
}

int	ptoi(t_point p, int i_pos, int size)
{
	return (i_pos + p.x + (p.y * size));
}
