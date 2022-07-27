/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:39:28 by sshana            #+#    #+#             */
/*   Updated: 2021/11/11 19:40:34 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_tab(const char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

long int	ft_ato(const char *str, int sign, int i)
{
	long int	res;
	int			x;

	res = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (48 <= str[i] && str[i] <= 57)
		{
			res = res * 10 + str[i] - '0';
			i++;
			x++;
		}
		else
			return (sign * res);
	}
	if (x > 17 && sign == 1)
		return (-1);
	if (x > 17 && sign == -1)
		return (0);
	return ((long int)(sign * res));
}

long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	i = ft_tab(str, i);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	return (ft_ato(str, sign, i));
}
