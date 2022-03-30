/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:02:01 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 21:28:33 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*checkdead(void *ptr_philo)
{	
	t_philo		*philo;
	t_info		*info;

	philo = (t_philo *) ptr_philo;
	while (philo->times_must_eat)
	{
		usleep(1000);
		if (!philo->times_must_eat)
			return (NULL);
		else
		{
			pthread_mutex_lock(&philo->time_last_meal_lock);
			if (current_time_ms() - philo->time_last_meal >= philo->info->time_to_die)
			{
				pthread_mutex_lock(&philo->info->printlock);
				printf("%lld %d died\n",
					current_time_ms() - philo->info->time_start, philo->id);
				info = philo->info;
				free_all_philos(info->philos, info->number_of_philosophers);
				free_info(info);
				exit(0);
		}
		pthread_mutex_unlock(&philo->time_last_meal_lock);
		}
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->time_last_meal_lock);
	philo->time_last_meal = current_time_ms();
	pthread_mutex_unlock(&philo->time_last_meal_lock);
	printstatus(philo, "is eating");
	if (philo->times_must_eat > 0)
		philo->times_must_eat--;
	philo_usleep(philo->info->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	printstatus(philo, "is sleeping");
	release_forks(philo);
	philo_usleep(philo->info->time_to_sleep);
}

void	philo_think(t_philo	*philo)
{
	printstatus(philo, "is thinking");
	usleep(500);
}

void	*philosopher(void *ptr_philo)
{
	t_philo			*philo;
	pthread_t		deatstatus;

	philo = (t_philo *) ptr_philo;
	pthread_mutex_init(&philo->time_last_meal_lock, NULL);
	pthread_mutex_lock(&philo->time_last_meal_lock);
	philo->time_last_meal = current_time_ms();
	pthread_mutex_unlock(&philo->time_last_meal_lock);
	pthread_create(&deatstatus, NULL, checkdead, (void *) philo);
	pthread_detach(deatstatus);
	philo_usleep(philo->info->time_to_eat * (philo->id & 1) - 10);
	while (philo->times_must_eat)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	free_philo(philo);
	return (NULL);
}