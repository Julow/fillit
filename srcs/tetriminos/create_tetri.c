/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:29:10 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/18 15:11:11 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

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

void			create_tetri(uint16_t bits, t_tetri *dst)
{
	*dst = (t_tetri){bits, get_clip(bits)};
}
