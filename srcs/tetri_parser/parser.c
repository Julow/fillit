/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:29:49 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/07 19:49:04 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_parser.h"

static bool		get_next_tetri(t_in *in, uint16_t *dst)
{
	t_vec2u			i;
	char			c;

	i = VEC2U(0, 0);
	while (i.y < 4)
	{
		i.x = 0;
		while (i.x < 4)
		{
			if (!IN_REFRESH(in))
				return (false);
			c = in->buff[in->buff_i++];
			if (c == TETRI_CHAR_EMPTY)
				;
			else if (c == TETRI_CHAR_FULL)
				*dst |= (1 << i.x) << (i.y * 4);
			else
				return (false);
			++i.x;
		}
		if (IN_REFRESH(in) && in->buff[in->buff_i++] != '\n')
			return (false);
		++i.y;
	}
	return (true);
}

bool			parse_tetris(t_in *in, t_vector *dst)
{
	t_tetri			tetri;

	tetri = (t_tetri){0, 0};
	while (true)
	{
		tetri.bits = 0;
		if (!get_next_tetri(in, &tetri.bits))
			return (false);
		tetri.bits = tetri_align(tetri.bits);
		if (!tetri_check(tetri.bits))
			return (false);
		ft_vpush(dst, &tetri, 1);
		tetri.id++;
		if (!IN_REFRESH(in))
			break ;
		if (in->buff[in->buff_i++] != '\n')
			return (false);
	}
	return (true);
}
