/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccompera <ccompera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:16:13 by ccompera          #+#    #+#             */
/*   Updated: 2016/11/07 19:48:26 by ccompera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_PARSER_H
# define TETRI_PARSER_H

# include "ft/ft_in.h"
# include "ft/ft_vector.h"

# include "tetriminos.h"

/*
** ========================================================================== **
*/

/*
** Parse tetris until EOF
** A valid tetri is a 4*4 square made with '.' and '#' char
** 	'.' mean empty space
** 	'#' block of tetri
** Tetris are separated by an empty line
** Empty file is an error
** Return true on success, false on error
*/
bool			parse_tetris(t_in *in, t_vector *dst);

#endif
