/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:33:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/18 13:51:12 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

uint16_t		tetri_map_get(t_tetri_map const *map, t_vec2u pos)
{
	uint64_t const	bits = BLOCK_NORM(
			TETRI_MAP_BLOCK(map, pos.x >> 2, pos.y >> 2),
			pos.x & 0b11, pos.y & 0b11);

	return (0
		| (uint16_t)((bits & (0b1111 <<  0)) >>  0)
		| (uint16_t)((bits & (0b1111 <<  8)) >>  4)
		| (uint16_t)((bits & (0b1111 << 16)) >>  8)
		| (uint16_t)((bits & (0b1111 << 24)) >> 12));
}
