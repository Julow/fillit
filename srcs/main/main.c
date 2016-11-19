/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 16:07:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "tetri_map.h"
#include "tetri_parser.h"
#include "tetri_solver.h"

#include <stdlib.h>

static char const	g_colors[][5] = {
	"\033[36m",
	"\033[94m",
	"\033[93m",
	"\033[92m",
	"\033[91m",
	"\033[90m",
	"\033[37m",
	"\033[35m",
	"\033[31m",
	"\033[34m",
	"\033[96m",
	"\033[95m",
	"\033[33m",
	"\033[32m",
	"\033[97m",
};

static void		print_solution(t_tetri_solution const *sol)
{
	char				tab[sol->map_size][sol->map_size][6];
	t_tetri_pos const	*t;
	uint32_t			i;
	uint32_t			j;

	i = 0;
	while (i < sol->map_size)
	{
		j = 0;
		while (j < sol->map_size)
		{
			ft_memcpy(tab[i][j], "\033[39m.", 6);
			j++;
		}
		i++;
	}

	i = 0;
	while (i < sol->count)
	{
		t = &sol->tetris[i];

		j = 0;
		while (j < 16)
		{
			char *dst = tab[t->pos.y + j/4][t->pos.x + j%4];
			if (t->tetri & (1 << j))
			{
				ft_memcpy(dst, g_colors[i % ARRAY_LEN(g_colors)], 5);
				dst[5] = 'A' + i;
			}
			j++;
		}

		i++;
	}

	i = 0;
	while (i < sol->map_size)
		ft_printf("%.*s\033[39m\n", sol->map_size * 6, tab[i++]);
	ft_printf("%!");
}

int				main(int argc, char **argv)
{
	t_file_in			*in;
	t_vector			tetris;
	t_tetri_solution	*solution;

	if ((in = (argc > 1) ?
			ft_in_open(ft_sub(argv[1], 0, -1)) :
			ft_in_fdopen(0)) == NULL)
	{
		ft_dprintf(2, "error%n");
		return (1);
	}
	tetris = VECTOR(uint16_t);
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
