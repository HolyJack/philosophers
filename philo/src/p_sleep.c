/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:34 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/26 18:27:27 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_data *data)
{
	printf("%lld %d is sleeping\n",
		current_time_ms() - data->pinfo->time_start, data->id + 1);
	if (data->times_must_eat == 0)
	{
		data->times_must_eat -= 1;
		pthread_mutex_lock(&data->m_pinfo);
		data->pinfo->meals_finished--;
		if (data->pinfo->meals_finished == 0)
			exit(0);
		pthread_mutex_unlock(&data->m_pinfo);
	}
	release_forks(data);
	p_usleep(data, data->pinfo->time_to_sleep);
}
