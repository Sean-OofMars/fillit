/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferreir <sferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:09:11 by sferreir          #+#    #+#             */
/*   Updated: 2019/12/04 14:32:57 by sferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_pieces(t_piece *tetris_pieces)
{
	t_piece *curr;

	while (tetris_pieces)
	{
		curr = tetris_pieces;
		tetris_pieces = tetris_pieces->next;
		free(curr);
	}
}

t_piece	*align_piece(t_piece *ptr_piece)
{
	int		i;

	i = 0;
	while (ptr_piece->coords[i] != 0)
	{
		if (i == 6)
		{
			shift_x(ptr_piece);
			i = 0;
		}
		else
			i += 2;
	}
	i = 1;
	while (ptr_piece->coords[i] != 0)
	{
		if (i == 7)
		{
			shift_y(ptr_piece);
			i = 1;
		}
		else
			i += 2;
	}
	return (ptr_piece);
}

t_piece	*save_piece(char *tmp_piece, char letter)
{
	int		i;
	int		coord_count;
	t_piece	*ptr_piece;

	i = 0;
	coord_count = 0;
	if (!(ptr_piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (tmp_piece[i] == '#')
		{
			ptr_piece->coords[coord_count] = i % 5;
			coord_count++;
			ptr_piece->coords[coord_count] = i / 5;
			coord_count++;
		}
		i++;
	}
	ptr_piece->x_offset = 0;
	ptr_piece->y_offset = 0;
	ptr_piece->piece_letter = letter;
	return (align_piece(ptr_piece));
}

t_piece	*create_pieces(char *src, int size)
{
	t_piece	*curr;
	t_piece	*start;
	int		i;
	char	letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			start = save_piece(src + i, letter);
			curr = start;
		}
		else
		{
			curr->next = save_piece(src + i, letter);
			curr = curr->next;
		}
		letter++;
		i += 21;
	}
	curr->next = NULL;
	return (start);
}

t_piece	*create_source(char *file)
{
	char	src[576];
	int		fd;
	int		count;

	fd = open(file, O_RDONLY);
	count = read(fd, src, 576);
	close(fd);
	if (count < 19 || count > 575)
		return (NULL);
	src[count] = '\0';
	if (!valid(src, count))
		return (NULL);
	return (create_pieces(src, count));
}
