/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:26:51 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/08 18:38:26 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

void			tetri_map_toggle(t_tetri_map *map, uint16_t bits, t_vec2u pos)
{
	t_vec2u const	p = VEC2U(pos.x/4, pos.y/4);
	t_vec2u const	mod = VEC2U(pos.x%4, pos.y%4);

	uint16_t const	a_bits = ((bits & g_block_masks[0][4-mod.x][4-mod.y])
			<< mod.x) << (mod.y * 4);
	uint16_t const	b_bits = ((bits & g_block_masks[1][4-mod.x][4-mod.y])
			>> (4 - mod.x)) << (mod.y * 4);
	uint16_t const	c_bits = ((bits & g_block_masks[2][4-mod.x][4-mod.y])
			>> ((4 - mod.y) * 4)) << mod.x;
	uint16_t const	d_bits = ((bits & g_block_masks[3][4-mod.x][4-mod.y])
			>> (4 - mod.x)) >> ((4 - mod.y) * 4);

	TETRI_MAP_BLOCK(map, p.x    , p.y    ) ^= a_bits;
	TETRI_MAP_BLOCK(map, p.x + 1, p.y    ) ^= b_bits;
	TETRI_MAP_BLOCK(map, p.x    , p.y + 1) ^= c_bits;
	TETRI_MAP_BLOCK(map, p.x + 1, p.y + 1) ^= d_bits;
}
