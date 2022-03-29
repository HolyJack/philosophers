/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_forks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:22:51 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:44:58 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_free_forks(pthread_mutex_t *forks, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		pthread_mutex_destroy(forks + i);
}

void	p_grab_forks(t_data *data)
{
	pthread_mutex_lock(&data->locks->forkslock);
	pthread_mutex_lock(&data->forks[data->left]);
	pthread_mutex_lock(&data->forks[data->right]);
	pthread_mutex_unlock(&data->locks->forkslock);
	p_printstatus(data,
		p_current_time_ms() - data->pinfo->time_start,
		data->id + 1, "has taken a fork");
	p_printstatus(data,
		p_current_time_ms() - data->pinfo->time_start,
		data->id + 1, "has taken a fork");
}

void	p_release_forks(t_data *data)
{
	pthread_mutex_unlock(&(data->forks[data->left]));
	pthread_mutex_unlock(&(data->forks[data->right]));
}

pthread_mutex_t	*p_init_forks(int amount)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * (amount));
	i = -1;
	while (++i < amount)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}
