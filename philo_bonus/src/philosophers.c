/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:44:04 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/31 01:07:25 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*checkdead(void *info_ptr)
{
	t_info	*info;
	int		val;

	info = (t_info *) info_ptr;
	val = 1;
	while (val > 0)
	{
		sem_getvalue(info->all_finished, &val);
		if (val <= 0)
			break ;
		usleep(1000);
		sem_wait(&info->lock_eat);
		if (info->time_to_die <= current_time_ms() - info->time_last_meal)
		{
			sem_wait(info->lock_print);
			printf("%lld %d %s\n",
				current_time_ms() - info->time_start, info->id, "died");
			free_info(info);
			exit(1);
		}
		sem_post(&info->lock_eat);
		sem_getvalue(info->all_finished, &val);
	}
	return (NULL);
}

void	philo_eat(t_info *info)
{
	sem_wait(info->lock_forks);
	sem_wait(info->forks);
	print_status(info, "has taken a fork");
	sem_wait(info->forks);
	print_status(info, "has taken a fork");
	sem_post(info->lock_forks);
	sem_wait(&info->lock_eat);
	info->time_last_meal = current_time_ms();
	sem_post(&info->lock_eat);
	print_status(info, "is eating");
	philo_usleep(info->time_to_eat);
	if (info->times_must_eat > 0)
	{
		info->times_must_eat--;
		if (!info->times_must_eat)
			sem_wait(info->all_finished);
	}
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
	print_status(info, "is thinking");
}

void	philosopher(t_info *info)
{
	int	val;

	val = 1;
	sem_init(&info->lock_eat, 0, 1);
	sem_wait(&info->lock_eat);
	info->time_last_meal = current_time_ms();
	sem_post(&info->lock_eat);
	pthread_create(&info->deathstatus, NULL, checkdead, (void *) info);
	pthread_detach(info->deathstatus);
	philo_usleep(info->time_to_eat * ((info->id - 1) & 1) - 5);
	while (val > 0)
	{
		philo_eat(info);
		sem_getvalue(info->all_finished, &val);
		if (val <= 0)
			break ;
		philo_sleep(info);
		philo_think(info);
		sem_getvalue(info->all_finished, &val);
	}
	free_info(info);
	exit (0);
}
