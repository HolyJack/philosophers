/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:18:24 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 01:03:02 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "ft_utils.h"

t_info	*init_info(char **argv)
{
	t_info			*info;

	info = malloc(sizeof(t_info) * 1);
	info->number_of_philosophers = ft_atoi(argv[0]);
	info->id = info->number_of_philosophers;
	info->time_to_die = ft_atoi(argv[1]);
	info->time_to_eat = ft_atoi(argv[2]);
	info->time_to_sleep = ft_atoi(argv[3]);
	info->time_start = current_time_ms();
	sem_unlink(FORKS);
	sem_unlink(LOCK_PRINT);
	sem_unlink(LOCK_FORKS);
	sem_unlink(LOCK_EAT);
	info->forks = sem_open(FORKS, O_CREAT | O_EXCL, 0644,
			info->number_of_philosophers);
	info->lock_forks = sem_open(LOCK_FORKS, O_CREAT | O_EXCL, 0644, 1);
	info->lock_print = sem_open(LOCK_PRINT, O_CREAT | O_EXCL, 0644, 1);
	info->lock_eat = sem_open(LOCK_EAT, O_CREAT | O_EXCL, 0644, 1);
	if (argv[4])
		info->times_must_eat = ft_atoi(argv[4]);
	else
		info->times_must_eat = -1;
	return (info);
}
