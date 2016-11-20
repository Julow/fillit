/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/20 14:06:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#include <stdlib.h>

static t_tetri_solution	*build_solution(t_tetri_pool const *pool,
							t_vector const *tetris, uint32_t map_size)
{
	t_tetri_solution		*solution;
	uint32_t				i;

	solution = MALLOC(sizeof(t_tetri_solution)
				+ sizeof(t_tetri_pos) * tetris->length);
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

static uint32_t			isqrt(uint32_t num)
{
	uint32_t				r;

	r = num / 2;
	if (num == 0)
		return (num);
	while (r * r >= num)
		r--;
	return (r + 1);
}

static uint32_t			initial_map_size(t_tetri_pool const *pool, uint32_t len)
{
	uint32_t				i;
	uint32_t				map_size;

	map_size = isqrt(len * 4);
	i = 0;
	while (i < len)
	{
		map_size = MAX(MAX(map_size, pool[i].clip.x), pool[i].clip.y);
		i++;
	}
	return (map_size);
}

t_tetri_solution		*tetri_solve(t_vector const *tetris)
{
	t_tetri_pool			pool[tetris->length];
	t_tetri_map				*map;
	uint32_t				map_size;

	build_pool(tetris, pool);
	map_size = initial_map_size(pool, tetris->length);
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
