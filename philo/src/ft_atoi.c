/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:05:02 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/25 12:22:43 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	ft_atoi(const char *s)
{
	int		buf;
	int		sign;
	char	*str;

	sign = 1;
	str = (char *) s;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	buf = 0;
	while (ft_isdigit(*str) == 1)
	{
		buf *= 10;
		buf += (*str - '0');
		str++;
	}
	return (sign * buf);
}
