/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juloo <juloo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 00:01:49 by juloo             #+#    #+#             */
/*   Updated: 2015/12/10 19:14:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

t_is			g_is_table[(unsigned char)-1] = {
	0,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL | IS_WHITE,
	IS_CNTRL | IS_WHITE,
	IS_CNTRL | IS_WHITE,
	IS_CNTRL | IS_WHITE,
	IS_CNTRL | IS_WHITE,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_CNTRL,
	IS_BLANK,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_DIGIT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_UPPER | IS_XALPHA,
	IS_UPPER | IS_XALPHA,
	IS_UPPER | IS_XALPHA,
	IS_UPPER | IS_XALPHA,
	IS_UPPER | IS_XALPHA,
	IS_UPPER | IS_XALPHA,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_UPPER,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT | IS_UNDERSCORE,
	IS_PUNCT,
	IS_LOWER | IS_XALPHA,
	IS_LOWER | IS_XALPHA,
	IS_LOWER | IS_XALPHA,
	IS_LOWER | IS_XALPHA,
	IS_LOWER | IS_XALPHA,
	IS_LOWER | IS_XALPHA,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_LOWER,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_PUNCT,
	IS_CNTRL,
	0
};

bool			ft_is(char c, t_is mask)
{
	if (IS(c, mask))
		return (true);
	return (false);
}