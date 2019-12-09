/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferreir <sferreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:06:19 by sferreir          #+#    #+#             */
/*   Updated: 2019/12/04 14:33:47 by sferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h>

typedef struct		s_piece
{
	int				coords[8];
	char			piece_letter;
	int				x_offset;
	int				y_offset;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_grid
{
	char			**array;
}					t_grid;

void				free_pieces(t_piece *tetris_pieces);
t_piece				*align_piece(t_piece *ptr_piece);
t_piece				*save_piece(char *tmp_piece, char letter);
t_piece				*create_pieces(char *src, int size);
t_piece				*create_source(char *file);
void				print_grid(t_grid *grid, int size);
void				free_grid(t_grid *grid, int size);
t_grid				*create_grid(int size);
int					size_grid(t_piece *tetris_piece);
void				shift_x(t_piece *ptr_piece);
void				shift_y(t_piece *ptr_piece);
int					hash_count(char *src);
int					adjac_count(char *src);
int					valid(char *src, int size);
int					empty_space(t_grid *grid, t_piece *tetris_piece);
void				place_piece(t_piece *tetris_piece,
									t_grid *grid, char letter);
int					inside_grid(t_piece *tetris_piece, int size, char axis);
int					solve_tetris(t_piece *tetris_piece, t_grid *grid, int size);
void				solve(t_piece *tetris_pieces);

#endif
