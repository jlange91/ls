/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:01:21 by jlange            #+#    #+#             */
/*   Updated: 2017/03/10 05:34:20 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_return(int i, int ret, char **line, char *str)
{
	if (i > 0 && ret == 0)
	{
		str[i] = '\0';
		*line = ft_strdup(str);
		return (1);
	}
	if (ret < 0)
		return (-1);
	else if (!*line)
		return (0);
	return (ret);
}

static int		ft_fill_line(char tmp, char *str, char **line, int i)
{
	if (tmp == '\n' || tmp == '\0')
	{
		str[i] = '\0';
		*line = ft_strdup(str);
		return (1);
	}
	else
		return (0);
}

int				get_next_line(const int fd, char **line)
{
	char	str[65536];
	char	tmp;
	int		ret;
	int		i;

	i = 0;
	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	while ((ret = read(fd, &tmp, 1)) > 0)
	{
		if (ft_fill_line(tmp, str, line, i))
			return (1);
		else
			str[i] = tmp;
		i++;
		if (i == 4095)
		{
			str[i] = '\0';
			*line = ft_strdup(str);
			return (2);
		}
	}
	return (ft_return(i, ret, line, str));
}
