/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 15:18:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#include <stdlib.h>

static bool		place_tetri(t_vec2u *pos, t_tetri_map const *map,
					t_tetri const *tetri)
{
	t_vec2u const	clip = VEC2U(map->side_size - tetri->clip.x,
						map->side_size - tetri->clip.y);
	uint32_t		x;
	uint32_t		y;
	uint64_t const	tetri_bits = tetri_16to64(tetri->bits);
	uint64_t		bits;

	x = pos->x;
	y = pos->y;
	while (y <= clip.y)
	{
		while (x <= clip.x)
		{
			bits = TETRI_MAP_BLOCK(map, x >> 2, y >> 2) >> ((y & 0b11) * 8 + (x & 0b11));
			if ((bits & tetri_bits) == 0)
			{
				*pos = VEC2U(x, y);
				return (true);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (false);
}

static bool		tetri_backtrack(t_tetri_pool *pool, t_tetri_map *map,
					uint32_t len)
{
	uint32_t		i;

	i = 0;
	while (true)
		if (place_tetri(&pool[i].pos, map, pool[i].tetri))
		{
			tetri_map_toggle(map, pool[i].tetri->bits, pool[i].pos);
			if (++i == len)
				return (true);
			pool[i].pos = pool[pool[i].required].pos;
		}
		else
		{
			pool[i].pos = VEC2U(0, 0);
			if (i-- == 0)
				return (false);
			tetri_map_toggle(map, pool[i].tetri->bits, pool[i].pos);
			++pool[i].pos.x;
		}
}

static uint32_t	isqrt(uint32_t num)
{
	uint32_t	r;

	r = num / 2;
	if (num == 0)
		return (num);
	while (r * r >= num)
		r--;
	return (r + 1);
}

static t_tetri_solution	*build_solution(t_tetri_pool const *pool,
							uint32_t len, uint32_t map_size)
{
	t_tetri_solution		*solution;
	uint32_t				i;

	solution = MALLOC(sizeof(t_tetri_solution) + sizeof(t_tetri_pos) * len);
	solution->map_size = map_size;
	solution->count = len;
	i = 0;
	while (i < len)
	{
		solution->tetris[i] = (t_tetri_pos){pool[i].tetri, pool[i].pos};
		i++;
	}
	return (solution);
}

int					tetri_shape_cmp(t_tetri_shape const *shape,
						t_tetri const *key)
{
	return (shape->tetri->bits - key->bits);
}

static void			build_pool(t_vector const *tetris, t_tetri_pool *dst)
{
	t_set				last_occurrence;
	uint32_t			i;
	t_tetri_shape		shape[tetris->length];
	t_tetri_shape		*tmp;
	t_tetri const		*tetri;

	last_occurrence = SET(tetri_shape_cmp, 0);
	i = 0;
	while (i < tetris->length)
	{
		tetri = VECTOR_GET(*tetris, i);
		tmp = ft_set_get(&last_occurrence, tetri);
		dst[i] = (t_tetri_pool){
			tetri,
			(tmp == NULL) ? i : tmp->index,
			{0, 0}
		};
		if (tmp == NULL)
		{
			shape[i] = (t_tetri_shape){SET_HEAD(), i, tetri};
			ft_set_insert(&last_occurrence, &shape[i], tetri);
		}
		else
			tmp->index = i;
		i++;
	}
}

t_tetri_solution	*tetri_solve(t_vector const *tetris)
{
	t_tetri_pool		pool[tetris->length];
	t_tetri_map			*map;
	uint32_t			map_size;

	build_pool(tetris, pool);
	map_size = isqrt(tetris->length * 4);
	while (true)
	{
		map = tetri_map_create(map_size);
		if (tetri_backtrack(pool, map, tetris->length))
			break ;
		free(map);
		map_size++;
	}
	free(map);
	return (build_solution(pool, tetris->length, map_size));
}
