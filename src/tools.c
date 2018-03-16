/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:26:04 by jlange            #+#    #+#             */
/*   Updated: 2017/02/22 10:24:24 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_add_prefix(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	if (ret == NULL)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	if (s1[0] != '/' || s1[1] != '\0')
	{
		ret[i] = '/';
		++i;
	}
	while (s2[++j])
	{
		ret[i] = s2[j];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	ft_error(char *name)
{
	int i;

	i = -1;
	write(1, "ft_ls: ", 7);
	if (errno == 13)
	{
		while (name[++i])
			;
		while (name[--i] != '/' && i > -1)
			;
		write(2, &name[i + 1], ft_strlen(&name[i + 1]));
	}
	else
		write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
}

void	ft_charcat(char **s1, const char s2)
{
	while (**s1)
		(*s1)++;
	**s1 = s2;
	(*s1)++;
	**s1 = '\0';
}

void	ft_strcat_ls(char **s1, const char *s2)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (s2[i])
		{
			**s1 = s2[i];
			i++;
			(*s1)++;
		}
	}
	**s1 = '\0';
}

void	add_padding(char **s1, int nb)
{
	int i;

	i = 0;
	while (**s1)
		(*s1)++;
	if (**s1 == '\0')
	{
		while (nb > 0)
		{
			**s1 = ' ';
			i++;
			(*s1)++;
			nb--;
		}
	}
	**s1 = '\0';
}
