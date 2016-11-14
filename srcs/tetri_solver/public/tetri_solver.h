/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_solver.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:26:11 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/14 14:27:36 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_SOLVER_H
# define TETRI_SOLVER_H

# include "ft/ft_vector.h"
# include "ft/libft.h"

# include "tetriminos.h"

typedef struct s_tetri_pos			t_tetri_pos;
typedef struct s_tetri_solution		t_tetri_solution;

/*
** ========================================================================== **
*/

struct		s_tetri_pos
{
	t_tetri const	*tetri;
	t_vec2u			pos;
};

struct		s_tetri_solution
{
	uint32_t		map_size;
	uint32_t		count;
	t_tetri_pos		tetris[0];
};

/*
** Solve
** -
** Return a solution object (that can be freed with 'free')
*/
t_tetri_solution	*tetri_solve(t_vector const *tetris);

#endif
