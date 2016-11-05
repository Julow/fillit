/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:20:04 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/05 19:21:10 by jaguillo         ###   ########.fr       */
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

struct	s_tetri
{
	uint16_t	bits;
	uint16_t	id;
};

#endif
