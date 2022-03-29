/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:38:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 14:09:49 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*p_checkdead(void *ptr_data)
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
