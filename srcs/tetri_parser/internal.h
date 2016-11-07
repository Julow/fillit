/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:30:54 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/07 19:39:13 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# include "tetri_parser.h"

/*
** ========================================================================== **
*/

# define TETRI_CHAR_EMPTY		'.'
# define TETRI_CHAR_FULL		'#'

/*
** Check:
** 	4 bits
** 	every bit have at least 1 neighbor
*/
bool			tetri_check(uint16_t bits);

/*
** Align a tetri at the top/left
*/
uint16_t		tetri_align(uint16_t bits);

#endif
