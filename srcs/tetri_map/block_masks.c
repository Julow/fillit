/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_masks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:16:16 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/05 19:53:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

/*
** ?omg
** #
** TETRI_SIZE = 4
** #
** def get_mask(x, y):
** 	line_mask = 0
** 	for _ in range(x):
** 		line_mask = (line_mask << 1) | 1
** 	mask = 0
** 	for i in range(y):
** 		mask |= line_mask << (4 * i)
** 	return mask
** #
** def block_repr(bits):
** 	tmp = "{:016b}".format(bits)[::-1]
** 	return tmp[:4] + "\n" + tmp[4:8] + "\n" + tmp[8:12] + "\n" + tmp[12:]
** #
** out("\n")
** out("static uint16_t const	g_block_masks[][][] = {\n")
** #
** side = range(TETRI_SIZE+1)
** #
** masks = [[get_mask(x, y) for y in side] for x in side]
** #
** for mask in [
** 		masks,
** 		[[masks[4-x][y] << x for y in side] for x in side],
** 		[[masks[x][4-y] << (y * 4) for y in side] for x in side],
** 		[[masks[4-x][4-y] << (x + y*4) for y in side] for x in side],
** 	]:
** 	out("\t{\n")
** 	for line in mask:
** 		out("\t\t{%s},\n" % ", ".join(["{:#06x}".format(m) for m in line]))
** 	out("\t},\n")
** #
** out("};\n")
** out("\n")
*/

uint16_t const		g_block_masks[4][5][5] = {
	{
		{0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
		{0x0000, 0x0001, 0x0011, 0x0111, 0x1111},
		{0x0000, 0x0003, 0x0033, 0x0333, 0x3333},
		{0x0000, 0x0007, 0x0077, 0x0777, 0x7777},
		{0x0000, 0x000f, 0x00ff, 0x0fff, 0xffff},
	},
	{
		{0x0000, 0x000f, 0x00ff, 0x0fff, 0xffff},
		{0x0000, 0x000e, 0x00ee, 0x0eee, 0xeeee},
		{0x0000, 0x000c, 0x00cc, 0x0ccc, 0xcccc},
		{0x0000, 0x0008, 0x0088, 0x0888, 0x8888},
		{0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	},
	{
		{0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
		{0x1111, 0x1110, 0x1100, 0x1000, 0x0000},
		{0x3333, 0x3330, 0x3300, 0x3000, 0x0000},
		{0x7777, 0x7770, 0x7700, 0x7000, 0x0000},
		{0xffff, 0xfff0, 0xff00, 0xf000, 0x0000},
	},
	{
		{0xffff, 0xfff0, 0xff00, 0xf000, 0x0000},
		{0xeeee, 0xeee0, 0xee00, 0xe000, 0x0000},
		{0xcccc, 0xccc0, 0xcc00, 0xc000, 0x0000},
		{0x8888, 0x8880, 0x8800, 0x8000, 0x0000},
		{0x0000, 0x0000, 0x0000, 0x0000, 0x0000},
	},
};

/*
** ?end
*/
