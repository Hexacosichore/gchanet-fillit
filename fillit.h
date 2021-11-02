/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:20:51 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/18 12:08:46 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_tetri {
	int				index;
	int				i_pos;
	t_point			blocs[4];
	t_point			size;
}					t_tetri;

typedef struct s_fillit {
	char			*map;
	int				map_size;
	int				resolved;
	t_list			*tetri;
	int				tetri_count;
}			t_fillit;

/*	resolve.c	*/
void	resolve(t_fillit *f);

/*	parsing.c	*/
int		parse_entry(int fd, t_fillit **fillit);

/*	print.c	*/
void	draw_map(t_fillit *f);

/*	utils.c	*/
int		itox(int index, int size);
int		itoy(int index, int size);
int		ptoi(t_point p, int i_pos, int size);

#endif
