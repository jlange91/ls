/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:14:40 by jlange            #+#    #+#             */
/*   Updated: 2017/03/10 03:53:40 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (res *= -1);
	return (res);
}
