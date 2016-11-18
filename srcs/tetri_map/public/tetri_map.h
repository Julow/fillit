/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:54:14 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/18 19:54:57 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_MAP_H
# define TETRI_MAP_H

# include "ft/libft.h"

typedef struct s_tetri_map	t_tetri_map;

/*
** ========================================================================== **
** tetri_map
** -
** Store bits in a square of 'side_size'
** Is composed of 8*8 blocks overlapping each other with a step of 4
** Example: A stores its neighbors like this: 
** 		A B
** 		C D
*/

/*
** side_size		=> side size in bit
** side_blocks		=> side size in block (also line stride)
** map				=> blocks (array of 8*8 bits blocks with a step of 4)
** -
** TETRI_MAP_BLOCK(MAP+, X, Y)	Return the block at X, Y
*/
struct	s_tetri_map
{
	uint32_t		side_size;
	uint32_t		side_blocks;
	uint64_t		map[0];
};

# define TETRI_MAP_BLOCK(M, X, Y)		((M)->map[(Y) * (M)->side_blocks + (X)])

/*
** Create a square tetri_map with side 'size'
** Overflow area is guarded by an active bit (1) (to the right and bottom)
** -
** Params:
** 	'size'		Side size (in bit)
** Return:
**  A dynamically allocated tetri_map
**  (can be free with 'free')
*/
t_tetri_map		*tetri_map_create(uint32_t size);

/*
** Toggle the block 'bits' at pos
** -
** Params:
** 	'pos'		Position (in bit) in 'map'
*/
void			tetri_map_toggle(t_tetri_map *map, uint16_t bits, t_vec2u pos);

/*
** Return the a 4*4 sample of the map at 'pos'
** -
** Params:
** 	'pos'		Position (in bit)
*/
uint16_t		tetri_map_get(t_tetri_map const *map, uint32_t x, uint32_t y);

/*
** Tranform a 4*4 bits to a 8*8 bits.
*/
uint64_t		tetri_16to64(uint16_t bits);

#endif
