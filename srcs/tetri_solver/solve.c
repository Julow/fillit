/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 16:08:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#include <stdlib.h>

/*
** ========================================================================== **
** Backtrack
*/

static bool		place_tetri(t_tetri_pool *t, t_tetri_map const *map)
{
	t_vec2u const	clip = VEC2U(map->side_size - t->clip.x,
						map->side_size - t->clip.y);
	uint32_t		x;
	uint32_t		y;
	uint64_t		bits;

	x = t->pos.x;
	y = t->pos.y;
	while (y <= clip.y)
	{
		while (x <= clip.x)
		{
			bits = TETRI_MAP_BLOCK(map, x >> 2, y >> 2) >> ((y & 0b11) * 8 + (x & 0b11));
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

static bool		tetri_backtrack(t_tetri_pool *pool, t_tetri_map *map,
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
			pool[i].pos = pool[pool[i].required].pos;
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

/*
** ========================================================================== **
** Solution
*/

static t_tetri_solution	*build_solution(t_tetri_pool const *pool,
							t_vector const *tetris, uint32_t map_size)
{
	t_tetri_solution		*solution;
	uint32_t				i;

	solution = MALLOC(sizeof(t_tetri_solution) + sizeof(t_tetri_pos) * tetris->length);
	solution->map_size = map_size;
	solution->count = tetris->length;
	i = 0;
	while (i < tetris->length)
	{
		solution->tetris[i] = (t_tetri_pos){
			VGETC(uint16_t, *tetris, i),
			pool[i].pos
		};
		i++;
	}
	return (solution);
}

/*
** ========================================================================== **
** Build pool
*/

# define TETRI_H_LINE		0b1111
# define TETRI_V_LINE		0b0001000100010001

static t_vec2u	get_clip(uint16_t bits)
{
	t_vec2u			clip;

	clip = VEC2U(0, 0);
	while (bits & (TETRI_H_LINE << (clip.y * 4)))
		clip.y++;
	while (bits & (TETRI_V_LINE << clip.x))
		clip.x++;
	return (clip);
}

int					tetri_shape_cmp(t_tetri_shape const *shape,
						uint16_t const *key)
{
	return (shape->bits - *key);
}

static void			build_pool(t_vector const *tetris, t_tetri_pool *dst)
{
	t_set				last_occurrence;
	uint32_t			i;
	t_tetri_shape		shape[tetris->length];
	t_tetri_shape		*tmp;
	uint16_t			tetri;

	last_occurrence = SET(tetri_shape_cmp, 0);
	i = 0;
	while (i < tetris->length)
	{
		tetri = VGETC(uint16_t, *tetris, i);
		tmp = ft_set_get(&last_occurrence, &tetri);
		dst[i] = (t_tetri_pool){
			(tmp == NULL) ? i : tmp->index,
			tetri_16to64(tetri),
			{0, 0},
			get_clip(tetri)
		};
		if (tmp == NULL)
		{
			shape[i] = (t_tetri_shape){SET_HEAD(), i, tetri};
			ft_set_insert(&last_occurrence, &shape[i], &tetri);
		}
		else
			tmp->index = i;
		i++;
	}
}

/*
** ========================================================================== **
** Solver
*/

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
	return (build_solution(pool, tetris, map_size));
}
