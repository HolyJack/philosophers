/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:15:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 20:16:03 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	isvalid_inputs(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc != 4 && argc != 5)
		return (0);
	while (++i < argc)
		if (!is_number(argv[i]))
			return (0);
	return (1);
}

int	ft_atoi(const char *s)
{
	long long		buf;
	long long		sign;
	char			*str;

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
