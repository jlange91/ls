/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:49:32 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 17:55:49 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_check_file(char *name, int flags)
{
	int i;

	i = 0;
	if ((flags & 0b10000000000))
	{
		if ((flags & 0b00100))
			return (name[0] != '.' || (flags & 0b00100)) ? 1 : 0;
		if (name[0] != '.')
			return (1);
		else if (name[1] == '.' || name[1] == '\0')
			return (0);
		else
			return (1);
	}
	else
		return (name[0] != '.' || (flags & 0b00100)) ? 1 : 0;
}
