/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_one_l2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:55:33 by jlange            #+#    #+#             */
/*   Updated: 2017/02/17 18:55:48 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_display_l(t_file *file, t_len len, int flags)
{
	int i;

	i = 0;
	while (file[i].d_name != NULL)
	{
		ft_print_lflag(&file[i], len, flags);
		i++;
	}
}
