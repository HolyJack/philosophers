/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:18:24 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 21:20:34 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "ft_utils.h"

t_info	*init_info(char **argv)
{
	t_info			*info;

	info = malloc(sizeof(t_info) * 1);
	info->number_of_philosophers = ft_atoi(argv[0]);
	info->time_to_die = ft_atoi(argv[1]);
	info->time_to_eat = ft_atoi(argv[2]);
	info->time_to_sleep = ft_atoi(argv[3]);
	info->forks = init_forks(info->number_of_philosophers);
	info->philos = malloc(sizeof(t_philo *) * info->number_of_philosophers);
	pthread_mutex_init(&info->printlock, NULL);
	pthread_mutex_init(&info->forkslock, NULL);
	if (argv[4])
		info->times_must_eat = ft_atoi(argv[4]);
	else
		info->times_must_eat = -1;
	return (info);
}

void	free_info(t_info *info)
{
	pthread_mutex_destroy(&info->forkslock);
	pthread_mutex_destroy(&info->printlock);
	free_forks(info->forks, info->number_of_philosophers);
	free(info->threads);
	free(info->philos);
	free(info);
}
