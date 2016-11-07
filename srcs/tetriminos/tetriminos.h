/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:20:04 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/07 19:34:27 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "ft/libft.h"

typedef struct s_tetri		t_tetri;

/*
** ========================================================================== **
** Tetri
*/

# define TETRI_H_LINE		0b1111
# define TETRI_V_LINE		0b0001000100010001

struct	s_tetri
{
	uint16_t	bits;
	uint16_t	id;
};

#endif
