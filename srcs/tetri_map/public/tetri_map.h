/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:54:14 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/16 17:42:00 by ccompera         ###   ########.fr       */
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
uint16_t		tetri_map_get(t_tetri_map const *map, t_vec2u pos);

#endif
