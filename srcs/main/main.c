/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/18 14:49:29 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "tetri_map.h"
#include "tetri_parser.h"
#include "tetri_solver.h"
#include "tetriminos.h"

#include <stdlib.h>

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

static void		print_solution(t_tetri_solution const *sol)
{
	char				tab[sol->map_size][sol->map_size];
	t_tetri_pos const	*t;
	uint32_t			i;

	ft_memset(tab, '.', sizeof(tab));
	i = 0;
	while (i < sol->count)
	{
		t = &sol->tetris[i];
		// ft_printf("TETRI#%d AT %d,%d%n", t->tetri->id, t->pos.x, t->pos.y);
		put_tetri_line(&tab[t->pos.y + 0][t->pos.x], t->tetri->bits, i + 'A', 0);
		put_tetri_line(&tab[t->pos.y + 1][t->pos.x], t->tetri->bits, i + 'A', 4);
		put_tetri_line(&tab[t->pos.y + 2][t->pos.x], t->tetri->bits, i + 'A', 8);
		put_tetri_line(&tab[t->pos.y + 3][t->pos.x], t->tetri->bits, i + 'A', 12);
		i++;
	}
	// ft_printf("Map size: %d\n", sol->map_size);
	i = 0;
	while (i < sol->map_size)
		ft_printf("%.*s\n", sol->map_size, tab[i++]);
	ft_printf("%!");
}

int				main(int argc, char **argv)
{
	t_file_in			*in;
	t_vector			tetris;
	t_tetri_solution	*solution;

	if (argc != 2 || (in = ft_in_open(ft_sub(argv[1], 0, -1))) == NULL)
	{
		ft_dprintf(2, "error%n");
		return (1);
	}
	tetris = VECTOR(t_tetri);
	if (!parse_tetris(V(in), &tetris))
	{
		ft_dprintf(2, "error%n");
		ft_vclear(&tetris);
		ft_in_close(in);
		return (1);
	}
	solution = tetri_solve(&tetris);
	print_solution(solution);
	free(solution);

	ft_vclear(&tetris);
	ft_in_close(in);
	return (0);
}
