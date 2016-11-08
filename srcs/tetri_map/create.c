/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:01:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/08 18:54:14 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

t_tetri_map		*tetri_map_create(uint32_t size)
{
	uint32_t const		side_blocks = (size + 1 + 3) / 4;
	uint32_t const		side_mod = (size + 1 + 3) % 4;
	uint32_t			total_size;
	uint32_t			i;
	t_tetri_map			*map;

	total_size = sizeof(uint16_t) * MAX(side_blocks * side_blocks, 4);
	map = MALLOC(sizeof(t_tetri_map) + total_size);
	map->side_size = size;
	map->side_blocks = side_blocks;
	ft_bzero(&map->map, total_size);
	i = 0;
	while (i < side_blocks)
	{
		TETRI_MAP_BLOCK(map, side_blocks-1, i) |= 0b0001000100010001 << side_mod;
		TETRI_MAP_BLOCK(map, i, side_blocks-1) |= 0b1111 << (side_mod * 4);
		i++;
	}
	return (map);
}
