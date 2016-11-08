/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_solver.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:26:11 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/08 18:42:25 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_SOLVER_H
# define TETRI_SOLVER_H

# include "ft/libft.h"

# include "tetri_map.h"
# include "tetriminos.h"

typedef struct s_tetri_pos			t_tetri_pos;

/*
** ========================================================================== **
*/

struct		s_tetri_pos
{
	t_tetri const	*tetri;
	t_vec2u			pos;
};

static char const	tetri_line[][4] = {
	[0] = "\0\0\0\0",
	[1] = "\1\0\0\0",
	[2] = "\0\1\0\0",
	[3] = "\1\1\0\0",
	[4] = "\0\0\1\0",
	[5] = "\1\0\1\0",
	[6] = "\0\1\1\0",
	[7] = "\1\1\1\0",
	[8] = "\0\0\0\1",
	[9] = "\1\0\0\1",
	[10] = "\0\1\0\1",
	[11] = "\1\1\0\1",
	[12] = "\0\0\1\1",
	[13] = "\1\0\1\1",
	[14] = "\0\1\1\1",
	[15] = "\1\1\1\1",
};

static void		put_tetri_line(char *dst, uint16_t bits, char id, uint32_t shift)
{
	char const *const	line = tetri_line[(bits >> shift) & TETRI_H_LINE];

	if (line[0])
		dst[0] = line[0] * id;
	if (line[1])
		dst[1] = line[1] * id;
	if (line[2])
		dst[2] = line[2] * id;
	if (line[3])
		dst[3] = line[3] * id;
}

static void		print_solution(t_tetri_pos const *path, uint32_t len, uint32_t map_size)
{
	char				tab[map_size][map_size];
	t_tetri_pos const	*t;
	uint32_t			i;

	ft_memset(tab, '.', sizeof(tab));
	i = 0;
	while (i < len)
	{
		t = &path[i];
		ft_printf("TETRI#%d AT %d,%d%n", t->tetri->id, t->pos.x, t->pos.y);
		put_tetri_line(&tab[t->pos.y + 0][t->pos.x], t->tetri->bits, t->tetri->id + 'A', 0);
		put_tetri_line(&tab[t->pos.y + 1][t->pos.x], t->tetri->bits, t->tetri->id + 'A', 4);
		put_tetri_line(&tab[t->pos.y + 2][t->pos.x], t->tetri->bits, t->tetri->id + 'A', 8);
		put_tetri_line(&tab[t->pos.y + 3][t->pos.x], t->tetri->bits, t->tetri->id + 'A', 12);
		i++;
	}
	ft_printf("Map size: %d\n", map_size);
	i = 0;
	while (i < map_size)
		ft_printf("%.*s\n", map_size, tab[i++]);
	ft_printf("%!");
}

static bool		place_tetri(t_vec2u *pos, t_tetri_map const *map,
					t_tetri const *tetri)
{
	*pos = VEC2U(0, 0);
	while (pos->y < map->side_size)
	{
		pos->x = 0;
		while (pos->x < map->side_size)
		{
			if ((tetri_map_get(map, *pos) & tetri->bits) == 0)
				return (true);
			pos->x++;
		}
		pos->y++;
	}
	return (false);
}

bool			tetri_backtrack(t_tetri const **pool, t_tetri_pos *path,
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
			if (place_tetri(&path[path_i].pos, map, tetri))
			{
				tetri_map_toggle(map, tetri->bits, path[path_i].pos);
				if (tetri_backtrack(pool, path, map, len, path_i + 1))
					return (true);
				tetri_map_toggle(map, tetri->bits, path[path_i].pos);
			}
			pool[i] = tetri;
		}
		i++;
	}
	return (false);
}

uint32_t		isqrt(uint32_t num)
{
	uint32_t	r;

	r = num / 2;
	if (num == 0)
		return (num);
	while (r * r >= num)
		r--;
	return (r + 1);
}

#include <stdlib.h>

void			tetri_solve(t_vector const *tetris, t_vector *solution)
{
	t_tetri const	*pool[tetris->length];
	t_tetri_pos		path[tetris->length];
	t_tetri_map		*map;
	uint32_t		map_size;
	uint32_t		i;

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
	print_solution(path, tetris->length, map_size); // TODO: report solution
	free(map);
}

#endif
