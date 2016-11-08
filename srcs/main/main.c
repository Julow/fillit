/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 20:03:06 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/08 18:58:12 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/file_in.h"
#include "ft/ft_in.h"
#include "ft/ft_printf.h"

#include "tetri_map.h"
#include "tetri_parser.h"
#include "tetri_solver.h"
#include "tetriminos.h"

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
	tetri_solve(&tetris, NULL);

	ft_vclear(&tetris);
	ft_in_close(in);
	return (0);
}
