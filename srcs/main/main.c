/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/20 16:59:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "tetri_map.h"
#include "tetri_parser.h"
#include "tetri_solver.h"

#include <stdlib.h>

static void		print_solution(t_tetri_solution const *sol)
{
	char				tab[sol->map_size][sol->map_size];
	t_tetri_pos const	*t;
	uint32_t			i;
	uint32_t			j;

	ft_memset(tab, '.', sizeof(tab));
	i = 0;
	while (i < sol->count)
	{
		t = &sol->tetris[i];
		j = 0;
		while (j < 16)
		{
			if (t->tetri & (1 << j))
				tab[t->pos.y + (j >> 2)][t->pos.x + (j & 0b11)] = 'A' + i;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < sol->map_size)
		ft_printf("%.*s\n", sol->map_size, tab[i++]);
	ft_printf("%!");
}

static int		usage(char const *arg0)
{
	ft_printf("usage: %s file%n", arg0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_file_in			*in;
	t_vector			tetris;
	t_tetri_solution	*solution;

	if (argc != 2)
		return (usage(argv[0]));
	if ((in = ft_in_open(ft_sub(argv[1], 0, -1))) == NULL)
	{
		ft_printf("error%n");
		return (1);
	}
	tetris = VECTOR(uint16_t);
	if (!parse_tetris(V(in), &tetris))
	{
		ft_printf("error%n");
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
