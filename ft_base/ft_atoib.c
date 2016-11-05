/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:12:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/11/27 23:45:59 by juloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/libft.h"

int				ft_atoib(const char *str, int *nb)
{
	int				sign;
	int				i;

	sign = 1;
	*nb = 0;
	i = 0;
	while (IS(str[i], IS_WHITE))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		*nb = *nb * 10 + (str[i++] - '0');
	*nb *= sign;
	return (i);
}
