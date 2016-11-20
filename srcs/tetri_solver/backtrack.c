/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:37:12 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/20 16:52:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#define VEC2U_SSUB(A, B)	(VEC2U((A) - (B).x, (A) - (B).y))

static bool		place_tetri(t_tetri_pool *t, t_tetri_map const *map)
{
	t_vec2u const	clip = VEC2U_SSUB(map->side_size, t->clip);
	uint32_t		x;
	uint32_t		y;
	uint64_t		bits;

	x = t->pos.x;
	y = t->pos.y;
	while (y <= clip.y)
	{
		while (x <= clip.x)
		{
			bits = TETRI_MAP_BLOCK(map, x >> 2, y >> 2)
					>> ((y & 0b11) * 8 + (x & 0b11));
			if ((bits & t->bits) == 0)
			{
				t->pos = VEC2U(x, y);
				return (true);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (false);
}

bool			tetri_backtrack(t_tetri_pool *pool, t_tetri_map *map,
					uint32_t len)
{
	uint32_t		i;

	i = 0;
	while (true)
		if (place_tetri(&pool[i], map))
		{
			tetri_map_toggle(map, pool[i].bits, pool[i].pos);
			if (++i == len)
				return (true);
			if (pool[i].required != i)
			{
				pool[i].pos = pool[pool[i].required].pos;
				pool[i].pos.x += pool[i].step;
			}
		}
		else
		{
			pool[i].pos = VEC2U(0, 0);
			if (i-- == 0)
				return (false);
			tetri_map_toggle(map, pool[i].bits, pool[i].pos);
			++pool[i].pos.x;
		}
}
