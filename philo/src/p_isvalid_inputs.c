/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_isvalid_inputs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:15:45 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:45:08 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	is_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int	p_isvalid_inputs(int argc, char **argv)
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
