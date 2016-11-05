/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:54:14 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/05 19:14:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_MAP_H
# define TETRI_MAP_H

# include "ft/libft.h"

typedef struct s_tetri_map	t_tetri_map;

/*
** ========================================================================== **
*/

/*
** side_size		=> side size in bit
** side_blocks		=> side size in block (also line stride)
** map				=> blocks (array of 4*4 bits blocks)
** -
** TETRI_MAP_BLOCK(MAP+, X, Y)	Return the block at X, Y
*/
struct	s_tetri_map
{
	uint32_t		side_size;
	uint32_t		side_blocks;
};

# define TETRI_MAP_BLOCK(M, X, Y)		(((uint16_t const*)ENDOF(M))[(Y) * (M)->side_blocks + (X)])

/*
** Create a square tetri_map with side 'size'
** -
** Params:
** 	'size'		Side size (in bit)
*/
t_tetri_map		*tetri_map_create(uint32_t size);

/*
** Insert the block 'bits' at pos
** -
** Params:
** 	'pos'		Position (in bit) in 'map'
*/
void			tetri_map_insert(t_tetri_map *map, uint16_t bits, t_vec2u pos);

/*
** Return the result of the bitwise AND between 'bits' and the bits at 'pos'
** Overflow area is guarded by an active bit (1) (to the right and bottom)
** -
** Params:
** 	'bits'		Mask
** 	'pos'		Position (in bit) in 'map'
*/
uint16_t		tetri_map_collide(t_tetri_map const *map, uint16_t bits,
					t_vec2u pos);

#endif
