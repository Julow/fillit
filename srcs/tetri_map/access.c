/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:33:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 19:16:28 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

uint16_t		tetri_map_get(t_tetri_map const *map, uint32_t x, uint32_t y)
{
	uint64_t		bits;

	bits = BLOCK_NORM(TETRI_MAP_BLOCK(map, x >> 2, y >> 2), x & 0b11, y & 0b11);
	return ((uint16_t)((bits & (0b1111 << 0)) >> 0)
		| (uint16_t)((bits & (0b1111 << 8)) >> 4)
		| (uint16_t)((bits & (0b1111 << 16)) >> 8)
		| (uint16_t)((bits & (0b1111 << 24)) >> 12));
}
