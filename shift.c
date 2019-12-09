/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <elee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:22:04 by sferreir          #+#    #+#             */
/*   Updated: 2019/11/26 14:33:33 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_x(t_piece *ptr_piece)
{
	ptr_piece->coords[0] -= 1;
	ptr_piece->coords[2] -= 1;
	ptr_piece->coords[4] -= 1;
	ptr_piece->coords[6] -= 1;
}

void	shift_y(t_piece *ptr_piece)
{
	ptr_piece->coords[1] -= 1;
	ptr_piece->coords[3] -= 1;
	ptr_piece->coords[5] -= 1;
	ptr_piece->coords[7] -= 1;
}
