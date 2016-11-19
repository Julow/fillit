/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:20:04 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/19 15:18:22 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "ft/libft.h"

typedef struct s_tetri		t_tetri;

/*
** ========================================================================== **
** Tetri
*/

# define TETRI_H_LINE		0b1111
# define TETRI_V_LINE		0b0001000100010001

struct	s_tetri
{
	uint16_t		bits;
	t_vec2u			clip;
};

void			create_tetri(uint16_t bits, t_tetri *dst);

#endif
