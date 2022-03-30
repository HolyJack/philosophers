/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:38:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/30 19:40:04 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	die(long long ms, t_data *data)
{
	pthread_mutex_lock(&data->locks->printlock);
	printf("%lld %d died\n", ms, data->id + 1);
	free_forks(data->forks, data->pinfo->number_of_philosophers);
	free_locks(data->locks);
	free_info(data->pinfo);
	p_free_data(data);
	exit(0);
}

void	*checkdead(void *ptr_data)
{	
	t_data		*data;
	long long	ms;

	data = (t_data *) ptr_data;
	while (data->times_must_eat)
	{
		usleep(1000);
		pthread_mutex_lock(&data->time_last_meal_lock);
		ms = p_current_time_ms();
		if (ms - data->time_last_meal >= data->pinfo->time_to_die)
			p_die(ms - data->pinfo->time_start, data);
		pthread_mutex_unlock(&data->time_last_meal_lock);
	}
	return (NULL);
}
