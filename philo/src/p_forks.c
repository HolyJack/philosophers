/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:22:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/28 17:14:24 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_data *data)
{
	pthread_mutex_lock(&data->grabing_forks);
	/*
	pthread_mutex_lock(&(data->forks[data->l]));
	printf("%lld %d has taken a fork\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	while (pthread_mutex_trylock(&(data->forks[data->r])))
	{
		usleep(100);
		checkdead(data);
	}
	printf("%lld %d has taken a fork\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	*/
	while (pthread_mutex_trylock(&(data->forks[data->l])))
	{
		usleep(200);
		checkdead(data);
	}
	printf("%lld %d has taken a fork\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	while (pthread_mutex_trylock(&(data->forks[data->r])))
	{
		usleep(200);
		checkdead(data);
	}
	printf("%lld %d has taken a fork\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	pthread_mutex_unlock(&data->grabing_forks);
}

void	release_forks(t_data *data)
{
	pthread_mutex_unlock(&(data->forks[data->l]));
	pthread_mutex_unlock(&(data->forks[data->r]));
}

pthread_mutex_t	*forks_init(int amount)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * (amount));
	i = -1;
	while (++i < amount)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}
