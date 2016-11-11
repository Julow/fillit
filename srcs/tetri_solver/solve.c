/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:45:58 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/11 20:01:24 by jaguillo         ###   ########.fr       */
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

static bool		tetri_backtrack(t_tetri const **pool, t_tetri_pos *path,
					t_tetri_map *map, uint32_t len, uint32_t path_i)
{
	t_tetri const	*tetri; 
	uint32_t		i;

	i = 0;
	if (len == path_i)
		return (true);
	while (i < len)
	{
		tetri = pool[i];
		if (tetri != NULL)
		{
			pool[i] = NULL;
			path[path_i] = (t_tetri_pos){tetri, {0, 0}};
			while (place_tetri(&path[path_i].pos, map, tetri))
			{
				tetri_map_toggle(map, tetri->bits, path[path_i].pos);
				if (tetri_backtrack(pool, path, map, len, path_i + 1))
					return (true);
				tetri_map_toggle(map, tetri->bits, path[path_i].pos);
				path[path_i].pos.x++;
			}
			pool[i] = tetri;
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

static t_tetri_solution	*build_solution(t_tetri_pos const *path,
							uint32_t len, uint32_t map_size)
{
	t_tetri_solution		*solution;

	solution = MALLOC(sizeof(t_tetri_solution) + sizeof(t_tetri_pos) * len);
	solution->map_size = map_size;
	solution->count = len;
	ft_memcpy(solution->tetris, path, sizeof(t_tetri_pos) * len);
	return (solution);
}

t_tetri_solution	*tetri_solve(t_vector const *tetris)
{
	t_tetri const		*pool[tetris->length];
	t_tetri_pos			path[tetris->length];
	t_tetri_map			*map;
	uint32_t			map_size;
	uint32_t			i;

	i = 0;
	while (i < tetris->length)
	{
		pool[i] = VECTOR_GET(*tetris, i);
		i++;
	}
	map_size = isqrt(tetris->length * 4);
	while (true)
	{
		map = tetri_map_create(map_size);
		if (tetri_backtrack(pool, path, map, tetris->length, 0))
			break ;
		free(map);
		map_size++;
	}
	free(map);
	return (build_solution(path, tetris->length, map_size));
}
