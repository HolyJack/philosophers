/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:44:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 00:55:32 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*checkdead(void *info_ptr)
{
	t_info	*info;

	info = (t_info *) info_ptr;
	while (1)
	{
		usleep(1000);
		if (!info->times_must_eat)
			return (NULL);
		else
		{
			sem_wait(info->lock_eat);
			if (info->time_to_die <= current_time_ms() - info->time_last_meal)
			{
				sem_wait(info->lock_print);
				printf("%lld %d %s\n",
					current_time_ms() - info->time_start, info->id, "died");
				free_info(info);
				exit(0);
			}
			sem_post(info->lock_eat);
		}
	}
}

void	philo_eat(t_info *info)
{
	sem_wait(info->lock_forks);
	sem_wait(info->forks);
	print_status(info, "has taken a fork");
	sem_wait(info->forks);
	print_status(info, "has taken a fork");
	sem_post(info->lock_forks);
	sem_wait(info->lock_eat);
	info->time_last_meal = current_time_ms();
	sem_post(info->lock_eat);
	print_status(info, "is eating");
	philo_usleep(info->time_to_eat);
	if (info->times_must_eat > 0)
		info->times_must_eat--;
}

void	philo_sleep(t_info *info)
{
	print_status(info, "is sleeping");
	sem_post(info->forks);
	sem_post(info->forks);
	philo_usleep(info->time_to_sleep);
}

void	philo_think(t_info *info)
{
	printf("%lld %d is thinking\n",
		current_time_ms() - info->time_start, info->id);
}

void	philosopher(t_info *info)
{
	info->time_last_meal = current_time_ms();
	pthread_create(&info->deathstatus, NULL, checkdead, (void *) info);
	pthread_detach(info->deathstatus);
	philo_usleep(info->time_to_eat * info->id % 2);
	while (info->times_must_eat)
	{
		philo_eat(info);
		philo_sleep(info);
		philo_think(info);
	}
	free_info(info);
}
