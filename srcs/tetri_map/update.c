/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:26:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/18 17:05:05 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

uint64_t		tetri_16to64(uint16_t bits) // TODO: move
{
	return (((uint64_t)(bits & (0b1111 <<  0))) <<  0
		| ((uint64_t)(bits & (0b1111 <<  4))) <<  4
		| ((uint64_t)(bits & (0b1111 <<  8))) <<  8
		| ((uint64_t)(bits & (0b1111 << 12))) << 12);
}

void			tetri_map_toggle(t_tetri_map *map, uint16_t bits, t_vec2u pos)
{
	uint64_t		bits64;
	uint64_t		*dst;
	int32_t const	y = map->side_blocks;

	bits64 = BLOCK_MOVE(tetri_16to64(bits), pos.x & 0b11, pos.y & 0b11);
	dst = map->map + ((pos.y >> 2) * map->side_blocks) + (pos.x >> 2);
	if (pos.y >= 4)
	{
		if (pos.x >= 4)
			dst[-y - 1] ^= (bits64 & 0x000000000f0f0f0f) << 36;
		dst[-y] ^= (bits64 & 0x00000000ffffffff) << 32;
		dst[-y + 1] ^= (bits64 & 0x00000000f0f0f0f0) << 28;
	}
	if (pos.x >= 4)
		dst[-1] ^= (bits64 & 0x0f0f0f0f0f0f0f0f) << 4;
	dst[0] ^= bits64;
	dst[1] ^= (bits64 & 0xf0f0f0f0f0f0f0f0) >> 4;
	if (pos.x >= 4)
		dst[y - 1] ^= (bits64 & 0x0f0f0f0f00000000) >> 28;
	dst[y] ^= (bits64 & 0xffffffff00000000) >> 32;
	dst[y + 1] ^= (bits64 & 0xf0f0f0f000000000) >> 36;
}
