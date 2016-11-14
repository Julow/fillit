/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/14 15:24:40 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#include <stdlib.h>

static bool		place_tetri(t_vec2u *pos, t_tetri_map const *map,
					t_tetri const *tetri)
{
	while (pos->y < map->side_size)
	{
		while (pos->x < map->side_size)
		{
			if ((tetri_map_get(map, *pos) & tetri->bits) == 0)
				return (true);
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
	return (false);
}

static bool		tetri_backtrack(t_tetri_pool *pool, t_tetri_map *map,
					uint32_t len, uint32_t path_i)
{
	t_tetri const	*tetri; 
	uint32_t		i;

	i = 0;
	if (len == path_i)
		return (true);
	while (i < len)
	{
		if (!pool[i].used)
		{
			pool[i].used = true;
			if (pool[pool[i].required].used)
			{
				tetri = pool[i].tetri;
				pool[i].pos = pool[pool[i].required].pos;
				while (place_tetri(&pool[i].pos, map, tetri))
				{
					tetri_map_toggle(map, tetri->bits, pool[i].pos);
					if (tetri_backtrack(pool, map, len, path_i + 1))
						return (true);
					tetri_map_toggle(map, tetri->bits, pool[i].pos);
					pool[i].pos.x++;
				}
				pool[i].pos = VEC2U(0, 0);
			}
			pool[i].used = false;
		}
		i++;
	}
	return (false);
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
			false,
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
		if (tetri_backtrack(pool, map, tetris->length, 0))
			break ;
		free(map);
		map_size++;
	}
	free(map);
	return (build_solution(pool, tetris->length, map_size));
}
