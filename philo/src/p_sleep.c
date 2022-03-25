/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 00:46:37 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_data *data)
{
	printf("%lld %d is sleeping\n",
		current_time_ms(), data->id + 1);
	usleep(data->pinfo->time_to_sleep * 1000);
	if (data->pinfo->number_of_times_each_philosopher_must_eat > 0)
	{
		pthread_mutex_lock(&data->meal);
		data->pinfo->number_of_times_each_philosopher_must_eat--;
		pthread_mutex_unlock(&data->meal);
	}
}
