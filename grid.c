/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferreir <sferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:19:46 by sferreir          #+#    #+#             */
/*   Updated: 2019/12/04 14:34:22 by sferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(t_grid *grid, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(grid->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_grid(t_grid *grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&(grid->array[i]));
		i++;
	}
	ft_memdel((void **)&(grid->array));
	ft_memdel((void **)&grid);
}

t_grid	*create_grid(int size)
{
	t_grid	*tmp_grid;
	int		i;

	i = 0;
	if (!(tmp_grid = (t_grid *)ft_memalloc(sizeof(t_grid))))
		return (NULL);
	if (!(tmp_grid->array = (char **)ft_memalloc(sizeof(char*) * size)))
		return (NULL);
	while (i < size)
	{
		tmp_grid->array[i] = ft_strnew(size);
		ft_memset(tmp_grid->array[i], '.', size);
		i++;
	}
	return (tmp_grid);
}

int		size_grid(t_piece *tetris_piece)
{
	int		i;
	int		x;
	t_piece *curr;

	i = 0;
	x = 2;
	curr = tetris_piece;
	while (curr != NULL)
	{
		i += 4;
		curr = curr->next;
	}
	while ((x * x) < i)
		x++;
	return (x);
}
