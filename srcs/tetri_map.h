/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:54:14 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/04 19:26:52 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_MAP_H
# define TETRI_MAP_H

# include "ft/libft.h"
# include "tetriminos.h"

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
	uint16_t		map[0];
};

# define TETRI_MAP_BLOCK(M, X, Y)		((M)->map[(Y) * (M)->side_blocks + (X)])

static void		enclose_map(t_tetri_map *map)
{
	uint32_t const		block_offset = (map->side_size + 1) / 4;
	uint32_t const		bit_offset = (map->side_size + 1) % 4;
	uint32_t			i;

	i = 0;
	while (i < map->side_blocks)
	{
		TETRI_MAP_BLOCK(map, block_offset, i) |= 0b1000100010001000 << bit_offset;
		TETRI_MAP_BLOCK(map, i, block_offset) |= 0b1111000000000000 << (bit_offset * TETRI_WIDTH);
		i++;
	}
}

t_tetri_map		*tetri_map_create(uint32_t size)
{
	uint32_t const		side_blocks = (size + 1) / 4;
	uint32_t const		block_count = side_blocks * side_blocks;
	t_tetri_map			*map;

	map = MALLOC(sizeof(t_tetri_map) + sizeof(uint16_t) * block_count);
	map->side_size = size;
	map->side_blocks = side_blocks;
	ft_bzero(&map->map, sizeof(uint16_t) * block_count);
	enclose_map(map);
	return (map);
}

static uint16_t	get_mask(uint32_t x, uint32_t y)
{
	static uint16_t const	LINE_MASKS[] = {
		0b0000, 0b0001, 0b0011, 0b0111, 0b1111
	};
	uint16_t const			line_mask = LINE_MASKS[x];

	return ((line_mask <<  0) * (y > 0)
		|	(line_mask <<  4) * (y > 1)
		|	(line_mask <<  8) * (y > 2)
		|	(line_mask << 12) * (y > 3));
}

void			tetri_map_insert(t_tetri_map *map, uint16_t bits,
					t_vec2u pos)
{
	t_vec2u const	p = VEC2U(pos.x/4, pos.y/4);
	t_vec2u const	mod = VEC2U(pos.x%4, pos.y%4);

	uint16_t const	a_bits = bits & (get_mask(mod.x, mod.y));
	uint16_t const	b_bits = bits & (get_mask(4 - mod.x, mod.y) << mod.x);
	uint16_t const	c_bits = bits & (get_mask(x, 4 - mod.y) << (mod.y * 4));
	uint16_t const	d_bits = bits & (get_mask(4 - mod.x, 4 - mod.y) << (mod.x + (mod.y * 4)));

	TETRI_MAP_BLOCK(map, p.x    , p.y    ) |= a_bits;
	TETRI_MAP_BLOCK(map, p.x + 1, p.y    ) |= b_bits;
	TETRI_MAP_BLOCK(map, p.x    , p.y + 1) |= c_bits;
	TETRI_MAP_BLOCK(map, p.x + 1, p.y + 1) |= d_bits;
}

uint16_t		tetri_map_get_bits_at(t_tetri_map const *map, t_vec2u pos)
{
	t_vec2u const	p = VEC2U(pos.x/4, pos.y/4);
	t_vec2u const	mod = VEC2U(pos.x%4, pos.y%4);

	uint16_t const	a = TETRI_MAP_BLOCK(map, p.x    , p.y    );
	uint16_t const	b = TETRI_MAP_BLOCK(map, p.x + 1, p.y    );
	uint16_t const	c = TETRI_MAP_BLOCK(map, p.x    , p.y + 1);
	uint16_t const	d = TETRI_MAP_BLOCK(map, p.x + 1, p.y + 1);

	return (((a << ((    mod.y) * TETRI_WIDTH)) << (    mod.x))
		|	((b << ((    mod.y) * TETRI_WIDTH)) >> (4 - mod.x))
		|	((c >> ((4 - mod.y) * TETRI_WIDTH)) << (    mod.x))
		|	((d >> ((4 - mod.y) * TETRI_WIDTH)) >> (4 - mod.x)));
}

bool			tetri_map_collide(t_tetri_map const *map, uint16_t bits,
					t_vec2u pos)
{
	return (tetri_map_get_bits_at(map, pos) & bits);
}

#endif
