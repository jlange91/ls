/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 22:44:26 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 19:03:35 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		wchar_four(wchar_t data)
{
	char c;

	c = (((data & 0x1c0000) >> 18) + 0xF0);
	write(1, &c, 1);
	c = (((data & 0x03F000) >> 12) + 0x80);
	write(1, &c, 1);
	c = (((data & 0x0Fc0) >> 6) + 0x80);
	write(1, &c, 1);
	c = ((data & 0x003F) + 0x80);
	write(1, &c, 1);
}

static void		wchar_three(wchar_t data)
{
	char c;

	c = (((data & 0xF000) >> 12) + 0xE0);
	write(1, &c, 1);
	c = (((data & 0x0Fc0) >> 6) + 0x80);
	write(1, &c, 1);
	c = ((data & 0x003F) + 0x80);
	write(1, &c, 1);
}

static void		wchar_two(wchar_t data)
{
	char c;

	c = (((data & 0x07c0) >> 6) + 0xc0);
	write(1, &c, 1);
	c = ((data & 0x003F) + 0x80);
	write(1, &c, 1);
}

void			ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		write(1, &c, 1);
	else if (c <= 0x7FF)
		wchar_two(c);
	else if (c <= 0xFFFF)
		wchar_three(c);
	else if (c <= 0x1FFFFF)
		wchar_four(c);
}
