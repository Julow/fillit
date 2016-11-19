/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:47:27 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 16:05:42 by jaguillo         ###   ########.fr       */
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
	uint32_t		required;
	uint64_t		bits;
	t_vec2u			pos;
	t_vec2u			clip;
};

struct		s_tetri_shape
{
	t_set_h			set_h;
	uint32_t		index;
	uint16_t		bits;
};

#endif
