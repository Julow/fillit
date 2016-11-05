/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:01:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/05 19:15:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

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