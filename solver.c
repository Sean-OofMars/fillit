/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferreir <sferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:05:43 by sferreir          #+#    #+#             */
/*   Updated: 2019/12/09 06:56:47 by sferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		empty_space(t_grid *grid, t_piece *tetris_piece)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	x = tetris_piece->coords[i] + tetris_piece->x_offset;
	y = tetris_piece->coords[i + 1] + tetris_piece->y_offset;
	while (i <= 6 && grid->array[y][x] == '.')
	{
		i += 2;
		x = tetris_piece->coords[i] + tetris_piece->x_offset;
		y = tetris_piece->coords[i + 1] + tetris_piece->y_offset;
	}
	return (i == 8);
}

void	place_piece(t_piece *tetris_piece, t_grid *grid, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = tetris_piece->coords[i] + tetris_piece->x_offset;
		y = tetris_piece->coords[i + 1] + tetris_piece->y_offset;
		grid->array[y][x] = letter;
		i += 2;
	}
}

int		inside_grid(t_piece *tetris_piece, int size, char axis)
{
	if (axis == 'y')
		return (tetris_piece->coords[1] + tetris_piece->y_offset < size &&
				tetris_piece->coords[3] + tetris_piece->y_offset < size &&
				tetris_piece->coords[5] + tetris_piece->y_offset < size &&
				tetris_piece->coords[7] + tetris_piece->y_offset < size);
	else
		return (tetris_piece->coords[0] + tetris_piece->x_offset < size &&
				tetris_piece->coords[2] + tetris_piece->x_offset < size &&
				tetris_piece->coords[4] + tetris_piece->x_offset < size &&
				tetris_piece->coords[6] + tetris_piece->x_offset < size);
}

int		solve_tetris(t_piece *tetris_piece, t_grid *grid, int size)
{
	if (!tetris_piece)
		return (1);
	tetris_piece->x_offset = 0;
	tetris_piece->y_offset = 0;
	while (inside_grid(tetris_piece, size, 'y'))
	{
		while (inside_grid(tetris_piece, size, 'x'))
		{
			if (empty_space(grid, tetris_piece))
			{
				place_piece(tetris_piece, grid, tetris_piece->piece_letter);
				if (solve_tetris(tetris_piece->next, grid, size))
					return (1);
				else
					place_piece(tetris_piece, grid, '.');
			}
			tetris_piece->x_offset++;
		}
		tetris_piece->y_offset++;
		tetris_piece->x_offset = 0;
	}
	return (0);
}

void	solve(t_piece *tetris_pieces)
{
	t_grid	*grid;
	int		size;

	size = size_grid(tetris_pieces);
	grid = create_grid(size);
	while (!solve_tetris(tetris_pieces, grid, size))
	{
		free_grid(grid, size);
		size++;
		grid = create_grid(size);
	}
	print_grid(grid, size);
	free_grid(grid, size);
}
