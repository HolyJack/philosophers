/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:18:24 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 12:54:12 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "ft_utils.h"

t_pinfo	*pinfo_init(char **argv)
{
	t_pinfo			*pinfo;

	pinfo = malloc(sizeof(t_pinfo) * 1);
	pinfo->number_of_philosophers = ft_atoi(argv[0]);
	pinfo->time_to_die = ft_atoi(argv[1]);
	pinfo->time_to_eat = ft_atoi(argv[2]);
	pinfo->time_to_sleep = ft_atoi(argv[3]);
	if (argv[4])
		pinfo->times_each_philosopher_must_eat = ft_atoi(argv[4]);
	else
		pinfo->times_each_philosopher_must_eat = -1;
	return (pinfo);
}
