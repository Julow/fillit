/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:36:11 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/19 19:26:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_solver.h"

#define TETRI_H_LINE		0b1111
#define TETRI_V_LINE		0b0001000100010001

static t_vec2u	get_clip(uint16_t bits)
{
	t_vec2u			clip;

	clip = VEC2U(0, 0);
	while (bits & (TETRI_H_LINE << (clip.y * 4)))
		clip.y++;
	while (bits & (TETRI_V_LINE << clip.x))
		clip.x++;
	return (clip);
}

static uint32_t	get_step(uint16_t bits)
{
	uint16_t		steps;
	uint32_t		max;

	steps = (bits >> 0) & TETRI_V_LINE
		+ (bits >> 4) & TETRI_V_LINE
		+ (bits >> 8) & TETRI_V_LINE
		+ (bits >> 12) & TETRI_V_LINE;
	max = (steps >> 0) & 0b1111;
	max = MAX(max, (steps >> 4) & 0b1111);
	max = MAX(max, (steps >> 8) & 0b1111);
	max = MAX(max, (steps >> 12) & 0b1111);
	return (max);
}

static int		tetri_shape_cmp(t_tetri_shape const *shape,
						uint16_t const *key)
{
	return (shape->bits - *key);
}

void			build_pool(t_vector const *tetris, t_tetri_pool *dst)
{
	t_set				last_occurrence;
	uint32_t			i;
	t_tetri_shape		shape[tetris->length];
	t_tetri_shape		*tmp;
	uint16_t			tetri;

	last_occurrence = SET(tetri_shape_cmp, 0);
	i = 0;
	while (i < tetris->length)
	{
		tetri = VGETC(uint16_t, *tetris, i);
		tmp = ft_set_get(&last_occurrence, &tetri);
		dst[i] = (t_tetri_pool){ tetri_16to64(tetri), {0, 0}, get_clip(tetri),
				(tmp == NULL) ? i : tmp->index, get_step(tetri) };
		if (tmp == NULL)
		{
			shape[i] = (t_tetri_shape){SET_HEAD(), i, tetri};
			ft_set_insert(&last_occurrence, &shape[i], &tetri);
		}
		else
			tmp->index = i;
		i++;
	}
}
