/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferreir <sferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:13:32 by sferreir          #+#    #+#             */
/*   Updated: 2019/12/04 14:17:54 by sferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_piece *tetris_pieces;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	if ((tetris_pieces = create_source(av[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	solve(tetris_pieces);
	free_pieces(tetris_pieces);
	return (0);
}
