/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/07 20:32:51 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "tetri_map.h"
#include "tetri_parser.h"
#include "tetriminos.h"

/*
** ?omg
** out("\n")
** out("static char const *const	tetri_line[] = {\n")
** for i in range(1 << 4):
** 	out("\t\"%s\"," % "{:04b}".format(i)[::-1])
** 	if (i + 1) % 8 == 0: out("\n")
** out("};\n")
** out("\n")
*/

static char const *const	tetri_line[] = {
	"0000",	"1000",	"0100",	"1100",	"0010",	"1010",	"0110",	"1110",
	"0001",	"1001",	"0101",	"1101",	"0011",	"1011",	"0111",	"1111",
};

/*
** ?end
*/

static void		print_tetris(t_vector const *tetris)
{
	t_tetri const	*t;

	t = VECTOR_IT(*tetris);
	while (VECTOR_NEXT(*tetris, t))
	{
		ft_printf("%s\n", tetri_line[(t->bits & (TETRI_H_LINE <<  0)) >>  0]);
		ft_printf("%s\n", tetri_line[(t->bits & (TETRI_H_LINE <<  4)) >>  4]);
		ft_printf("%s\n", tetri_line[(t->bits & (TETRI_H_LINE <<  8)) >>  8]);
		ft_printf("%s\n", tetri_line[(t->bits & (TETRI_H_LINE << 12)) >> 12]);
		ft_printf("%n");
	}
}

int				main(void)
{
	t_file_in *const	in = ft_in_fdopen(0);
	t_vector			tetris;

	tetris = VECTOR(t_tetri);
	if (!parse_tetris(in, &tetris))
	{
		ft_dprintf(2, "error%n");
		ft_vclear(&tetris);
		ft_in_close(in);
		return (1);
	}
	print_tetris(&tetris);
	ft_vclear(&tetris);
	ft_in_close(in);
	return (0);
}
