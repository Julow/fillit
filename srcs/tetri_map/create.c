/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 19:01:54 by jaguillo          #+#    #+#             */
/*   Updated: 2016/11/18 11:37:15 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "tetri_map.h"

t_tetri_map		*tetri_map_create(uint32_t size)
{
	uint32_t const		side_blocks = (size + 1 + 3) / 4 + 1;
	uint32_t const		side_mod = (size + 1 + 3) % 4;
	uint32_t			total_size;
	uint32_t			i;
	t_tetri_map			*map;

	total_size = sizeof(uint64_t) * MAX(side_blocks * side_blocks, 4);
	map = MALLOC(sizeof(t_tetri_map) + total_size);
	map->side_size = size;
	map->side_blocks = side_blocks;
	ft_bzero(&map->map, total_size);
	i = 0;
	while (i < (side_blocks-1))
	{
		tetri_map_toggle(map, 0b0001000100010001,
			VEC2U((side_blocks - 2) * 4 + side_mod, i * 4));
		tetri_map_toggle(map, 0b1111,
			VEC2U(i * 4, (side_blocks - 2) * 4 + side_mod));
		i++;
	}
	return (map);
}
