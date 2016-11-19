/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:30:23 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/19 15:40:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_parser.h"

#define TETRI_H_LINE		0b1111
#define TETRI_V_LINE		0b0001000100010001

static uint32_t	bit_count(uint32_t n)
{
	n = n - ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

uint16_t		tetri_align(uint16_t bits)
{
	if (bits == 0)
		return (0);
	while (!(bits & TETRI_H_LINE))
		bits >>= 1 * 4;
	while (!(bits & TETRI_V_LINE))
		bits >>= 1;
	return (bits);
}

static bool		tetri_check_neighbor(uint16_t bits, uint16_t mask,
					uint32_t shift)
{
	uint16_t		l;

	while (true)
	{
		l = bits & mask;
		bits = (bits & ~mask) >> shift;
		if (!(bits & l))
			break ;
	}
	return (bits == 0);
}

bool			tetri_check(uint16_t bits)
{
	return (bit_count(bits) == 4
		&& tetri_check_neighbor(bits, TETRI_H_LINE, 4)
		&& tetri_check_neighbor(bits, TETRI_V_LINE, 1));
}
