/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejafer <ejafer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:30:33 by ejafer            #+#    #+#             */
/*   Updated: 2022/03/29 18:46:45 by ejafer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_eat(t_data *data)
{
	p_grab_forks(data);
	pthread_mutex_lock(&data->time_last_meal_lock);
	data->time_last_meal = p_current_time_ms();
	pthread_mutex_unlock(&data->time_last_meal_lock);
	p_printstatus(data,
		data->time_last_meal - data->pinfo->time_start,
		data->id + 1, "is eating");
	if (data->times_must_eat > 0)
		data->times_must_eat--;
	p_usleep(data->pinfo->time_to_eat);
}
