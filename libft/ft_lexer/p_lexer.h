/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_lexer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 20:36:57 by juloo             #+#    #+#             */
/*   Updated: 2016/09/09 00:01:26 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_LEXER_BUILD_H
# define P_LEXER_BUILD_H

# include "ft/lexer.h"

/*
** ========================================================================== **
** Build
*/

t_tokenmap	*lexer_build_state(t_lexer_def const *def);

#endif