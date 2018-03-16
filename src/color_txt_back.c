/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_txt_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:56:41 by jlange            #+#    #+#             */
/*   Updated: 2017/02/21 16:28:42 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void						ft_background_color(char c)
{
	if (c == 'a' || c == 'A')
		ft_putstr(BACK_BLACK);
	else if (c == 'b' || c == 'B')
		ft_putstr(BACK_RED);
	else if (c == 'c' || c == 'C')
		ft_putstr(BACK_GREEN);
	else if (c == 'd' || c == 'D')
		ft_putstr(BACK_YELLOW);
	else if (c == 'e' || c == 'E')
		ft_putstr(BACK_BLUE);
	else if (c == 'f' || c == 'F')
		ft_putstr(BACK_MAGENTA);
	else if (c == 'g' || c == 'G')
		ft_putstr(BACK_CYAN);
	else if (c == 'h' || c == 'H')
		ft_putstr(BACK_GREY);
}

static inline void			ft_text_color2(char c)
{
	if (c == 'A')
		ft_putstr(D_GREY);
	else if (c == 'B')
		ft_putstr(B_RED);
	else if (c == 'C')
		ft_putstr(B_GREEN);
	else if (c == 'D')
		ft_putstr(YELLOW);
	else if (c == 'E')
		ft_putstr(B_BLUE);
	else if (c == 'F')
		ft_putstr(B_MAGENTA);
	else if (c == 'G')
		ft_putstr(B_CYAN);
	else if (c == 'H')
		ft_putstr(WHITE);
}

void						ft_text_color(char c)
{
	if (c == 'a')
		ft_putstr(BLACK);
	else if (c == 'b')
		ft_putstr(RED);
	else if (c == 'c')
		ft_putstr(GREEN);
	else if (c == 'd')
		ft_putstr(BROWN);
	else if (c == 'e')
		ft_putstr(BLUE);
	else if (c == 'f')
		ft_putstr(MAGENTA);
	else if (c == 'g')
		ft_putstr(CYAN);
	else if (c == 'h')
		ft_putstr(GREY);
	else
		ft_text_color2(c);
}
