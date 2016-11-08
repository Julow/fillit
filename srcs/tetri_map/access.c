/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:33:00 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/08 18:06:46 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

uint16_t		tetri_map_get(t_tetri_map const *map, t_vec2u pos)
{
	t_vec2u const	p = VEC2U(pos.x / 4, pos.y / 4);
	t_vec2u const	mod = VEC2U(pos.x % 4, pos.y % 4);

	return ((((TETRI_MAP_BLOCK(map, p.x, p.y)
					& g_block_masks[3][mod.x][mod.y])
				>> (mod.y * 4)) >> mod.x)
		| (((TETRI_MAP_BLOCK(map, p.x + 1, p.y)
					& g_block_masks[2][mod.x][mod.y])
				>> (mod.y * 4)) << (4 - mod.x))
		| (((TETRI_MAP_BLOCK(map, p.x, p.y + 1)
					& g_block_masks[1][mod.x][mod.y])
				<< ((4 - mod.y) * 4)) >> mod.x)
		| (((TETRI_MAP_BLOCK(map, p.x + 1, p.y + 1)
					& g_block_masks[0][mod.x][mod.y])
				<< ((4 - mod.y) * 4)) << (4 - mod.x)));
}
