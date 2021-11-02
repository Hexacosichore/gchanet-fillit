/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:55:15 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/26 19:00:15 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_fillit	*fillit;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			fillit = malloc(sizeof(t_fillit));
			if (fillit && parse_entry(fd, &fillit))
			{
				resolve(fillit);
				close(fd);
			}
			else
				ft_putstr("error parse");
			ft_lstdel(&fillit->tetri, NULL);
			ft_memdel((void **)&fillit);
		}
	}
	return (1);
}
