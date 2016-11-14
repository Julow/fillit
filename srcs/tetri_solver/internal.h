/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:47:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/14 15:12:12 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "ft/set.h"

# include "tetri_map.h"
# include "tetri_solver.h"

typedef struct s_tetri_pool			t_tetri_pool;
typedef struct s_tetri_shape		t_tetri_shape;

/*
** ========================================================================== **
*/

struct		s_tetri_pool
{
	t_tetri const	*tetri;
	uint32_t		required;
	bool			used;
	t_vec2u			pos;
};

struct		s_tetri_shape
{
	t_set_h			set_h;
	uint32_t		index;
	t_tetri	const	*tetri;
};

#endif
