/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_txt_back_l.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:56:41 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 16:23:43 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void						ft_background_color_l(char c, char **buf)
{
	if (c == 'a' || c == 'A')
		ft_strcat_ls(buf, BACK_BLACK);
	else if (c == 'b' || c == 'B')
		ft_strcat_ls(buf, BACK_RED);
	else if (c == 'c' || c == 'C')
		ft_strcat_ls(buf, BACK_GREEN);
	else if (c == 'd' || c == 'D')
		ft_strcat_ls(buf, BACK_YELLOW);
	else if (c == 'e' || c == 'E')
		ft_strcat_ls(buf, BACK_BLUE);
	else if (c == 'f' || c == 'F')
		ft_strcat_ls(buf, BACK_MAGENTA);
	else if (c == 'g' || c == 'G')
		ft_strcat_ls(buf, BACK_CYAN);
	else if (c == 'h' || c == 'H')
		ft_strcat_ls(buf, BACK_GREY);
}

static inline void			ft_text_color2(char c, char **buf)
{
	if (c == 'A')
		ft_strcat_ls(buf, D_GREY);
	else if (c == 'B')
		ft_strcat_ls(buf, B_RED);
	else if (c == 'C')
		ft_strcat_ls(buf, B_GREEN);
	else if (c == 'D')
		ft_strcat_ls(buf, YELLOW);
	else if (c == 'E')
		ft_strcat_ls(buf, B_BLUE);
	else if (c == 'F')
		ft_strcat_ls(buf, B_MAGENTA);
	else if (c == 'G')
		ft_strcat_ls(buf, B_CYAN);
	else if (c == 'H')
		ft_strcat_ls(buf, WHITE);
}

void						ft_text_color_l(char c, char **buf)
{
	if (c == 'a')
		ft_strcat_ls(buf, BLACK);
	else if (c == 'b')
		ft_strcat_ls(buf, RED);
	else if (c == 'c')
		ft_strcat_ls(buf, GREEN);
	else if (c == 'd')
		ft_strcat_ls(buf, BROWN);
	else if (c == 'e')
		ft_strcat_ls(buf, BLUE);
	else if (c == 'f')
		ft_strcat_ls(buf, MAGENTA);
	else if (c == 'g')
		ft_strcat_ls(buf, CYAN);
	else if (c == 'h')
		ft_strcat_ls(buf, GREY);
	else
		ft_text_color2(c, buf);
}
