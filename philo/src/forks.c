/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:22:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 20:26:41 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forkslock);
	pthread_mutex_lock(&philo->info->forks[philo->left]);
	pthread_mutex_lock(&philo->info->forks[philo->right]);
	pthread_mutex_unlock(&philo->info->forkslock);
	printstatus(philo, "has taken a fork");
	printstatus(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->info->forks[philo->left]));
	pthread_mutex_unlock(&(philo->info->forks[philo->right]));
}

pthread_mutex_t	*init_forks(int amount)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * (amount));
	i = -1;
	while (++i < amount)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

void	free_forks(pthread_mutex_t *forks, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
}
